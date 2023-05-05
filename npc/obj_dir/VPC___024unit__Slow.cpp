// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPC.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VPC__Syms.h"
#include "VPC___024unit.h"

void VPC___024unit___ctor_var_reset(VPC___024unit* vlSelf);

VPC___024unit::VPC___024unit(VPC__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPC___024unit___ctor_var_reset(this);
}

void VPC___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPC___024unit::~VPC___024unit() {
}
