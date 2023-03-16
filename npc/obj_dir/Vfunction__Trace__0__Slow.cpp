// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfunction__Syms.h"


VL_ATTR_COLD void Vfunction___024root__trace_init_sub__TOP__0(Vfunction___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushNamePrefix("testbench ");
    tracep->declBit(c+1,"a", false,-1);
    tracep->declBit(c+2,"b", false,-1);
    tracep->declBit(c+3,"c", false,-1);
    tracep->declBit(c+4,"y", false,-1);
    tracep->pushNamePrefix("dut ");
    tracep->declBit(c+1,"a", false,-1);
    tracep->declBit(c+2,"b", false,-1);
    tracep->declBit(c+3,"c", false,-1);
    tracep->declBit(c+4,"y", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vfunction___024root__trace_init_top(Vfunction___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_init_top\n"); );
    // Body
    Vfunction___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfunction___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfunction___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfunction___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfunction___024root__trace_register(Vfunction___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vfunction___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vfunction___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vfunction___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfunction___024root__trace_full_sub_0(Vfunction___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfunction___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_full_top_0\n"); );
    // Init
    Vfunction___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfunction___024root*>(voidSelf);
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfunction___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vfunction___024root__trace_full_sub_0(Vfunction___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->testbench__DOT__a));
    bufp->fullBit(oldp+2,(vlSelf->testbench__DOT__b));
    bufp->fullBit(oldp+3,(vlSelf->testbench__DOT__c));
    bufp->fullBit(oldp+4,((1U & ((~ (IData)(vlSelf->testbench__DOT__b)) 
                                 & ((~ (IData)(vlSelf->testbench__DOT__c)) 
                                    | (IData)(vlSelf->testbench__DOT__a))))));
}
