// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPC.h for the primary calling header

#ifndef VERILATED_VPC___024UNIT_H_
#define VERILATED_VPC___024UNIT_H_  // guard

#include "verilated.h"

class VPC__Syms;

class VPC___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    VPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPC___024unit(VPC__Syms* symsp, const char* v__name);
    ~VPC___024unit();
    VL_UNCOPYABLE(VPC___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
