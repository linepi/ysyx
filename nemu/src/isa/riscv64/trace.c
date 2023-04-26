#include <sdb.h>
#include <reg.h>

struct func_t *functbl = NULL;
struct func_t cur_func = {};
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
      functbl[idx].end = false;
      idx++;
    }
  }
  functbl[idx].end = true;
  for (int i = 0; !functbl[i].end; i++) {
    printf("func addr 0x%016lx, func name %s\n", functbl[i].addr, functbl[i].name);
  }
}

void ftrace(vaddr_t pc) {
  static char lastfunc[FUNC_LEN];
  vaddr_t save_pc = pc;
  uint32_t i = inst_fetch_add(&pc, 4);
  if (i == 0x00008067) {
    if (g_print_step) printf(ANSI_FMT("ret from %s\n", ANSI_FG_BLUE), lastfunc);
    return;
  }

  vaddr_t jump_to = 0;
  word_t _imm = 0;
  word_t *imm = &_imm;
  // jal
  if ((i & 0b1111111) == 0b1101111) {
    immUJ();
    jump_to = *imm + save_pc;
  }
  // jalr
  if ((i & 0b111000001111111) == 0b000000001100111) {
    word_t src1 = gpr(BITS(i, 19, 15));
    immI();
    jump_to = *imm + src1;
  }

  for (int i = 0; !functbl[i].end; i++) {
    if (functbl[i].addr == jump_to) {
      if (g_print_step) printf(ANSI_FMT("call %s\n", ANSI_FG_BLUE), functbl[i].name);
      cur_func = functbl[i];
      strcpy(lastfunc, functbl[i].name);
      break;
    }
  }
}

// just for riscv64
void frame_dump(vaddr_t pc, int n) {
  printf(ANSI_FMT("Frame %s(), with pc = 0x%016lx:\n", ANSI_FG_GREEN), cur_func.name[0] ? cur_func.name : "unknown", cpu.pc);
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
    disassemble(disa, 128, saved_pc, (uint8_t *)&inst, 4);

    printf("0x%08lx: %s", saved_pc, disa); 
    for (int i = 0; i < 30 - strlen(disa); i++) putchar(' ');
    uint8_t *p_inst = (uint8_t *)&inst;
    for (int i = 3; i >= 0; i --) {
      printf(" %02x", p_inst[i]);
    }
    printf("\n");
  }
}