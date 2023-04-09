// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnb.h for the primary calling header

#ifndef VERILATED_VNB___024ROOT_H_
#define VERILATED_VNB___024ROOT_H_  // guard

#include "verilated.h"

class Vnb__Syms;

class Vnb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ nb__DOT__enable;
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_IN8(resetn,0,0);
    VL_OUT8(seg0,7,0);
    VL_OUT8(seg1,7,0);
    VL_OUT8(seg2,7,0);
    VL_OUT8(seg3,7,0);
    VL_OUT8(seg4,7,0);
    VL_OUT8(seg5,7,0);
    VL_OUT8(seg6,7,0);
    VL_OUT8(seg7,7,0);
    CData/*7:0*/ nb__DOT__code;
    CData/*3:0*/ nb__DOT__keyboard_ins__DOT__count;
    CData/*2:0*/ nb__DOT__keyboard_ins__DOT__ps2_clk_sync;
    CData/*0:0*/ nb__DOT__keyboard_ins__DOT____Vlvbound_h1a91ade8__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ nb__DOT__keyboard_ins__DOT__buffer;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vnb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vnb___024root(Vnb__Syms* symsp, const char* v__name);
    ~Vnb___024root();
    VL_UNCOPYABLE(Vnb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
