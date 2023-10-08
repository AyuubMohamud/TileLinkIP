// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTileLink1toN.h"
#include "VTileLink1toN__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VTileLink1toN::VTileLink1toN(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTileLink1toN__Syms(contextp(), _vcname__, this)}
    , tilelink_clock_i{vlSymsp->TOP.tilelink_clock_i}
    , tilelink_reset_i{vlSymsp->TOP.tilelink_reset_i}
    , master_a_opcode{vlSymsp->TOP.master_a_opcode}
    , master_a_param{vlSymsp->TOP.master_a_param}
    , master_a_size{vlSymsp->TOP.master_a_size}
    , master_a_source{vlSymsp->TOP.master_a_source}
    , master_a_mask{vlSymsp->TOP.master_a_mask}
    , master_a_corrupt{vlSymsp->TOP.master_a_corrupt}
    , master_a_valid{vlSymsp->TOP.master_a_valid}
    , master_a_ready{vlSymsp->TOP.master_a_ready}
    , master_d_opcode{vlSymsp->TOP.master_d_opcode}
    , master_d_param{vlSymsp->TOP.master_d_param}
    , master_d_size{vlSymsp->TOP.master_d_size}
    , master_d_source{vlSymsp->TOP.master_d_source}
    , master_d_denied{vlSymsp->TOP.master_d_denied}
    , master_d_corrupt{vlSymsp->TOP.master_d_corrupt}
    , master_d_valid{vlSymsp->TOP.master_d_valid}
    , master_d_ready{vlSymsp->TOP.master_d_ready}
    , slave_a_opcode{vlSymsp->TOP.slave_a_opcode}
    , slave_a_param{vlSymsp->TOP.slave_a_param}
    , slave_a_size{vlSymsp->TOP.slave_a_size}
    , slave_a_source{vlSymsp->TOP.slave_a_source}
    , slave_a_mask{vlSymsp->TOP.slave_a_mask}
    , slave_a_corrupt{vlSymsp->TOP.slave_a_corrupt}
    , slave_a_valid{vlSymsp->TOP.slave_a_valid}
    , slave_a_ready{vlSymsp->TOP.slave_a_ready}
    , slave_d_opcode{vlSymsp->TOP.slave_d_opcode}
    , slave_d_param{vlSymsp->TOP.slave_d_param}
    , slave_d_size{vlSymsp->TOP.slave_d_size}
    , slave_d_source{vlSymsp->TOP.slave_d_source}
    , slave_d_denied{vlSymsp->TOP.slave_d_denied}
    , slave_d_corrupt{vlSymsp->TOP.slave_d_corrupt}
    , slave_d_valid{vlSymsp->TOP.slave_d_valid}
    , slave_d_ready{vlSymsp->TOP.slave_d_ready}
    , master_a_address{vlSymsp->TOP.master_a_address}
    , master_a_data{vlSymsp->TOP.master_a_data}
    , master_d_data{vlSymsp->TOP.master_d_data}
    , slave_a_address{vlSymsp->TOP.slave_a_address}
    , slave_a_data{vlSymsp->TOP.slave_a_data}
    , slave_d_data{vlSymsp->TOP.slave_d_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTileLink1toN::VTileLink1toN(const char* _vcname__)
    : VTileLink1toN(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTileLink1toN::~VTileLink1toN() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTileLink1toN___024root___eval_debug_assertions(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG
void VTileLink1toN___024root___eval_static(VTileLink1toN___024root* vlSelf);
void VTileLink1toN___024root___eval_initial(VTileLink1toN___024root* vlSelf);
void VTileLink1toN___024root___eval_settle(VTileLink1toN___024root* vlSelf);
void VTileLink1toN___024root___eval(VTileLink1toN___024root* vlSelf);

void VTileLink1toN::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTileLink1toN::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTileLink1toN___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTileLink1toN___024root___eval_static(&(vlSymsp->TOP));
        VTileLink1toN___024root___eval_initial(&(vlSymsp->TOP));
        VTileLink1toN___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTileLink1toN___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTileLink1toN::eventsPending() { return false; }

uint64_t VTileLink1toN::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTileLink1toN::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTileLink1toN___024root___eval_final(VTileLink1toN___024root* vlSelf);

VL_ATTR_COLD void VTileLink1toN::final() {
    VTileLink1toN___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTileLink1toN::hierName() const { return vlSymsp->name(); }
const char* VTileLink1toN::modelName() const { return "VTileLink1toN"; }
unsigned VTileLink1toN::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VTileLink1toN::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VTileLink1toN___024root__trace_init_top(VTileLink1toN___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VTileLink1toN___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTileLink1toN___024root*>(voidSelf);
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VTileLink1toN___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VTileLink1toN___024root__trace_register(VTileLink1toN___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VTileLink1toN::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VTileLink1toN::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VTileLink1toN___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
