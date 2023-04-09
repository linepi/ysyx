// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnb.h for the primary calling header

#include "verilated.h"

#include "Vnb___024root.h"

void Vnb___024root___eval_act(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vnb___024root___nba_sequent__TOP__0(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__nb__DOT__keyboard_ins__DOT__ps2_clk_sync;
    __Vdly__nb__DOT__keyboard_ins__DOT__ps2_clk_sync = 0;
    CData/*3:0*/ __Vdly__nb__DOT__keyboard_ins__DOT__count;
    __Vdly__nb__DOT__keyboard_ins__DOT__count = 0;
    // Body
    __Vdly__nb__DOT__keyboard_ins__DOT__ps2_clk_sync 
        = vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync;
    __Vdly__nb__DOT__keyboard_ins__DOT__count = vlSelf->nb__DOT__keyboard_ins__DOT__count;
    __Vdly__nb__DOT__keyboard_ins__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (VL_UNLIKELY((0U != (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync)))) {
        VL_WRITEF("%b\n",3,vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync);
    }
    if (vlSelf->resetn) {
        if ((IData)((4U == (6U & (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__count))) {
                if (VL_UNLIKELY((((~ (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__buffer)) 
                                  & (IData)(vlSelf->ps2_data)) 
                                 & VL_REDXOR_32((0x1ffU 
                                                 & ((IData)(vlSelf->nb__DOT__keyboard_ins__DOT__buffer) 
                                                    >> 1U)))))) {
                    VL_WRITEF("receive %x\n",8,(0xffU 
                                                & ((IData)(vlSelf->nb__DOT__keyboard_ins__DOT__buffer) 
                                                   >> 1U)));
                }
                __Vdly__nb__DOT__keyboard_ins__DOT__count = 0U;
            } else {
                vlSelf->nb__DOT__keyboard_ins__DOT____Vlvbound_h1a91ade8__0 
                    = vlSelf->ps2_data;
                if (VL_LIKELY((9U >= (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__count)))) {
                    vlSelf->nb__DOT__keyboard_ins__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__count))) 
                            & (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->nb__DOT__keyboard_ins__DOT____Vlvbound_h1a91ade8__0) 
                                        << (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__count))));
                }
                __Vdly__nb__DOT__keyboard_ins__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->nb__DOT__keyboard_ins__DOT__count)));
            }
        }
    } else {
        __Vdly__nb__DOT__keyboard_ins__DOT__count = 0U;
    }
    vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync 
        = __Vdly__nb__DOT__keyboard_ins__DOT__ps2_clk_sync;
    vlSelf->nb__DOT__keyboard_ins__DOT__count = __Vdly__nb__DOT__keyboard_ins__DOT__count;
}

void Vnb___024root___eval_nba(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vnb___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vnb___024root___eval_triggers__act(Vnb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnb___024root___dump_triggers__act(Vnb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnb___024root___dump_triggers__nba(Vnb___024root* vlSelf);
#endif  // VL_DEBUG

void Vnb___024root___eval(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval\n"); );
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
            Vnb___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vnb___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/w/dev/ysyx-workbench/npc/vsrc/nb.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vnb___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vnb___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/w/dev/ysyx-workbench/npc/vsrc/nb.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vnb___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vnb___024root___eval_debug_assertions(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
    if (VL_UNLIKELY((vlSelf->resetn & 0xfeU))) {
        Verilated::overWidthError("resetn");}
}
#endif  // VL_DEBUG
