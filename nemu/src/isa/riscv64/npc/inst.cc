extern "C" {
#include <utils.h>
#include "../local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <generated/autoconf.h>
}

#include <VPC.h> 
#include "defs.h"

VPC *PC;
static bool inited = false;
bool npc_end = false;

void init_PC() {
  PC = new VPC;
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
  single_cycle();
  s->isa.inst.val = PC->inst;
  printf("PC-inst = 0x%08x\n", PC->inst);
  s->dnpc = PC->pc;
  if (npc_end) {
    NEMUTRAP(cpu.pc, R(10));
    clean_PC();
  }
  return 0;
}