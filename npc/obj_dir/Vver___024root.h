// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vver.h for the primary calling header

#ifndef VERILATED_VVER___024ROOT_H_
#define VERILATED_VVER___024ROOT_H_  // guard

#include "verilated.h"

class Vver__Syms;

class Vver___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(pc,63,0);
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vver__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vver___024root(Vver__Syms* symsp, const char* v__name);
    ~Vver___024root();
    VL_UNCOPYABLE(Vver___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
