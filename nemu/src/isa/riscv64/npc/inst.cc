extern "C" {
#include <utils.h>
#include "../local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <generated/autoconf.h>
}

#include <VPC.h> 

#define R(i) gpr(i)

VPC *PC;
static bool inited = false;

void init_PC() {
  PC = new VPC;
  PC->pc = CONFIG_MBASE;
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

  s->isa.inst.val = inst_fetch_add(&s->snpc, 4);
  PC->inst = s->isa.inst.val;
  single_cycle();
  s->dnpc = PC->pc;

  if (PC->ebreak) {
    NEMUTRAP(s->pc, R(10));
    clean_PC();
  }
  return 0;
}