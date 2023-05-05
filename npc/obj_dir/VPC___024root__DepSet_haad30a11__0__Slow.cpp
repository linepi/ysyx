// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPC.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VPC__Syms.h"
#include "VPC___024root.h"

void VPC___024unit____Vdpiimwrap_add_TOP____024unit(IData/*31:0*/ a, IData/*31:0*/ b, IData/*31:0*/ &add__Vfuncrtn);

VL_ATTR_COLD void VPC___024root___eval_initial__TOP(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ __Vfunc_add__0__Vfuncout;
    __Vfunc_add__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_add__1__Vfuncout;
    __Vfunc_add__1__Vfuncout = 0;
    // Body
    VPC___024unit____Vdpiimwrap_add_TOP____024unit(1U, 2U, __Vfunc_add__1__Vfuncout);
    VPC___024unit____Vdpiimwrap_add_TOP____024unit(1U, 2U, __Vfunc_add__0__Vfuncout);
    vlSelf->PC__DOT__i_rf__DOT__rf[0U] = (((QData)((IData)(__Vfunc_add__0__Vfuncout)) 
                                           << 0x20U) 
                                          | (QData)((IData)(__Vfunc_add__1__Vfuncout)));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPC___024root___dump_triggers__stl(VPC___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VPC___024root___eval_triggers__stl(VPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPC___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPC___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
