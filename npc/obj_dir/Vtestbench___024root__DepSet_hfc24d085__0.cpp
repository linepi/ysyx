// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "verilated.h"

#include "Vtestbench__Syms.h"
#include "Vtestbench___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__act(Vtestbench___024root* vlSelf);
#endif  // VL_DEBUG

void Vtestbench___024root___eval_triggers__act(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->testbench__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__testbench__DOT__clk)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->testbench__DOT__counter_ins__DOT__w1) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__testbench__DOT__counter_ins__DOT__w1)));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSelf->testbench__DOT__counter_ins__DOT__w2) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__testbench__DOT__counter_ins__DOT__w2)));
    vlSelf->__VactTriggered.at(3U) = vlSelf->__VdlySched.awaitingCurrentTime();
    vlSelf->__Vtrigrprev__TOP__testbench__DOT__clk 
        = vlSelf->testbench__DOT__clk;
    vlSelf->__Vtrigrprev__TOP__testbench__DOT__counter_ins__DOT__w1 
        = vlSelf->testbench__DOT__counter_ins__DOT__w1;
    vlSelf->__Vtrigrprev__TOP__testbench__DOT__counter_ins__DOT__w2 
        = vlSelf->testbench__DOT__counter_ins__DOT__w2;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtestbench___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtestbench___024root___nba_comb__TOP__0(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___nba_comb__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSymsp->TOP____024unit.__VmonitorOff))))) {
        VL_WRITEF("%1# %1# %1#\n",1,vlSelf->testbench__DOT__Q2,
                  1,(IData)(vlSelf->testbench__DOT__Q1),
                  1,vlSelf->testbench__DOT__Q0);
    }
}
