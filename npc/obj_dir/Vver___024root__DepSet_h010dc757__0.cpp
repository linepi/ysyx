// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vver.h for the primary calling header

#include "verilated.h"

#include "Vver__Syms.h"
#include "Vver___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vver___024root___dump_triggers__act(Vver___024root* vlSelf);
#endif  // VL_DEBUG

void Vver___024root___eval_triggers__act(Vver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vver___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vver___024root___dump_triggers__act(vlSelf);
    }
#endif
}
