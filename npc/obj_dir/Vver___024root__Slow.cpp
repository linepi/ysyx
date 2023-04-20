// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vver.h for the primary calling header

#include "verilated.h"

#include "Vver__Syms.h"
#include "Vver___024root.h"

void Vver___024root___ctor_var_reset(Vver___024root* vlSelf);

Vver___024root::Vver___024root(Vver__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vver___024root___ctor_var_reset(this);
}

void Vver___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vver___024root::~Vver___024root() {
}
