#include "defs.h"

VPC *PC;
static bool inited = false;
bool npc_end = false;
vaddr_t *pc;
uint32_t *inst;

void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
}

int isa_exec_once(Decode *s) {
  if (!inited) {
    PC = new VPC;
    PC->rst = true;
    single_cycle();
    inited = true; 
  } else {
    PC->rst = false;
  }

  s->snpc += 4;
  s->isa.inst.val = PC->inst;
  single_cycle();
  s->dnpc = PC->pc;

  if (npc_end) {
    NEMUTRAP(cpu.pc, R(10));
    PC->final();
    delete PC;
  }
  return 0;
}