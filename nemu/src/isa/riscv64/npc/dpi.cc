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

void ebreak() {
	npc_end = true;
}

void set_gpr_ptr(const svOpenArrayHandle r) {
  cpu.gpr = (uint64_t *)(((VerilatedDpiOpenVar*)r)->datap());
}