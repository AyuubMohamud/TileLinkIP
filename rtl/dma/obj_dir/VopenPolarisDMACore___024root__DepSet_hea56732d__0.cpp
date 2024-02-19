// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VopenPolarisDMACore.h for the primary calling header

#include "verilated.h"

#include "VopenPolarisDMACore__Syms.h"
#include "VopenPolarisDMACore___024root.h"

VL_INLINE_OPT void VopenPolarisDMACore___024root___ico_sequent__TOP__0(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->openPolarisDMACore__DOT__write_fifo = ((IData)(vlSelf->dma_d_valid) 
                                                   & (1U 
                                                      == (IData)(vlSelf->dma_d_opcode)));
}

void VopenPolarisDMACore___024root___eval_ico(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VopenPolarisDMACore___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VopenPolarisDMACore___024root___eval_act(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_act\n"); );
}

VL_INLINE_OPT void VopenPolarisDMACore___024root___nba_sequent__TOP__0(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ openPolarisDMACore__DOT____VdfgTmp_h03a06e2e__0;
    openPolarisDMACore__DOT____VdfgTmp_h03a06e2e__0 = 0;
    CData/*7:0*/ __Vdly__openPolarisDMACore__DOT__byte_count;
    __Vdly__openPolarisDMACore__DOT__byte_count = 0;
    CData/*0:0*/ __Vdly__dma_a_valid;
    __Vdly__dma_a_valid = 0;
    CData/*3:0*/ __Vdly__dma_a_size;
    __Vdly__dma_a_size = 0;
    IData/*31:0*/ __Vdly__openPolarisDMACore__DOT__bytesRemaining;
    __Vdly__openPolarisDMACore__DOT__bytesRemaining = 0;
    CData/*1:0*/ __Vdly__openPolarisDMACore__DOT__dma_state;
    __Vdly__openPolarisDMACore__DOT__dma_state = 0;
    CData/*5:0*/ __Vdly__openPolarisDMACore__DOT__fifo__DOT__write_ptr;
    __Vdly__openPolarisDMACore__DOT__fifo__DOT__write_ptr = 0;
    CData/*5:0*/ __Vdly__openPolarisDMACore__DOT__fifo__DOT__read_ptr;
    __Vdly__openPolarisDMACore__DOT__fifo__DOT__read_ptr = 0;
    CData/*4:0*/ __Vdlyvdim0__openPolarisDMACore__DOT__fifo__DOT__fifo__v0;
    __Vdlyvdim0__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 = 0;
    IData/*31:0*/ __Vdlyvval__openPolarisDMACore__DOT__fifo__DOT__fifo__v0;
    __Vdlyvval__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__openPolarisDMACore__DOT__fifo__DOT__fifo__v0;
    __Vdlyvset__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 = 0;
    // Body
    __Vdly__openPolarisDMACore__DOT__fifo__DOT__write_ptr 
        = vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr;
    __Vdlyvset__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 = 0U;
    __Vdly__openPolarisDMACore__DOT__fifo__DOT__read_ptr 
        = vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr;
    __Vdly__dma_a_size = vlSelf->dma_a_size;
    __Vdly__dma_a_valid = vlSelf->dma_a_valid;
    __Vdly__openPolarisDMACore__DOT__byte_count = vlSelf->openPolarisDMACore__DOT__byte_count;
    __Vdly__openPolarisDMACore__DOT__dma_state = vlSelf->openPolarisDMACore__DOT__dma_state;
    __Vdly__openPolarisDMACore__DOT__bytesRemaining 
        = vlSelf->openPolarisDMACore__DOT__bytesRemaining;
    if (vlSelf->dmac_reset_i) {
        __Vdly__openPolarisDMACore__DOT__fifo__DOT__write_ptr = 0U;
        __Vdly__openPolarisDMACore__DOT__fifo__DOT__read_ptr = 0U;
    }
    if ((((~ (IData)(vlSelf->dmac_reset_i)) & (IData)(vlSelf->openPolarisDMACore__DOT__write_fifo)) 
         & (~ (IData)(vlSelf->openPolarisDMACore__DOT__full)))) {
        __Vdly__openPolarisDMACore__DOT__fifo__DOT__write_ptr 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr)));
        __Vdlyvval__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 
            = vlSelf->dma_d_data;
        __Vdlyvset__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 = 1U;
        __Vdlyvdim0__openPolarisDMACore__DOT__fifo__DOT__fifo__v0 
            = (0x1fU & (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr));
    }
    if ((((~ (IData)(vlSelf->dmac_reset_i)) & ((IData)(vlSelf->dma_a_ready) 
                                               & ((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                                                  != (IData)(vlSelf->openPolarisDMACore__DOT__count_store)))) 
         & (~ (IData)(vlSelf->openPolarisDMACore__DOT__empty)))) {
        __Vdly__openPolarisDMACore__DOT__fifo__DOT__read_ptr 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr)));
    }
    if ((2U & (IData)(vlSelf->openPolarisDMACore__DOT__dma_state))) {
        if ((1U & (IData)(vlSelf->openPolarisDMACore__DOT__dma_state))) {
            if (((IData)(vlSelf->dma_a_ready) & ((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                                                 != (IData)(vlSelf->openPolarisDMACore__DOT__count_store)))) {
                __Vdly__openPolarisDMACore__DOT__byte_count 
                    = (0xffU & ((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                                + ((2U <= (IData)(vlSelf->dma_a_size))
                                    ? 4U : ((1U == (IData)(vlSelf->dma_a_size))
                                             ? 2U : 1U))));
                vlSelf->dma_a_address = vlSelf->openPolarisDMACore__DOT__current_destination_address;
                vlSelf->dma_a_corrupt = 0U;
                vlSelf->dma_a_data = vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo
                    [(0x1fU & (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr))];
                vlSelf->dma_a_mask = 0xfU;
                vlSelf->dma_a_opcode = 0U;
                vlSelf->dma_a_param = 0U;
                __Vdly__dma_a_valid = 1U;
                __Vdly__dma_a_size = vlSelf->openPolarisDMACore__DOT__size_store;
            } else if (((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                        == (IData)(vlSelf->openPolarisDMACore__DOT__count_store))) {
                __Vdly__dma_a_valid = ((IData)(vlSelf->dma_a_ready)
                                        ? 0U : (1U 
                                                & (IData)(vlSelf->dma_a_valid)));
                if (((IData)(vlSelf->dma_d_valid) & 
                     (0U == (IData)(vlSelf->dma_d_opcode)))) {
                    vlSelf->openPolarisDMACore__DOT__current_destination_address 
                        = (vlSelf->openPolarisDMACore__DOT__current_destination_address 
                           + vlSelf->openPolarisDMACore__DOT__minimum_bytes_r);
                    __Vdly__openPolarisDMACore__DOT__bytesRemaining 
                        = (vlSelf->openPolarisDMACore__DOT__bytesRemaining 
                           - vlSelf->openPolarisDMACore__DOT__minimum_bytes_r);
                    __Vdly__openPolarisDMACore__DOT__dma_state = 1U;
                }
            }
        } else {
            __Vdly__dma_a_valid = ((IData)(vlSelf->dma_a_ready)
                                    ? 0U : (1U & (IData)(vlSelf->dma_a_valid)));
            if (((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                 == (IData)(vlSelf->openPolarisDMACore__DOT__count_store))) {
                __Vdly__openPolarisDMACore__DOT__byte_count = 0U;
                __Vdly__openPolarisDMACore__DOT__dma_state = 3U;
            } else if (vlSelf->dma_d_valid) {
                __Vdly__openPolarisDMACore__DOT__byte_count 
                    = (0xffU & ((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                                + ((2U <= (IData)(vlSelf->dma_a_size))
                                    ? 4U : ((1U == (IData)(vlSelf->dma_a_size))
                                             ? 2U : 1U))));
            }
        }
    } else if ((1U & (IData)(vlSelf->openPolarisDMACore__DOT__dma_state))) {
        if (((IData)(vlSelf->dma_a_ready) & (0U != vlSelf->openPolarisDMACore__DOT__bytesRemaining))) {
            __Vdly__openPolarisDMACore__DOT__byte_count = 0U;
            vlSelf->dma_a_address = vlSelf->openPolarisDMACore__DOT__current_source_address;
            vlSelf->dma_a_corrupt = 0U;
            vlSelf->dma_a_opcode = 4U;
            vlSelf->dma_a_param = 0U;
            vlSelf->dma_a_data = 0U;
            vlSelf->dma_a_mask = 0U;
            __Vdly__dma_a_size = vlSelf->openPolarisDMACore__DOT__minimum;
            __Vdly__dma_a_valid = 1U;
            __Vdly__openPolarisDMACore__DOT__dma_state = 2U;
            vlSelf->openPolarisDMACore__DOT__count_store 
                = (0xffU & vlSelf->openPolarisDMACore__DOT__minimum_bytes);
            vlSelf->openPolarisDMACore__DOT__size_store 
                = vlSelf->openPolarisDMACore__DOT__minimum;
            vlSelf->openPolarisDMACore__DOT__minimum_bytes_r 
                = vlSelf->openPolarisDMACore__DOT__minimum_bytes;
            vlSelf->openPolarisDMACore__DOT__current_source_address 
                = (vlSelf->openPolarisDMACore__DOT__current_source_address 
                   + vlSelf->openPolarisDMACore__DOT__minimum_bytes);
        } else if ((0U == vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->dmac_done_o = 1U;
            vlSelf->dmac_err_o = 0U;
            __Vdly__openPolarisDMACore__DOT__dma_state = 0U;
        }
    } else if (vlSelf->dmac_tx_i) {
        __Vdly__openPolarisDMACore__DOT__bytesRemaining 
            = vlSelf->dmac_bytes_tx_i;
        vlSelf->openPolarisDMACore__DOT__current_source_address 
            = vlSelf->dmac_source_address_i;
        vlSelf->openPolarisDMACore__DOT__current_destination_address 
            = vlSelf->dmac_dest_address_i;
        __Vdly__openPolarisDMACore__DOT__dma_state = 1U;
    }
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr 
        = __Vdly__openPolarisDMACore__DOT__fifo__DOT__write_ptr;
    vlSelf->openPolarisDMACore__DOT__byte_count = __Vdly__openPolarisDMACore__DOT__byte_count;
    vlSelf->dma_a_valid = __Vdly__dma_a_valid;
    vlSelf->dma_a_size = __Vdly__dma_a_size;
    if (__Vdlyvset__openPolarisDMACore__DOT__fifo__DOT__fifo__v0) {
        vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[__Vdlyvdim0__openPolarisDMACore__DOT__fifo__DOT__fifo__v0] 
            = __Vdlyvval__openPolarisDMACore__DOT__fifo__DOT__fifo__v0;
    }
    vlSelf->openPolarisDMACore__DOT__dma_state = __Vdly__openPolarisDMACore__DOT__dma_state;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr 
        = __Vdly__openPolarisDMACore__DOT__fifo__DOT__read_ptr;
    vlSelf->openPolarisDMACore__DOT__bytesRemaining 
        = __Vdly__openPolarisDMACore__DOT__bytesRemaining;
    vlSelf->dmac_busy_o = (0U != (IData)(vlSelf->openPolarisDMACore__DOT__dma_state));
    vlSelf->openPolarisDMACore__DOT__full = (((1U & 
                                               ((IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr) 
                                                >> 5U)) 
                                              != (1U 
                                                  & ((IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr) 
                                                     >> 5U))) 
                                             & ((0x1fU 
                                                 & (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr)) 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr))));
    vlSelf->openPolarisDMACore__DOT__empty = ((IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr) 
                                              == (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr));
    if ((0x40U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        if ((0x20U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((0x10U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                            } else {
                                vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                            }
                        } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                        } else {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                        }
                    } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                        } else {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                        }
                    } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
                    }
                } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                        } else {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                        }
                    } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                    }
                } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x10U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 4U;
                }
            } else if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                        } else {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                        }
                    } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                    }
                } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
                }
            } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                }
            } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x20U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 5U;
            }
        } else if ((0x10U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                        } else {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                        }
                    } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                    }
                } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
                }
            } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                }
            } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x10U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 4U;
            }
        } else if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                }
            } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
            }
        } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
            }
        } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
            }
        } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
        } else {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x40U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 6U;
        }
    } else if ((0x20U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        if ((0x10U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                        } else {
                            vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                        }
                    } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                    }
                } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
                }
            } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                }
            } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x10U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 4U;
            }
        } else if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                }
            } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
            }
        } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
            }
        } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
            }
        } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
        } else {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x20U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 5U;
        }
    } else if ((0x10U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                    } else {
                        vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                    }
                } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
                }
            } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
            }
        } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
            }
        } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
            }
        } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
        } else {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x10U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 4U;
        }
    } else if ((8U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
                } else {
                    vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
                }
            } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
            }
        } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
            }
        } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
        } else {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 8U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 3U;
        }
    } else if ((4U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
            } else {
                vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
                vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
            }
        } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
        } else {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 4U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 2U;
        }
    } else if ((2U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
        } else {
            vlSelf->openPolarisDMACore__DOT__bytes_2 = 2U;
            vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 1U;
        }
    } else if ((1U & vlSelf->openPolarisDMACore__DOT__bytesRemaining)) {
        vlSelf->openPolarisDMACore__DOT__bytes_2 = 1U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 0U;
    } else {
        vlSelf->openPolarisDMACore__DOT__bytes_2 = 0x80U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = 7U;
    }
    if ((1U == (1U & vlSelf->openPolarisDMACore__DOT__current_destination_address))) {
        vlSelf->openPolarisDMACore__DOT__bytes_0 = 1U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr = 0U;
    } else if ((2U == (3U & vlSelf->openPolarisDMACore__DOT__current_destination_address))) {
        vlSelf->openPolarisDMACore__DOT__bytes_0 = 2U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr = 1U;
    } else if ((4U == (7U & vlSelf->openPolarisDMACore__DOT__current_destination_address))) {
        vlSelf->openPolarisDMACore__DOT__bytes_0 = 4U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr = 2U;
    } else {
        vlSelf->openPolarisDMACore__DOT__bytes_0 = 0x80U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr = 7U;
    }
    if ((1U == (1U & vlSelf->openPolarisDMACore__DOT__current_source_address))) {
        vlSelf->openPolarisDMACore__DOT__bytes_1 = 1U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr = 0U;
    } else if ((2U == (3U & vlSelf->openPolarisDMACore__DOT__current_source_address))) {
        vlSelf->openPolarisDMACore__DOT__bytes_1 = 2U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr = 1U;
    } else {
        vlSelf->openPolarisDMACore__DOT__bytes_1 = 0x80U;
        vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr = 7U;
    }
    vlSelf->openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0 
        = ((IData)(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr) 
           < (IData)(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr));
    vlSelf->openPolarisDMACore__DOT__min_stage1 = ((IData)(vlSelf->openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0)
                                                    ? (IData)(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr)
                                                    : (IData)(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr));
    openPolarisDMACore__DOT____VdfgTmp_h03a06e2e__0 
        = ((IData)(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder) 
           < (IData)(vlSelf->openPolarisDMACore__DOT__min_stage1));
    if (openPolarisDMACore__DOT____VdfgTmp_h03a06e2e__0) {
        vlSelf->openPolarisDMACore__DOT__minimum = vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder;
        vlSelf->openPolarisDMACore__DOT__minimum_bytes 
            = vlSelf->openPolarisDMACore__DOT__bytes_2;
    } else {
        vlSelf->openPolarisDMACore__DOT__minimum = vlSelf->openPolarisDMACore__DOT__min_stage1;
        vlSelf->openPolarisDMACore__DOT__minimum_bytes 
            = ((IData)(vlSelf->openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0)
                ? vlSelf->openPolarisDMACore__DOT__bytes_0
                : vlSelf->openPolarisDMACore__DOT__bytes_1);
    }
}

