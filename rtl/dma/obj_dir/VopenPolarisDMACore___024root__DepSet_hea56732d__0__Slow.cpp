// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VopenPolarisDMACore.h for the primary calling header

#include "verilated.h"

#include "VopenPolarisDMACore__Syms.h"
#include "VopenPolarisDMACore___024root.h"

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_static(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_static\n"); );
}

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_initial__TOP(VopenPolarisDMACore___024root* vlSelf);

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_initial(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_initial\n"); );
    // Body
    VopenPolarisDMACore___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__dmac_clock_i__0 
        = vlSelf->dmac_clock_i;
}

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_initial__TOP(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->dma_d_ready = 1U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[1U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[2U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[3U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[4U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[5U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[6U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[7U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[8U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[9U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0xaU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0xbU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0xcU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0xdU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0xeU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0xfU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x10U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x11U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x12U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x13U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x14U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x15U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x16U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x17U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x18U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x19U] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x1aU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x1bU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x1cU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x1dU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x1eU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0x1fU] = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__unnamedblk1__DOT__i = 0x20U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr = 0U;
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr = 0U;
}

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_final(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_final\n"); );
}

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_triggers__stl(VopenPolarisDMACore___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__stl(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_stl(VopenPolarisDMACore___024root* vlSelf);

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_settle(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VopenPolarisDMACore___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VopenPolarisDMACore___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("openPolarisDMACore.sv", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VopenPolarisDMACore___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__stl(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VopenPolarisDMACore___024root___stl_sequent__TOP__0(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ openPolarisDMACore__DOT____VdfgTmp_h03a06e2e__0;
    openPolarisDMACore__DOT____VdfgTmp_h03a06e2e__0 = 0;
    // Body
    vlSelf->dmac_busy_o = (0U != (IData)(vlSelf->openPolarisDMACore__DOT__dma_state));
    vlSelf->openPolarisDMACore__DOT__write_fifo = ((IData)(vlSelf->dma_d_valid) 
                                                   & (1U 
                                                      == (IData)(vlSelf->dma_d_opcode)));
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

VL_ATTR_COLD void VopenPolarisDMACore___024root___eval_stl(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VopenPolarisDMACore___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__ico(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__act(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge dmac_clock_i)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__nba(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge dmac_clock_i)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VopenPolarisDMACore___024root___ctor_var_reset(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->dmac_clock_i = VL_RAND_RESET_I(1);
    vlSelf->dmac_reset_i = VL_RAND_RESET_I(1);
    vlSelf->dmac_tx_i = VL_RAND_RESET_I(1);
    vlSelf->dmac_source_address_i = VL_RAND_RESET_I(32);
    vlSelf->dmac_dest_address_i = VL_RAND_RESET_I(32);
    vlSelf->dmac_bytes_tx_i = VL_RAND_RESET_I(32);
    vlSelf->dmac_busy_o = VL_RAND_RESET_I(1);
    vlSelf->dmac_done_o = VL_RAND_RESET_I(1);
    vlSelf->dmac_err_o = VL_RAND_RESET_I(1);
    vlSelf->dma_a_opcode = VL_RAND_RESET_I(3);
    vlSelf->dma_a_param = VL_RAND_RESET_I(3);
    vlSelf->dma_a_size = VL_RAND_RESET_I(4);
    vlSelf->dma_a_address = VL_RAND_RESET_I(32);
    vlSelf->dma_a_mask = VL_RAND_RESET_I(4);
    vlSelf->dma_a_data = VL_RAND_RESET_I(32);
    vlSelf->dma_a_corrupt = VL_RAND_RESET_I(1);
    vlSelf->dma_a_valid = VL_RAND_RESET_I(1);
    vlSelf->dma_a_ready = VL_RAND_RESET_I(1);
    vlSelf->dma_d_opcode = VL_RAND_RESET_I(3);
    vlSelf->dma_d_param = VL_RAND_RESET_I(2);
    vlSelf->dma_d_size = VL_RAND_RESET_I(4);
    vlSelf->dma_d_denied = VL_RAND_RESET_I(1);
    vlSelf->dma_d_data = VL_RAND_RESET_I(32);
    vlSelf->dma_d_corrupt = VL_RAND_RESET_I(1);
    vlSelf->dma_d_valid = VL_RAND_RESET_I(1);
    vlSelf->dma_d_ready = VL_RAND_RESET_I(1);
    vlSelf->openPolarisDMACore__DOT__bytesRemaining = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__write_fifo = VL_RAND_RESET_I(1);
    vlSelf->openPolarisDMACore__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->openPolarisDMACore__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->openPolarisDMACore__DOT__current_source_address = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__current_destination_address = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__dma_state = VL_RAND_RESET_I(2);
    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr = VL_RAND_RESET_I(4);
    vlSelf->openPolarisDMACore__DOT__bytes_0 = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr = VL_RAND_RESET_I(4);
    vlSelf->openPolarisDMACore__DOT__bytes_1 = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder = VL_RAND_RESET_I(4);
    vlSelf->openPolarisDMACore__DOT__bytes_2 = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__min_stage1 = VL_RAND_RESET_I(4);
    vlSelf->openPolarisDMACore__DOT__minimum = VL_RAND_RESET_I(4);
    vlSelf->openPolarisDMACore__DOT__minimum_bytes = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT__byte_count = VL_RAND_RESET_I(8);
    vlSelf->openPolarisDMACore__DOT__count_store = VL_RAND_RESET_I(8);
    vlSelf->openPolarisDMACore__DOT__size_store = VL_RAND_RESET_I(4);
    vlSelf->openPolarisDMACore__DOT__minimum_bytes_r = VL_RAND_RESET_I(32);
    vlSelf->openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr = VL_RAND_RESET_I(6);
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr = VL_RAND_RESET_I(6);
    vlSelf->openPolarisDMACore__DOT__fifo__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__dmac_clock_i__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
