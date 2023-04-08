// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VVER__SYMS_H_
#define VERILATED_VVER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vver.h"

// INCLUDE MODULE CLASSES
#include "Vver___024root.h"

// SYMS CLASS (contains all model state)
class Vver__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vver* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vver___024root                 TOP;

    // CONSTRUCTORS
    Vver__Syms(VerilatedContext* contextp, const char* namep, Vver* modelp);
    ~Vver__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
