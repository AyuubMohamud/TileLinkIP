// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VopenPolarisDMACore.h"
#include "VopenPolarisDMACore__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VopenPolarisDMACore::VopenPolarisDMACore(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VopenPolarisDMACore__Syms(contextp(), _vcname__, this)}
    , dmac_clock_i{vlSymsp->TOP.dmac_clock_i}
    , dmac_reset_i{vlSymsp->TOP.dmac_reset_i}
    , dmac_tx_i{vlSymsp->TOP.dmac_tx_i}
    , dmac_busy_o{vlSymsp->TOP.dmac_busy_o}
    , dmac_done_o{vlSymsp->TOP.dmac_done_o}
    , dmac_err_o{vlSymsp->TOP.dmac_err_o}
    , dma_a_opcode{vlSymsp->TOP.dma_a_opcode}
    , dma_a_param{vlSymsp->TOP.dma_a_param}
    , dma_a_size{vlSymsp->TOP.dma_a_size}
    , dma_a_mask{vlSymsp->TOP.dma_a_mask}
    , dma_a_corrupt{vlSymsp->TOP.dma_a_corrupt}
    , dma_a_valid{vlSymsp->TOP.dma_a_valid}
    , dma_a_ready{vlSymsp->TOP.dma_a_ready}
    , dma_d_opcode{vlSymsp->TOP.dma_d_opcode}
    , dma_d_param{vlSymsp->TOP.dma_d_param}
    , dma_d_size{vlSymsp->TOP.dma_d_size}
    , dma_d_denied{vlSymsp->TOP.dma_d_denied}
    , dma_d_corrupt{vlSymsp->TOP.dma_d_corrupt}
    , dma_d_valid{vlSymsp->TOP.dma_d_valid}
    , dma_d_ready{vlSymsp->TOP.dma_d_ready}
    , dmac_source_address_i{vlSymsp->TOP.dmac_source_address_i}
    , dmac_dest_address_i{vlSymsp->TOP.dmac_dest_address_i}
    , dmac_bytes_tx_i{vlSymsp->TOP.dmac_bytes_tx_i}
    , dma_a_address{vlSymsp->TOP.dma_a_address}
    , dma_a_data{vlSymsp->TOP.dma_a_data}
    , dma_d_data{vlSymsp->TOP.dma_d_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VopenPolarisDMACore::VopenPolarisDMACore(const char* _vcname__)
    : VopenPolarisDMACore(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VopenPolarisDMACore::~VopenPolarisDMACore() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VopenPolarisDMACore___024root___eval_debug_assertions(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG
void VopenPolarisDMACore___024root___eval_static(VopenPolarisDMACore___024root* vlSelf);
void VopenPolarisDMACore___024root___eval_initial(VopenPolarisDMACore___024root* vlSelf);
void VopenPolarisDMACore___024root___eval_settle(VopenPolarisDMACore___024root* vlSelf);
void VopenPolarisDMACore___024root___eval(VopenPolarisDMACore___024root* vlSelf);

void VopenPolarisDMACore::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VopenPolarisDMACore::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VopenPolarisDMACore___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VopenPolarisDMACore___024root___eval_static(&(vlSymsp->TOP));
        VopenPolarisDMACore___024root___eval_initial(&(vlSymsp->TOP));
        VopenPolarisDMACore___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VopenPolarisDMACore___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VopenPolarisDMACore::eventsPending() { return false; }

uint64_t VopenPolarisDMACore::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VopenPolarisDMACore::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VopenPolarisDMACore___024root___eval_final(VopenPolarisDMACore___024root* vlSelf);

VL_ATTR_COLD void VopenPolarisDMACore::final() {
    VopenPolarisDMACore___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VopenPolarisDMACore::hierName() const { return vlSymsp->name(); }
const char* VopenPolarisDMACore::modelName() const { return "VopenPolarisDMACore"; }
unsigned VopenPolarisDMACore::threads() const { return 1; }
void VopenPolarisDMACore::prepareClone() const { contextp()->prepareClone(); }
void VopenPolarisDMACore::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VopenPolarisDMACore::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VopenPolarisDMACore___024root__trace_init_top(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VopenPolarisDMACore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VopenPolarisDMACore___024root*>(voidSelf);
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VopenPolarisDMACore___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_register(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VopenPolarisDMACore::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VopenPolarisDMACore::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VopenPolarisDMACore___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
