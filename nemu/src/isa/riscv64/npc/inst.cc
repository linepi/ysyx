#include "defs.h"

VPC *PC;
static bool inited = false;
bool npc_end = false;

void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
}

int isa_exec_once(Decode *s) {
  if (!inited) {
    PC = new VPC;
    inited = true; 
  }

  s->snpc += 4;
  // s->isa.inst.val = getinst();
  single_cycle();
  // s->dnpc = getpc();

  if (npc_end) {
    NEMUTRAP(cpu.pc, R(10));
    PC->final();
    delete PC;
  }
  return 0;
}