// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfunction.h for the primary calling header

#include "verilated.h"

#include "Vfunction___024root.h"

VlCoroutine Vfunction___024root___eval_initial__TOP__0(Vfunction___024root* vlSelf);

void Vfunction___024root___eval_initial(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_initial\n"); );
    // Body
    Vfunction___024root___eval_initial__TOP__0(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vfunction___024root___eval_initial__TOP__0(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_initial__TOP__0\n"); );
    // Body
    vlSelf->testbench__DOT__a = 0U;
    vlSelf->testbench__DOT__b = 0U;
    vlSelf->testbench__DOT__c = 0U;
    co_await vlSelf->__VdlySched.delay(0xaULL, "vsrc/test.v", 
                                       8);
}

void Vfunction___024root___eval_act(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_act\n"); );
}

void Vfunction___024root___eval_nba(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_nba\n"); );
}

void Vfunction___024root___eval_triggers__act(Vfunction___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfunction___024root___dump_triggers__act(Vfunction___024root* vlSelf);
#endif  // VL_DEBUG
void Vfunction___024root___timing_resume(Vfunction___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfunction___024root___dump_triggers__nba(Vfunction___024root* vlSelf);
#endif  // VL_DEBUG

void Vfunction___024root___eval(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vfunction___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vfunction___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/test.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vfunction___024root___timing_resume(vlSelf);
                Vfunction___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vfunction___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/test.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vfunction___024root___eval_nba(vlSelf);
        }
    }
}

void Vfunction___024root___timing_resume(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___timing_resume\n"); );
    // Body
    if (vlSelf->__VactTriggered.at(0U)) {
        vlSelf->__VdlySched.resume();
    }
}

#ifdef VL_DEBUG
void Vfunction___024root___eval_debug_assertions(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
