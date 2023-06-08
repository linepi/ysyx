#include "defs.h"

VPC *PC;
bool npc_inited = false;
bool npc_end = false;
bool npc_error = false;

static void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
}

static void reset(int n) {
  PC->rst = true;
  while (n-- > 0) single_cycle();
  PC->rst = false;
}

int isa_exec_once(Decode *s) {
  if (!npc_inited) {
    PC = new VPC;
    reset(10);
    npc_inited = true; 
  } 
}

int isa_exec_once(Decode *s) {
  s->snpc += 4;
  s->isa.inst.val = PC->inst;
  single_cycle();
  s->dnpc = PC->pc;

  if (npc_end) {
    if (!npc_error)
      NEMUTRAP(cpu.pc, R(10));
    else
      set_nemu_state(NEMU_ABORT, cpu.pc, 0);
    PC->final();
    delete PC;
  }
  return 0;
}