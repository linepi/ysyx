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

VL_ATTR_COLD void Vnb___024root___eval_initial__TOP(Vnb___024root* vlSelf);

VL_ATTR_COLD void Vnb___024root___eval_initial(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_initial\n"); );
    // Body
    Vnb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vnb___024root___eval_initial__TOP(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->seg5 = 0x7fU;
    vlSelf->seg6 = 0x7fU;
    vlSelf->seg7 = 0x7fU;
    vlSelf->nb__DOT__enable = 1U;
}

VL_ATTR_COLD void Vnb___024root___eval_final(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vnb___024root___eval_triggers__stl(Vnb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vnb___024root___dump_triggers__stl(Vnb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vnb___024root___eval_stl(Vnb___024root* vlSelf);

VL_ATTR_COLD void Vnb___024root___eval_settle(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vnb___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vnb___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/w/dev/ysyx-workbench/npc/vsrc/nb.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vnb___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnb___024root___dump_triggers__stl(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*6:0*/, 32> Vnb__ConstPool__TABLE_h47d0bdac_0;

VL_ATTR_COLD void Vnb___024root___stl_sequent__TOP__0(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx1 = ((0x1eU & ((IData)(vlSelf->nb__DOT__code) 
                              << 1U)) | (IData)(vlSelf->nb__DOT__enable));
    vlSelf->seg0 = Vnb__ConstPool__TABLE_h47d0bdac_0
        [__Vtableidx1];
    __Vtableidx2 = ((0x1eU & ((IData)(vlSelf->nb__DOT__code) 
                              >> 3U)) | (IData)(vlSelf->nb__DOT__enable));
    vlSelf->seg1 = Vnb__ConstPool__TABLE_h47d0bdac_0
        [__Vtableidx2];
}

VL_ATTR_COLD void Vnb___024root___eval_stl(Vnb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vnb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnb___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vnb___024root___stl_sequent__TOP__0(vlSelf);
    }
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
    vlSelf->seg0 = VL_RAND_RESET_I(7);
    vlSelf->seg1 = VL_RAND_RESET_I(7);
    vlSelf->seg2 = VL_RAND_RESET_I(7);
    vlSelf->seg3 = VL_RAND_RESET_I(7);
    vlSelf->seg4 = VL_RAND_RESET_I(7);
    vlSelf->seg5 = VL_RAND_RESET_I(7);
    vlSelf->seg6 = VL_RAND_RESET_I(7);
    vlSelf->seg7 = VL_RAND_RESET_I(7);
    vlSelf->nb__DOT__code = VL_RAND_RESET_I(8);
    vlSelf->nb__DOT__enable = VL_RAND_RESET_I(1);
    vlSelf->nb__DOT__keyboard_ins__DOT__buffer = VL_RAND_RESET_I(10);
    vlSelf->nb__DOT__keyboard_ins__DOT__count = VL_RAND_RESET_I(4);
    vlSelf->nb__DOT__keyboard_ins__DOT__ps2_clk_sync = VL_RAND_RESET_I(3);
    vlSelf->nb__DOT__keyboard_ins__DOT____Vlvbound_h1a91ade8__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
}
