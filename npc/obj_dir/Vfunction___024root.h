// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfunction.h for the primary calling header

#ifndef VERILATED_VFUNCTION___024ROOT_H_
#define VERILATED_VFUNCTION___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"

class Vfunction__Syms;

class Vfunction___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ testbench__DOT__a;
    CData/*0:0*/ testbench__DOT__b;
    CData/*0:0*/ testbench__DOT__c;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfunction__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfunction___024root(Vfunction__Syms* symsp, const char* v__name);
    ~Vfunction___024root();
    VL_UNCOPYABLE(Vfunction___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
