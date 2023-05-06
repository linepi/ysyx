#include "svdpi.h"
#include "verilated_dpi.h"
#include "VPC__Dpi.h"
#include "defs.h"

extern "C" {
#include "../local-include/reg.h"
#include <generated/autoconf.h>
#include <sdb.h>
#include <cpu/cpu.h>
}

uint64_t *cpu_gpr = NULL;

void write_r(const svLogicVecVal* no, const svLogicVecVal* val) {
	gpr(no->aval) = val->aval;
	printf("no->aval = %x, no->bval = %x\n", no->aval, no->bval);
	printf("val->aval = %x, val->bval = %x\n", val->aval, val->bval);
}

void ebreak() {
	npc_end = true;
}

void set_gpr_ptr(const svOpenArrayHandle r) {
  cpu_gpr = (uint64_t *)(((VerilatedDpiOpenVar*)r)->datap());
}
void dump_gpr() {
  int i;
  for (i = 0; i < 32; i++) {
    printf("gpr[%d] = 0x%lx\n", i, cpu_gpr[i]);
  }
}