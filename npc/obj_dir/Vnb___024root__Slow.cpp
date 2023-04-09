// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnb.h for the primary calling header

#include "verilated.h"

#include "Vnb__Syms.h"
#include "Vnb___024root.h"

void Vnb___024root___ctor_var_reset(Vnb___024root* vlSelf);

Vnb___024root::Vnb___024root(Vnb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vnb___024root___ctor_var_reset(this);
}

void Vnb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vnb___024root::~Vnb___024root() {
}
