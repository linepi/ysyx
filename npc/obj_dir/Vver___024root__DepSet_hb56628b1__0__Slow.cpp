// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vver.h for the primary calling header

#include "verilated.h"

#include "Vver___024root.h"

VL_ATTR_COLD void Vver___024root___eval_static(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vver___024root___eval_initial(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Vver___024root___eval_final(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vver___024root___eval_settle(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vver___024root___dump_triggers__act(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vver___024root___dump_triggers__nba(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vver___024root___ctor_var_reset(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_Q(64);
}
