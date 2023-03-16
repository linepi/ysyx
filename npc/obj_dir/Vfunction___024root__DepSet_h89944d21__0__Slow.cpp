// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfunction.h for the primary calling header

#include "verilated.h"

#include "Vfunction___024root.h"

VL_ATTR_COLD void Vfunction___024root___eval_static(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfunction___024root___eval_final(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vfunction___024root___eval_settle(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfunction___024root___dump_triggers__act(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfunction___024root___dump_triggers__nba(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfunction___024root___ctor_var_reset(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->testbench__DOT__a = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__b = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__c = VL_RAND_RESET_I(1);
    }
