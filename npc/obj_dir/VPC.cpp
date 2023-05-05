// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPC.h"
#include "VPC__Syms.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VPC::VPC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPC__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , ebreak{vlSymsp->TOP.ebreak}
    , inst{vlSymsp->TOP.inst}
    , pc{vlSymsp->TOP.pc}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPC::VPC(const char* _vcname__)
    : VPC(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPC::~VPC() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VPC___024root___eval_debug_assertions(VPC___024root* vlSelf);
#endif  // VL_DEBUG
void VPC___024root___eval_static(VPC___024root* vlSelf);
void VPC___024root___eval_initial(VPC___024root* vlSelf);
void VPC___024root___eval_settle(VPC___024root* vlSelf);
void VPC___024root___eval(VPC___024root* vlSelf);

void VPC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VPC___024root___eval_static(&(vlSymsp->TOP));
        VPC___024root___eval_initial(&(vlSymsp->TOP));
        VPC___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VPC___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VPC::eventsPending() { return false; }

uint64_t VPC::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VPC::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VPC___024root___eval_final(VPC___024root* vlSelf);

VL_ATTR_COLD void VPC::final() {
    VPC___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPC::hierName() const { return vlSymsp->name(); }
const char* VPC::modelName() const { return "VPC"; }
unsigned VPC::threads() const { return 1; }
