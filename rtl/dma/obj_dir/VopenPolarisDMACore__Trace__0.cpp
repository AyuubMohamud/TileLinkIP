// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VopenPolarisDMACore__Syms.h"


void VopenPolarisDMACore___024root__trace_chg_sub_0(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VopenPolarisDMACore___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_chg_top_0\n"); );
    // Init
    VopenPolarisDMACore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VopenPolarisDMACore___024root*>(voidSelf);
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VopenPolarisDMACore___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VopenPolarisDMACore___024root__trace_chg_sub_0(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(vlSelf->openPolarisDMACore__DOT__bytesRemaining),32);
        bufp->chgBit(oldp+2,(vlSelf->openPolarisDMACore__DOT__full));
        bufp->chgIData(oldp+3,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo
                               [(0x1fU & (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr))]),32);
        bufp->chgBit(oldp+4,(((IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr) 
                              == (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr))));
        bufp->chgIData(oldp+5,(vlSelf->openPolarisDMACore__DOT__current_source_address),32);
        bufp->chgIData(oldp+6,(vlSelf->openPolarisDMACore__DOT__current_destination_address),32);
        bufp->chgCData(oldp+7,(vlSelf->openPolarisDMACore__DOT__dma_state),2);
        bufp->chgCData(oldp+8,(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr),4);
        bufp->chgIData(oldp+9,(vlSelf->openPolarisDMACore__DOT__bytes_0),32);
        bufp->chgCData(oldp+10,(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr),4);
        bufp->chgIData(oldp+11,(vlSelf->openPolarisDMACore__DOT__bytes_1),32);
        bufp->chgCData(oldp+12,(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder),4);
        bufp->chgIData(oldp+13,(vlSelf->openPolarisDMACore__DOT__bytes_2),32);
        bufp->chgCData(oldp+14,(vlSelf->openPolarisDMACore__DOT__min_stage1),4);
        bufp->chgCData(oldp+15,(vlSelf->openPolarisDMACore__DOT__minimum),4);
        bufp->chgIData(oldp+16,(((IData)(vlSelf->openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0)
                                  ? vlSelf->openPolarisDMACore__DOT__bytes_0
                                  : vlSelf->openPolarisDMACore__DOT__bytes_1)),32);
        bufp->chgIData(oldp+17,(vlSelf->openPolarisDMACore__DOT__minimum_bytes),32);
        bufp->chgCData(oldp+18,(vlSelf->openPolarisDMACore__DOT__byte_count),8);
        bufp->chgCData(oldp+19,(vlSelf->openPolarisDMACore__DOT__count_store),8);
        bufp->chgCData(oldp+20,(vlSelf->openPolarisDMACore__DOT__size_store),4);
        bufp->chgIData(oldp+21,(vlSelf->openPolarisDMACore__DOT__minimum_bytes_r),32);
        bufp->chgIData(oldp+22,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0]),32);
        bufp->chgIData(oldp+23,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[1]),32);
        bufp->chgIData(oldp+24,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[2]),32);
        bufp->chgIData(oldp+25,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[3]),32);
        bufp->chgIData(oldp+26,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[4]),32);
        bufp->chgIData(oldp+27,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[5]),32);
        bufp->chgIData(oldp+28,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[6]),32);
        bufp->chgIData(oldp+29,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[7]),32);
        bufp->chgIData(oldp+30,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[8]),32);
        bufp->chgIData(oldp+31,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[9]),32);
        bufp->chgIData(oldp+32,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[10]),32);
        bufp->chgIData(oldp+33,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[11]),32);
        bufp->chgIData(oldp+34,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[12]),32);
        bufp->chgIData(oldp+35,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[13]),32);
        bufp->chgIData(oldp+36,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[14]),32);
        bufp->chgIData(oldp+37,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[15]),32);
        bufp->chgIData(oldp+38,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[16]),32);
        bufp->chgIData(oldp+39,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[17]),32);
        bufp->chgIData(oldp+40,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[18]),32);
        bufp->chgIData(oldp+41,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[19]),32);
        bufp->chgIData(oldp+42,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[20]),32);
        bufp->chgIData(oldp+43,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[21]),32);
        bufp->chgIData(oldp+44,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[22]),32);
        bufp->chgIData(oldp+45,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[23]),32);
        bufp->chgIData(oldp+46,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[24]),32);
        bufp->chgIData(oldp+47,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[25]),32);
        bufp->chgIData(oldp+48,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[26]),32);
        bufp->chgIData(oldp+49,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[27]),32);
        bufp->chgIData(oldp+50,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[28]),32);
        bufp->chgIData(oldp+51,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[29]),32);
        bufp->chgIData(oldp+52,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[30]),32);
        bufp->chgIData(oldp+53,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[31]),32);
        bufp->chgCData(oldp+54,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr),6);
        bufp->chgCData(oldp+55,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr),6);
    }
    bufp->chgBit(oldp+56,(vlSelf->dmac_clock_i));
    bufp->chgBit(oldp+57,(vlSelf->dmac_reset_i));
    bufp->chgBit(oldp+58,(vlSelf->dmac_tx_i));
    bufp->chgIData(oldp+59,(vlSelf->dmac_source_address_i),32);
    bufp->chgIData(oldp+60,(vlSelf->dmac_dest_address_i),32);
    bufp->chgIData(oldp+61,(vlSelf->dmac_bytes_tx_i),32);
    bufp->chgBit(oldp+62,(vlSelf->dmac_busy_o));
    bufp->chgBit(oldp+63,(vlSelf->dmac_done_o));
    bufp->chgBit(oldp+64,(vlSelf->dmac_err_o));
    bufp->chgCData(oldp+65,(vlSelf->dma_a_opcode),3);
    bufp->chgCData(oldp+66,(vlSelf->dma_a_param),3);
    bufp->chgCData(oldp+67,(vlSelf->dma_a_size),4);
    bufp->chgIData(oldp+68,(vlSelf->dma_a_address),32);
    bufp->chgCData(oldp+69,(vlSelf->dma_a_mask),4);
    bufp->chgIData(oldp+70,(vlSelf->dma_a_data),32);
    bufp->chgBit(oldp+71,(vlSelf->dma_a_corrupt));
    bufp->chgBit(oldp+72,(vlSelf->dma_a_valid));
    bufp->chgBit(oldp+73,(vlSelf->dma_a_ready));
    bufp->chgCData(oldp+74,(vlSelf->dma_d_opcode),3);
    bufp->chgCData(oldp+75,(vlSelf->dma_d_param),2);
    bufp->chgCData(oldp+76,(vlSelf->dma_d_size),4);
    bufp->chgBit(oldp+77,(vlSelf->dma_d_denied));
    bufp->chgIData(oldp+78,(vlSelf->dma_d_data),32);
    bufp->chgBit(oldp+79,(vlSelf->dma_d_corrupt));
    bufp->chgBit(oldp+80,(vlSelf->dma_d_valid));
    bufp->chgBit(oldp+81,(vlSelf->dma_d_ready));
    bufp->chgBit(oldp+82,(vlSelf->openPolarisDMACore__DOT__write_fifo));
    bufp->chgBit(oldp+83,(((IData)(vlSelf->dma_a_ready) 
                           & ((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                              != (IData)(vlSelf->openPolarisDMACore__DOT__count_store)))));
}

void VopenPolarisDMACore___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_cleanup\n"); );
    // Init
    VopenPolarisDMACore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VopenPolarisDMACore___024root*>(voidSelf);
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
