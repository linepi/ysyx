// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfunction__Syms.h"


void Vfunction___024root__trace_chg_sub_0(Vfunction___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfunction___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_chg_top_0\n"); );
    // Init
    Vfunction___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfunction___024root*>(voidSelf);
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfunction___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vfunction___024root__trace_chg_sub_0(Vfunction___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->testbench__DOT__a));
    bufp->chgBit(oldp+1,(vlSelf->testbench__DOT__b));
    bufp->chgBit(oldp+2,(vlSelf->testbench__DOT__c));
    bufp->chgBit(oldp+3,((1U & ((~ (IData)(vlSelf->testbench__DOT__b)) 
                                & ((~ (IData)(vlSelf->testbench__DOT__c)) 
                                   | (IData)(vlSelf->testbench__DOT__a))))));
}

void Vfunction___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_cleanup\n"); );
    // Init
    Vfunction___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfunction___024root*>(voidSelf);
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
