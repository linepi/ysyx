#include "defs.h"

VPC *PC;
static bool inited = false;
bool npc_end = false;
vaddr_t *pc;
uint32_t *inst;

void init_PC() {
  PC = new VPC;
  *pc = CONFIG_MBASE;
}
void clean_PC() {
  PC->final();
  delete PC;
}

void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
}

int isa_exec_once(Decode *s) {
  if (!inited) { init_PC(); inited = true; }
  s->snpc += 4;
  single_cycle();
  s->isa.inst.val = *inst;
  s->dnpc = *pc;
  if (npc_end) {
    NEMUTRAP(cpu.pc, R(10));
    clean_PC();
  }
  return 0;
}