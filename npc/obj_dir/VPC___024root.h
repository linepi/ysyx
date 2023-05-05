// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPC.h for the primary calling header

#ifndef VERILATED_VPC___024ROOT_H_
#define VERILATED_VPC___024ROOT_H_  // guard

#include "verilated.h"

class VPC__Syms;

class VPC___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(pc,63,0);
    VL_OUT64(regs[32],63,0);
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPC___024root(VPC__Syms* symsp, const char* v__name);
    ~VPC___024root();
    VL_UNCOPYABLE(VPC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
