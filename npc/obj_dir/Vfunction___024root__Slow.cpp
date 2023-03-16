// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfunction.h for the primary calling header

#include "verilated.h"

#include "Vfunction__Syms.h"
#include "Vfunction___024root.h"

void Vfunction___024root___ctor_var_reset(Vfunction___024root* vlSelf);

Vfunction___024root::Vfunction___024root(Vfunction__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfunction___024root___ctor_var_reset(this);
}

void Vfunction___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfunction___024root::~Vfunction___024root() {
}
