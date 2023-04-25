#include <sdb.h>

struct func_t *functbl = NULL;

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
  // for (int i = 0; !functbl[i].end; i++) {
  //   printf("func addr 0x%016lx, func name %s\n", functbl[i].addr, functbl[i].name);
  // }
}

void ftrace(vaddr_t pc) {
  
}

// just for riscv64
void frame_dump(int n) {
  printf(ANSI_FMT("Frame with pc = 0x%016lx:\n", ANSI_FG_GREEN), cpu.pc);
  char disa[128];
  vaddr_t pc = MAX(cpu.pc - 4 * (n/2), CONFIG_MBASE);
  for (int i = 0; i < n; i++) {
    if (pc != cpu.pc)
      printf("    ");
    else 
      printf(ANSI_FMT("=>  ", ANSI_FG_GREEN));
    // 这里保存pc的原因是，inst_fetch_add会使pc增加，以至于反汇编得不到所执行指令的正确相对地址
    vaddr_t saved_pc = pc;
    uint32_t inst = inst_fetch_add(&pc, 4);
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