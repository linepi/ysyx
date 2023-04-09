// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VNB__SYMS_H_
#define VERILATED_VNB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vnb.h"

// INCLUDE MODULE CLASSES
#include "Vnb___024root.h"

// SYMS CLASS (contains all model state)
class Vnb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vnb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vnb___024root                  TOP;

    // CONSTRUCTORS
    Vnb__Syms(VerilatedContext* contextp, const char* namep, Vnb* modelp);
    ~Vnb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
