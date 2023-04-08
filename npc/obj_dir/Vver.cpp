// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vver.h"
#include "Vver__Syms.h"

//============================================================
// Constructors

Vver::Vver(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vver__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , c{vlSymsp->TOP.c}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vver::Vver(const char* _vcname__)
    : Vver(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vver::~Vver() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vver___024root___eval_debug_assertions(Vver___024root* vlSelf);
#endif  // VL_DEBUG
void Vver___024root___eval_static(Vver___024root* vlSelf);
void Vver___024root___eval_initial(Vver___024root* vlSelf);
void Vver___024root___eval_settle(Vver___024root* vlSelf);
void Vver___024root___eval(Vver___024root* vlSelf);

void Vver::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vver::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vver___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vver___024root___eval_static(&(vlSymsp->TOP));
        Vver___024root___eval_initial(&(vlSymsp->TOP));
        Vver___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vver___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vver::eventsPending() { return false; }

uint64_t Vver::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vver::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vver___024root___eval_final(Vver___024root* vlSelf);

VL_ATTR_COLD void Vver::final() {
    Vver___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vver::hierName() const { return vlSymsp->name(); }
const char* Vver::modelName() const { return "Vver"; }
unsigned Vver::threads() const { return 1; }
