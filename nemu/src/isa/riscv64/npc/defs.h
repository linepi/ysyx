#ifndef __NPC_DEFS_H__
#define __NPC_DEFS_H__

#include "svdpi.h"
#include "verilated_dpi.h"
#include "VPC__Dpi.h"
#include <VPC.h> 

extern "C" {
#include "../local-include/reg.h"
#include <generated/autoconf.h>
#include <sdb.h>
#include <utils.h>
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
}
#define R(i) gpr(i)

extern bool npc_end;
extern uint32_t *inst;
extern vaddr_t *pc;
void clean_PC();

#endif