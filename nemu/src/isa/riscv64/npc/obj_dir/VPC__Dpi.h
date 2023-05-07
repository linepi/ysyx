// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VPC__DPI_H_
#define VERILATED_VPC__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/w/dev/ysyx-workbench/npc/vsrc/LemonPC/LemonPC.v:1:30
    extern void ebreak();
    // DPI import at /home/w/dev/ysyx-workbench/npc/vsrc/LemonPC/LemonPC.v:2:30
    extern void set_gpr_ptr(const svOpenArrayHandle a);

#ifdef __cplusplus
}
#endif

#endif  // guard
