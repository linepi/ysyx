#include <sdb.h>
#include <reg.h>

struct func_t *functbl = NULL;
struct func_t *cur_func = NULL;
struct func_stack_t func_stack_bottom = {};
struct func_stack_t *func_stack_top;

extern bool g_print_step;

void make_functbl() {
  int func_cnt = 0;
  int idx = 0;
  for (size_t i = 0; i < elfinfo.nr_sym; i++) {
    if (ELF64_ST_TYPE(elfinfo.Sym[i].st_info) == STT_FUNC) func_cnt++;
  }
  functbl = (struct func_t*)wmalloc(sizeof(struct func_t) * (func_cnt + 1));
  assert(functbl != NULL);
  for (size_t i = 0; i < elfinfo.nr_sym; i++) {
    if (ELF64_ST_TYPE(elfinfo.Sym[i].st_info) == STT_FUNC) {
      int j = 0;
      char c;
      functbl[idx].addr = elfinfo.Sym[i].st_value;
      fseek(elf_fp, elfinfo.Shdr_strtab->sh_offset + elfinfo.Sym[i].st_name, SEEK_SET); 
      while ((c = fgetc(elf_fp)) != '\0') {
        functbl[idx].name[j++] = c;
      }
      functbl[idx].name[j] = '\0';
      // init func stack
      if (strcmp(functbl[idx].name, "_start") == 0) {
        func_stack_bottom.func = &functbl[idx];
        func_stack_bottom.pre = NULL;
        func_stack_bottom.next = (struct func_stack_t *)wmalloc(sizeof(struct func_stack_t));
        assert(func_stack_bottom.next);
        func_stack_bottom.next->pre = &func_stack_bottom;
        func_stack_bottom.next->next = NULL;
        func_stack_bottom.next->func = NULL;
        func_stack_top = func_stack_bottom.next;
        cur_func = func_stack_bottom.func;
      }
      functbl[idx].end = false;
      idx++;
    }
  }
  functbl[idx].end = true;
}

void ftrace(vaddr_t pc) {
  vaddr_t save_pc = pc;
  uint32_t i = inst_fetch_add(&pc, 4);
  if (i == 0x00008067) { // mean ret instuction
    if (g_print_step) printf(ANSI_FMT("ret from %s\n", ANSI_FG_BLUE), func_stack_top->func->name);
    func_stack_top = func_stack_top->pre;
    cur_func = func_stack_top->func;
    return;
  }

  vaddr_t jump_to = 0;
  word_t _imm = 0;
  word_t *imm = &_imm;
  if ((i & 0b1111111) == 0b1101111) { // jal
    immUJ();
    jump_to = *imm + save_pc;
  }
  else if ((i & 0b111000001111111) == 0b000000001100111) { // jalr
    word_t src1 = gpr(BITS(i, 19, 15));
    immI();
    jump_to = *imm + src1;
  }
  else return;

  for (int i = 0; !functbl[i].end; i++) {
    if (functbl[i].addr == jump_to) {
      if (g_print_step) printf(ANSI_FMT("call %s\n", ANSI_FG_BLUE), functbl[i].name);
      func_stack_top->func = &functbl[i];
      cur_func = func_stack_top->func;
      if (!func_stack_top->next) {
        func_stack_top->next = (struct func_stack_t *)wmalloc(sizeof(struct func_stack_t));
        func_stack_top->next->pre = func_stack_top;
        func_stack_top->next->next = NULL;
        func_stack_top->next->func = NULL;
        assert(func_stack_top->next != NULL);
      }
      func_stack_top = func_stack_top->next;
      break;
    }
  }
}

// just for riscv64
void frame_dump(vaddr_t pc, int n) {
  printf(ANSI_FMT("Frame %s(), with pc = 0x%016lx:\n", ANSI_FG_GREEN), cur_func->name, cur_func->addr);
  char disa[128];
  vaddr_t _pc = MAX(pc - 4 * (n/2), CONFIG_MBASE);
  for (int i = 0; i < n; i++) {
    if (_pc != pc)
      printf("    ");
    else 
      printf(ANSI_FMT("=>  ", ANSI_FG_GREEN));
    // 这里保存pc的原因是，inst_fetch_add会使pc增加，以至于反汇编得不到所执行指令的正确相对地址
    vaddr_t saved_pc = _pc;
    uint32_t inst = inst_fetch_add(&_pc, 4);
    IFDEF(CONFIG_ITRACE, disassemble(disa, 128, saved_pc, (uint8_t *)&inst, 4));

    printf("0x%08lx: %s", saved_pc, disa); 
    for (int i = 0; i < 30 - strlen(disa); i++) putchar(' ');
    uint8_t *p_inst = (uint8_t *)&inst;
    for (int i = 3; i >= 0; i --) {
      printf(" %02x", p_inst[i]);
    }
    printf("\n");
  }
}

void backtrace() {
  printf(ANSI_FMT("Backtrace:\n", ANSI_FG_GREEN));
  int i = 0;
  for (struct func_stack_t *p = func_stack_top->pre; p; p = p->pre, i++) {
    printf("#%d: %s() 0x%016lx\n", i, p->func->name, p->func->addr);
  }
}

void func_list() {
  if (!functbl) {
    Error("No functbl specified");
    return;
  }
  printf(ANSI_FMT("Address             Name\n", ANSI_FG_BLUE));
  for (int i = 0; !functbl[i].end; i++) {
    printf("0x%016lx  %s\n", functbl[i].addr, functbl[i].name);
  }
}