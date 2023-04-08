// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vnb.h"
#include "Vnb__Syms.h"

//============================================================
// Constructors

Vnb::Vnb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vnb__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , ps2_clk{vlSymsp->TOP.ps2_clk}
    , ps2_data{vlSymsp->TOP.ps2_data}
    , resetn{vlSymsp->TOP.resetn}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vnb::Vnb(const char* _vcname__)
    : Vnb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vnb::~Vnb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vnb___024root___eval_debug_assertions(Vnb___024root* vlSelf);
#endif  // VL_DEBUG
void Vnb___024root___eval_static(Vnb___024root* vlSelf);
void Vnb___024root___eval_initial(Vnb___024root* vlSelf);
void Vnb___024root___eval_settle(Vnb___024root* vlSelf);
void Vnb___024root___eval(Vnb___024root* vlSelf);

void Vnb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vnb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vnb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vnb___024root___eval_static(&(vlSymsp->TOP));
        Vnb___024root___eval_initial(&(vlSymsp->TOP));
        Vnb___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vnb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vnb::eventsPending() { return false; }

uint64_t Vnb::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vnb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vnb___024root___eval_final(Vnb___024root* vlSelf);

VL_ATTR_COLD void Vnb::final() {
    Vnb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vnb::hierName() const { return vlSymsp->name(); }
const char* Vnb::modelName() const { return "Vnb"; }
unsigned Vnb::threads() const { return 1; }
