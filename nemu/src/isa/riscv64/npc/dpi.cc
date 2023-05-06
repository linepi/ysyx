#include "svdpi.h"
#include "VPC__Dpi.h"
#include "defs.h"

extern "C" {
#include "../local-include/reg.h"
#include <generated/autoconf.h>
#include <sdb.h>
#include <cpu/cpu.h>
}

void write_r(const svLogicVecVal* no, const svLogicVecVal* val) {
	gpr(no->aval) = val->aval;
	printf("no->aval = %x, no->bval = %x\n", no->aval, no->bval);
	printf("val->aval = %x, val->bval = %x\n", val->aval, val->bval);
}

void ebreak() {
	npc_end = true;
}