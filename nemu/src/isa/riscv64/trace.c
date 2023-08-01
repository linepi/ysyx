#include <sdb.h>
#include <reg.h>
#include "include/decode.h"
#include "syscall.h"

int nr_functbl = 0;
struct func_t *cur_func = NULL;
struct func_stack_t func_stack_bottom = {};
struct func_stack_t *func_stack_top;
struct pc_road pc_road = {};

extern bool g_print_step;

static char *etrace_reason[] = {
  [SYS_exit]             "SYS_exit",
  [SYS_yield]            "SYS_yield",        
  [SYS_open]             "SYS_open",        
  [SYS_read]             "SYS_read",        
  [SYS_write]            "SYS_write",        
  [SYS_kill]             "SYS_kill",        
  [SYS_getpid]           "SYS_getpid",        
  [SYS_close]            "SYS_close",        
  [SYS_lseek]            "SYS_lseek",        
  [SYS_brk]              "SYS_brk",
  [SYS_fstat]            "SYS_fstat",        
  [SYS_time]             "SYS_time",        
  [SYS_signal]           "SYS_signal",        
  [SYS_execve]           "SYS_execve",        
  [SYS_fork]             "SYS_fork",        
  [SYS_link]             "SYS_link",        
  [SYS_unlink]           "SYS_unlink",        
  [SYS_wait]             "SYS_wait",        
  [SYS_times]            "SYS_times",        
  [SYS_gettimeofday]     "SYS_gettimeofday" 
};

void etrace(word_t reason, vaddr_t where) {
  Assert(reason >= 0 && reason <= sizeof(etrace_reason)/sizeof(etrace_reason[0]), "Unknown etrace reason\n");
  printf(ANSI_FMT("[etrace]: %s at 0x%08lx\n", ANSI_FG_BLUE), etrace_reason[reason], where);
}

void build_functbl(struct elfinfo_t *elfinfo, bool user) {
  FILE *elf_fp;
  if (user) elf_fp = user_elf_fp;
  else elf_fp = image_elf_fp;
  assert(elf_fp != NULL);

  for (size_t i = 0; i < elfinfo->nr_sym; i++) {
    if (ELF64_ST_TYPE(elfinfo->Sym[i].st_info) == STT_FUNC) {
      int j = 0;
      char c;
      functbl[nr_functbl].addr = elfinfo->Sym[i].st_value;
      functbl[nr_functbl].size = elfinfo->Sym[i].st_size;
      functbl[nr_functbl].user = user;
      fseek(elf_fp, elfinfo->Shdr_strtab->sh_offset + elfinfo->Sym[i].st_name, SEEK_SET); 
      if (user) {
        functbl[nr_functbl].name[j++] = '$';
      } else {
        functbl[nr_functbl].name[j++] = '#';
      }
      while ((c = fgetc(elf_fp)) != '\0') {
        functbl[nr_functbl].name[j++] = c;
      }
      functbl[nr_functbl].name[j] = '\0';
      // 如果是这个函数，则手动给出函数大小
      if (strcmp(functbl[nr_functbl].name, "#__am_asm_trap") == 0) {
        functbl[nr_functbl].size = 316;
      }
      // init func stack
      if (strcmp(functbl[nr_functbl].name, "#_start") == 0 || strcmp(functbl[nr_functbl].name, "$_start") == 0) {
        if (functbl[nr_functbl].name[0] == '#')
          functbl[nr_functbl].size = 16;
        else 
          functbl[nr_functbl].size = 8;
        func_stack_bottom.func = &functbl[nr_functbl];
        func_stack_bottom.pre = NULL;
        func_stack_bottom.next = (struct func_stack_t *)wmalloc(sizeof(struct func_stack_t));
        assert(func_stack_bottom.next);
        func_stack_bottom.next->pre = &func_stack_bottom;
        func_stack_bottom.next->next = NULL;
        func_stack_bottom.next->func = NULL;
        func_stack_top = func_stack_bottom.next;
        cur_func = func_stack_bottom.func;
      }
      functbl[nr_functbl].cnt = 0;
      nr_functbl++;
    }
  }
}

// jalr inst: c5c08017, with actual ra = 0x8300048c, think ra = 83000494
// 0b110001011100 00001 000 00001 1100111
// think jump to 0x830000f0
// actually jump to 0x830000e8

static bool unknown_address(vaddr_t addr) {
  for (int i = 0; i < nr_functbl; i++) {
    if (addr >= functbl[i].addr && addr < functbl[i].addr + functbl[i].size) 
      return false;
  }
  return true;
}

