// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfunction.h for the primary calling header

#include "verilated.h"

#include "Vfunction__Syms.h"
#include "Vfunction___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfunction___024root___dump_triggers__act(Vfunction___024root* vlSelf);
#endif  // VL_DEBUG

void Vfunction___024root___eval_triggers__act(Vfunction___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfunction___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = vlSelf->__VdlySched.awaitingCurrentTime();
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfunction___024root___dump_triggers__act(vlSelf);
    }
#endif
}
