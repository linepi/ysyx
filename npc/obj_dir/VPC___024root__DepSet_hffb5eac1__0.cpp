// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPC.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VPC___024root.h"

VL_INLINE_OPT void VPC___024root___ico_sequent__TOP__0(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->ebreak = (0x100073U == vlSelf->inst);
    vlSelf->PC__DOT__dataD = (vlSelf->PC__DOT__i_rf__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))] 
                              + (((- (QData)((IData)(
                                                     (vlSelf->inst 
                                                      >> 0x1fU)))) 
                                  << 0xcU) | (QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0x14U)))));
}

void VPC___024root___eval_ico(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VPC___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VPC___024root___eval_act(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval_act\n"); );
}

VL_INLINE_OPT void VPC___024root___nba_sequent__TOP__0(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__PC__DOT__i_rf__DOT__rf__v0;
    __Vdlyvdim0__PC__DOT__i_rf__DOT__rf__v0 = 0;
    QData/*63:0*/ __Vdlyvval__PC__DOT__i_rf__DOT__rf__v0;
    __Vdlyvval__PC__DOT__i_rf__DOT__rf__v0 = 0;
    // Body
    vlSelf->pc = (4ULL + vlSelf->pc);
    vlSelf->PC__DOT__i_rf__DOT__rf_debug[(0x1fU & (vlSelf->inst 
                                                   >> 7U))] 
        = vlSelf->PC__DOT__dataD;
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0U]))) {
        VL_WRITEF("x0 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [1U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [1U]))) {
        VL_WRITEF("x1 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [1U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [1U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [1U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [1U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [2U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [2U]))) {
        VL_WRITEF("x2 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [2U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [2U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [2U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [2U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [3U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [3U]))) {
        VL_WRITEF("x3 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [3U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [3U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [3U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [3U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [4U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [4U]))) {
        VL_WRITEF("x4 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [4U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [4U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [4U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [4U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [5U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [5U]))) {
        VL_WRITEF("x5 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [5U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [5U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [5U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [5U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [6U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [6U]))) {
        VL_WRITEF("x6 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [6U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [6U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [6U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [6U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [7U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [7U]))) {
        VL_WRITEF("x7 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [7U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [7U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [7U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [7U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [8U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [8U]))) {
        VL_WRITEF("x8 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [8U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [8U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [8U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [8U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [9U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [9U]))) {
        VL_WRITEF("x9 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [9U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [9U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [9U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [9U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0xaU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0xaU]))) {
        VL_WRITEF("x10 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xaU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xaU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xaU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xaU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0xbU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0xbU]))) {
        VL_WRITEF("x11 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xbU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xbU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xbU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xbU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0xcU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0xcU]))) {
        VL_WRITEF("x12 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xcU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xcU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xcU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xcU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0xdU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0xdU]))) {
        VL_WRITEF("x13 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xdU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xdU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xdU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xdU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0xeU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0xeU]))) {
        VL_WRITEF("x14 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xeU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xeU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xeU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xeU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0xfU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0xfU]))) {
        VL_WRITEF("x15 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xfU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0xfU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xfU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0xfU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x10U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x10U]))) {
        VL_WRITEF("x16 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x10U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x10U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x10U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x10U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x11U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x11U]))) {
        VL_WRITEF("x17 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x11U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x11U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x11U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x11U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x12U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x12U]))) {
        VL_WRITEF("x18 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x12U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x12U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x12U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x12U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x13U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x13U]))) {
        VL_WRITEF("x19 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x13U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x13U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x13U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x13U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x14U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x14U]))) {
        VL_WRITEF("x20 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x14U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x14U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x14U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x14U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x15U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x15U]))) {
        VL_WRITEF("x21 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x15U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x15U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x15U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x15U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x16U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x16U]))) {
        VL_WRITEF("x22 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x16U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x16U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x16U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x16U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x17U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x17U]))) {
        VL_WRITEF("x23 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x17U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x17U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x17U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x17U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x18U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x18U]))) {
        VL_WRITEF("x24 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x18U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x18U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x18U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x18U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x19U] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x19U]))) {
        VL_WRITEF("x25 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x19U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x19U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x19U],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x19U]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x1aU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x1aU]))) {
        VL_WRITEF("x26 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1aU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1aU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1aU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1aU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x1bU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x1bU]))) {
        VL_WRITEF("x27 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1bU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1bU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1bU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1bU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x1cU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x1cU]))) {
        VL_WRITEF("x28 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1cU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1cU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1cU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1cU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x1dU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x1dU]))) {
        VL_WRITEF("x29 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1dU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1dU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1dU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1dU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x1eU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x1eU]))) {
        VL_WRITEF("x30 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1eU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1eU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1eU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1eU]);
    }
    if (VL_UNLIKELY((vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                     [0x1fU] != vlSelf->PC__DOT__i_rf__DOT__rf_debug
                     [0x1fU]))) {
        VL_WRITEF("x31 changed, from 0x%0x(%0d) to 0x%0x(%0d)\n",
                  64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1fU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug_last
                  [0x1fU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1fU],64,vlSelf->PC__DOT__i_rf__DOT__rf_debug
                  [0x1fU]);
    }
    vlSelf->PC__DOT__i_rf__DOT__rf_debug_last[(0x1fU 
                                               & (vlSelf->inst 
                                                  >> 7U))] 
        = vlSelf->PC__DOT__i_rf__DOT__rf_debug[(0x1fU 
                                                & (vlSelf->inst 
                                                   >> 7U))];
    __Vdlyvval__PC__DOT__i_rf__DOT__rf__v0 = vlSelf->PC__DOT__dataD;
    __Vdlyvdim0__PC__DOT__i_rf__DOT__rf__v0 = (0x1fU 
                                               & (vlSelf->inst 
                                                  >> 7U));
    vlSelf->PC__DOT__i_rf__DOT__rf[__Vdlyvdim0__PC__DOT__i_rf__DOT__rf__v0] 
        = __Vdlyvval__PC__DOT__i_rf__DOT__rf__v0;
    vlSelf->PC__DOT__dataD = (vlSelf->PC__DOT__i_rf__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))] 
                              + (((- (QData)((IData)(
                                                     (vlSelf->inst 
                                                      >> 0x1fU)))) 
                                  << 0xcU) | (QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0x14U)))));
}

void VPC___024root___eval_nba(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VPC___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VPC___024root___eval_triggers__ico(VPC___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPC___024root___dump_triggers__ico(VPC___024root* vlSelf);
#endif  // VL_DEBUG
void VPC___024root___eval_triggers__act(VPC___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPC___024root___dump_triggers__act(VPC___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPC___024root___dump_triggers__nba(VPC___024root* vlSelf);
#endif  // VL_DEBUG

void VPC___024root___eval(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VPC___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VPC___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/w/dev/ysyx-workbench/npc/vsrc/LemonPC/LemonPC.v", 3, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VPC___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VPC___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VPC___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/w/dev/ysyx-workbench/npc/vsrc/LemonPC/LemonPC.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VPC___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VPC___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/w/dev/ysyx-workbench/npc/vsrc/LemonPC/LemonPC.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VPC___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VPC___024root___eval_debug_assertions(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
