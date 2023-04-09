// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnb.h for the primary calling header

#include "verilated.h"

#include "Vnb___024root.h"

VL_ATTR_COLD void Vnb___024root___eval_static(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vnb___024root___eval_initial(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vnb___024root___eval_final(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vnb___024root___eval_settle(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnb___024root___dump_triggers__act(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnb___024root___dump_triggers__nba(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnb___024root___ctor_var_reset(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_data = VL_RAND_RESET_I(1);
    vlSelf->resetn = VL_RAND_RESET_I(1);
    vlSelf->nb__DOT__keyboard_ins__DOT__buffer = VL_RAND_RESET_I(10);
    vlSelf->nb__DOT__keyboard_ins__DOT__count = VL_RAND_RESET_I(4);
    vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync = VL_RAND_RESET_I(3);
    vlSelf->nb__DOT__keyboard_ins__DOT____Vlvbound_h1a91ade8__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
}
