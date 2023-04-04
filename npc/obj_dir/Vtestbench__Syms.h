// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTESTBENCH__SYMS_H_
#define VERILATED_VTESTBENCH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtestbench.h"

// INCLUDE MODULE CLASSES
#include "Vtestbench___024root.h"
#include "Vtestbench___024unit.h"

// SYMS CLASS (contains all model state)
class Vtestbench__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtestbench* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtestbench___024root           TOP;
    Vtestbench___024unit           TOP____024unit;

    // SCOPE NAMES
    VerilatedScope __Vscope_testbench;

    // CONSTRUCTORS
    Vtestbench__Syms(VerilatedContext* contextp, const char* namep, Vtestbench* modelp);
    ~Vtestbench__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