void VopenPolarisDMACore___024root___eval_nba(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VopenPolarisDMACore___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VopenPolarisDMACore___024root___eval_triggers__ico(VopenPolarisDMACore___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__ico(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG
void VopenPolarisDMACore___024root___eval_triggers__act(VopenPolarisDMACore___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__act(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__nba(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG

void VopenPolarisDMACore___024root___eval(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VopenPolarisDMACore___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VopenPolarisDMACore___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("openPolarisDMACore.sv", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VopenPolarisDMACore___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VopenPolarisDMACore___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VopenPolarisDMACore___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("openPolarisDMACore.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VopenPolarisDMACore___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VopenPolarisDMACore___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("openPolarisDMACore.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VopenPolarisDMACore___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VopenPolarisDMACore___024root___eval_debug_assertions(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->dmac_clock_i & 0xfeU))) {
        Verilated::overWidthError("dmac_clock_i");}
    if (VL_UNLIKELY((vlSelf->dmac_reset_i & 0xfeU))) {
        Verilated::overWidthError("dmac_reset_i");}
    if (VL_UNLIKELY((vlSelf->dmac_tx_i & 0xfeU))) {
        Verilated::overWidthError("dmac_tx_i");}
    if (VL_UNLIKELY((vlSelf->dma_a_ready & 0xfeU))) {
        Verilated::overWidthError("dma_a_ready");}
    if (VL_UNLIKELY((vlSelf->dma_d_opcode & 0xf8U))) {
        Verilated::overWidthError("dma_d_opcode");}
    if (VL_UNLIKELY((vlSelf->dma_d_param & 0xfcU))) {
        Verilated::overWidthError("dma_d_param");}
    if (VL_UNLIKELY((vlSelf->dma_d_size & 0xf0U))) {
        Verilated::overWidthError("dma_d_size");}
    if (VL_UNLIKELY((vlSelf->dma_d_denied & 0xfeU))) {
        Verilated::overWidthError("dma_d_denied");}
    if (VL_UNLIKELY((vlSelf->dma_d_corrupt & 0xfeU))) {
        Verilated::overWidthError("dma_d_corrupt");}
    if (VL_UNLIKELY((vlSelf->dma_d_valid & 0xfeU))) {
        Verilated::overWidthError("dma_d_valid");}
}
#endif  // VL_DEBUG
