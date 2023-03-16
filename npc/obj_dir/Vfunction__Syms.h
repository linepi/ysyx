// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFUNCTION__SYMS_H_
#define VERILATED_VFUNCTION__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfunction.h"

// INCLUDE MODULE CLASSES
#include "Vfunction___024root.h"

// SYMS CLASS (contains all model state)
class Vfunction__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfunction* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfunction___024root            TOP;

    // CONSTRUCTORS
    Vfunction__Syms(VerilatedContext* contextp, const char* namep, Vfunction* modelp);
    ~Vfunction__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