void ftrace() {
  // static bool has_unknown = false;

  vaddr_t tmp = last_cpu.pc;
  uint32_t i = inst_fetch_add(&tmp, 4);
  // ret指令并不一定是返回到上一个函数栈帧，
  // 而有可能返回到之前很远的一个栈帧，因为某些函数是没有ret指令的，ret指令在其子函数中
  if (i == 0x00008067 || i == 0b00110000001000000000000001110011) { // mean ret or mret instuction
    if (g_print_step) 
      printf(ANSI_FMT("ret from %s\n", ANSI_FG_BLUE), func_stack_top->pre->func->name);

    word_t ret_addr;
    if (i == 0x00008067) ret_addr = last_cpu.gpr[1];
    else ret_addr = last_cpu.mepc;

    // 如果要返回的位置不属于任何已知函数，则不更新函数栈
    if (unknown_address(ret_addr)) return;
    // 前向寻找，如果返回地址ra在cur_func的地址范围内，则返回到cur_func栈帧中
    do {
      func_stack_top = func_stack_top->pre;
      assert(func_stack_top);
    } while ( // 如果不在此函数里面，继续循环
      ret_addr < func_stack_top->func->addr ||
      ret_addr >= func_stack_top->func->addr + func_stack_top->func->size
    );
    cur_func = func_stack_top->func;
    func_stack_top = func_stack_top->next;

    // has_unknown = true;
    return;
  }

  vaddr_t jump_to = 0;
  word_t _imm = 0;
  word_t *imm = &_imm;
  word_t src1 = 0;
  if ((i & 0b1111111) == 0b1101111) { // jal
    immUJ();
    jump_to = *imm + last_cpu.pc;
  }
  else if ((i & 0b111000001111111) == 0b000000001100111) { // jalr
    src1 = last_cpu.gpr[BITS(i, 19, 15)];
    immI();
    jump_to = *imm + src1;
  }
  else if (i == 0b00000000000000000000000001110011) { // ecall
    jump_to = last_cpu.mtvec;
  }
  else return;

  for (int i = 0; i < nr_functbl; i++) {
    if (functbl[i].addr == jump_to) {
      functbl[i].cnt++;
      if (g_print_step) 
        printf(ANSI_FMT("call %s\n", ANSI_FG_BLUE), functbl[i].name);
      func_stack_top->func = &functbl[i];
      cur_func = &functbl[i];
      if (!func_stack_top->next) {
        func_stack_top->next = (struct func_stack_t *)wmalloc(sizeof(struct func_stack_t));
        assert(func_stack_top->next != NULL);
        func_stack_top->next->pre = func_stack_top;
        func_stack_top->next->next = NULL;
        func_stack_top->next->func = NULL;
      }
      func_stack_top = func_stack_top->next;
      break;
    }
  }
  // 未找到相应函数（假设jal, jalr, ecall都是前往一个函数)
  // if (i == nr_functbl) {
  //   func_t unknown_ 
  //   has_unknown = true;
  // }
}

// dump next n static instruction from addr
void _frame_dump(vaddr_t addr, int n) {
  if (!in_pmem(addr)) return;

  char disa[128];
  for (int i = 0; i < n; i++) {
    if (addr != cpu.pc)
      printf("    ");
    else 
      printf(ANSI_FMT("=>  ", ANSI_FG_GREEN));
    // 这里保存pc的原因是，inst_fetch_add会使pc增加，以至于反汇编得不到所执行指令的正确相对地址
    vaddr_t addr_bak = addr;
    uint32_t inst = inst_fetch_add(&addr, 4);
    IFDEF(CONFIG_ITRACE, disassemble(disa, 128, addr_bak, (uint8_t *)&inst, 4));

    printf("0x%08lx: %s", addr_bak, disa); 
    for (int i = 0; i < 30 - strlen(disa); i++) putchar(' ');
    uint8_t *p_inst = (uint8_t *)&inst;
    for (int i = 3; i >= 0; i --) {
      printf(" %02x", p_inst[i]);
    }
    printf("\n");
  }
}

// dump n static instruction before and after pc
void frame_dump(int n) {
  if (functbl) 
    printf(ANSI_FMT("In function %s(), frame dump:\n", ANSI_FG_GREEN), unknown_address(cpu.pc) ? "unknown" : cur_func->name);
  vaddr_t addr = MAX(cpu.pc - 4 * (n/2), CONFIG_MBASE);
  _frame_dump(addr, n);
}

// trace the pc
void pc_trace() {
  pc_road.arr[pc_road.cur] = last_cpu.pc;
  pc_road.cur = (pc_road.cur + 1) % NR_PC_ROAD;
}

// dump the latest n instructions that are executed
void pc_trace_dump(int n) {
  if (functbl) 
    printf(ANSI_FMT("In function %s(), pc trace dump:\n", ANSI_FG_RED), cur_func->name);
  else
    printf(ANSI_FMT("pc trace dump:\n", ANSI_FG_RED));
  char disa[128];
  for (int i = (pc_road.cur + NR_PC_ROAD - n) % NR_PC_ROAD; n--;i = (i + 1) % NR_PC_ROAD) {
    vaddr_t pc = pc_road.arr[i];
    if (pc != 0) {
      vaddr_t saved_pc = pc;
      uint32_t inst = inst_fetch_add(&pc, 4);
      IFDEF(CONFIG_ITRACE, disassemble(disa, 128, saved_pc, (uint8_t *)&inst, 4));
      printf("    0x%08lx: %s", saved_pc, disa); 
      for (int i = 0; i < 30 - strlen(disa); i++) putchar(' ');
      uint8_t *p_inst = (uint8_t *)&inst;
      for (int i = 3; i >= 0; i --) {
        printf(" %02x", p_inst[i]);
      }
      printf("\n");
    } 
  }
  _frame_dump(cpu.pc, 10);
}

int get_func_stack_len() {
  int i = 0;
  for (struct func_stack_t *p = func_stack_top->pre; p; p = p->pre, i++);
  return i + 1;
}

void backtrace() {
  if (!functbl) {
    Error("No functbl specified\n");
    return;
  }
  printf(ANSI_FMT("Backtrace:\n", ANSI_FG_GREEN));
  int i = 0;
  for (struct func_stack_t *p = func_stack_top->pre; p; p = p->pre, i++) {
    printf("#%d: %s() -- 0x%08lx\n", i, p->func->name, p->func->addr);
  }
}

void func_list() {
  if (!functbl) {
    Error("No functbl specified");
    return;
  }
  printf(ANSI_FMT("Address range                  Name\n", ANSI_FG_BLUE));
  for (int i = 0; i < nr_functbl; i++) {
    printf("[0x%08lx, 0x%08lx]       %s\n", functbl[i].addr, functbl[i].addr + functbl[i].size, functbl[i].name);
  }
}

void clear_funcstack() {
  
}