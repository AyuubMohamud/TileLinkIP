// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VopenPolarisDMACore.h for the primary calling header

#ifndef VERILATED_VOPENPOLARISDMACORE___024ROOT_H_
#define VERILATED_VOPENPOLARISDMACORE___024ROOT_H_  // guard

#include "verilated.h"


class VopenPolarisDMACore__Syms;

class alignas(VL_CACHE_LINE_BYTES) VopenPolarisDMACore___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(dmac_clock_i,0,0);
    VL_IN8(dmac_reset_i,0,0);
    VL_IN8(dmac_tx_i,0,0);
    VL_OUT8(dmac_busy_o,0,0);
    VL_OUT8(dmac_done_o,0,0);
    VL_OUT8(dmac_err_o,0,0);
    VL_OUT8(dma_a_opcode,2,0);
    VL_OUT8(dma_a_param,2,0);
    VL_OUT8(dma_a_size,3,0);
    VL_OUT8(dma_a_mask,3,0);
    VL_OUT8(dma_a_corrupt,0,0);
    VL_OUT8(dma_a_valid,0,0);
    VL_IN8(dma_a_ready,0,0);
    VL_IN8(dma_d_opcode,2,0);
    VL_IN8(dma_d_param,1,0);
    VL_IN8(dma_d_size,3,0);
    VL_IN8(dma_d_denied,0,0);
    VL_IN8(dma_d_corrupt,0,0);
    VL_IN8(dma_d_valid,0,0);
    VL_OUT8(dma_d_ready,0,0);
    CData/*0:0*/ openPolarisDMACore__DOT__write_fifo;
    CData/*0:0*/ openPolarisDMACore__DOT__full;
    CData/*0:0*/ openPolarisDMACore__DOT__empty;
    CData/*1:0*/ openPolarisDMACore__DOT__dma_state;
    CData/*3:0*/ openPolarisDMACore__DOT__max_burst_size_from_dest_addr;
    CData/*3:0*/ openPolarisDMACore__DOT__max_burst_size_from_src_addr;
    CData/*3:0*/ openPolarisDMACore__DOT__max_burst_size_from_remainder;
    CData/*3:0*/ openPolarisDMACore__DOT__min_stage1;
    CData/*3:0*/ openPolarisDMACore__DOT__minimum;
    CData/*7:0*/ openPolarisDMACore__DOT__byte_count;
    CData/*7:0*/ openPolarisDMACore__DOT__count_store;
    CData/*3:0*/ openPolarisDMACore__DOT__size_store;
    CData/*0:0*/ openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0;
    CData/*5:0*/ openPolarisDMACore__DOT__fifo__DOT__read_ptr;
    CData/*5:0*/ openPolarisDMACore__DOT__fifo__DOT__write_ptr;
    CData/*0:0*/ __Vtrigprevexpr___TOP__dmac_clock_i__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(dmac_source_address_i,31,0);
    VL_IN(dmac_dest_address_i,31,0);
    VL_IN(dmac_bytes_tx_i,31,0);
    VL_OUT(dma_a_address,31,0);
    VL_OUT(dma_a_data,31,0);
    VL_IN(dma_d_data,31,0);
    IData/*31:0*/ openPolarisDMACore__DOT__bytesRemaining;
    IData/*31:0*/ openPolarisDMACore__DOT__current_source_address;
    IData/*31:0*/ openPolarisDMACore__DOT__current_destination_address;
    IData/*31:0*/ openPolarisDMACore__DOT__bytes_0;
    IData/*31:0*/ openPolarisDMACore__DOT__bytes_1;
    IData/*31:0*/ openPolarisDMACore__DOT__bytes_2;
    IData/*31:0*/ openPolarisDMACore__DOT__minimum_bytes;
    IData/*31:0*/ openPolarisDMACore__DOT__minimum_bytes_r;
    IData/*31:0*/ openPolarisDMACore__DOT__fifo__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> openPolarisDMACore__DOT__fifo__DOT__fifo;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VopenPolarisDMACore__Syms* const vlSymsp;

    // CONSTRUCTORS
    VopenPolarisDMACore___024root(VopenPolarisDMACore__Syms* symsp, const char* v__name);
    ~VopenPolarisDMACore___024root();
    VL_UNCOPYABLE(VopenPolarisDMACore___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
