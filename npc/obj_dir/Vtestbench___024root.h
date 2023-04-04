// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestbench.h for the primary calling header

#ifndef VERILATED_VTESTBENCH___024ROOT_H_
#define VERILATED_VTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"

class Vtestbench__Syms;
class Vtestbench___024unit;


class Vtestbench___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtestbench___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ testbench__DOT__clk;
    CData/*0:0*/ testbench__DOT__counter_ins__DOT__w1;
    CData/*0:0*/ testbench__DOT__counter_ins__DOT__w2;
    CData/*0:0*/ testbench__DOT__Q0;
    CData/*0:0*/ testbench__DOT__Q1;
    CData/*0:0*/ testbench__DOT__Q2;
    CData/*0:0*/ testbench__DOT__counter_ins__DOT__w3;
    CData/*0:0*/ __Vtrigrprev__TOP__testbench__DOT__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__testbench__DOT__counter_ins__DOT__w1;
    CData/*0:0*/ __Vtrigrprev__TOP__testbench__DOT__counter_ins__DOT__w2;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtestbench__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestbench___024root(Vtestbench__Syms* symsp, const char* v__name);
    ~Vtestbench___024root();
    VL_UNCOPYABLE(Vtestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
