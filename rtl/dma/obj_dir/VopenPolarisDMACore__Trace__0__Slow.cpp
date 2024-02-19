// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VopenPolarisDMACore__Syms.h"


VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_init_sub__TOP__0(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+57,"dmac_clock_i", false,-1);
    tracep->declBit(c+58,"dmac_reset_i", false,-1);
    tracep->declBit(c+59,"dmac_tx_i", false,-1);
    tracep->declBus(c+60,"dmac_source_address_i", false,-1, 31,0);
    tracep->declBus(c+61,"dmac_dest_address_i", false,-1, 31,0);
    tracep->declBus(c+62,"dmac_bytes_tx_i", false,-1, 31,0);
    tracep->declBit(c+63,"dmac_busy_o", false,-1);
    tracep->declBit(c+64,"dmac_done_o", false,-1);
    tracep->declBit(c+65,"dmac_err_o", false,-1);
    tracep->declBus(c+66,"dma_a_opcode", false,-1, 2,0);
    tracep->declBus(c+67,"dma_a_param", false,-1, 2,0);
    tracep->declBus(c+68,"dma_a_size", false,-1, 3,0);
    tracep->declBus(c+69,"dma_a_address", false,-1, 31,0);
    tracep->declBus(c+70,"dma_a_mask", false,-1, 3,0);
    tracep->declBus(c+71,"dma_a_data", false,-1, 31,0);
    tracep->declBit(c+72,"dma_a_corrupt", false,-1);
    tracep->declBit(c+73,"dma_a_valid", false,-1);
    tracep->declBit(c+74,"dma_a_ready", false,-1);
    tracep->declBus(c+75,"dma_d_opcode", false,-1, 2,0);
    tracep->declBus(c+76,"dma_d_param", false,-1, 1,0);
    tracep->declBus(c+77,"dma_d_size", false,-1, 3,0);
    tracep->declBit(c+78,"dma_d_denied", false,-1);
    tracep->declBus(c+79,"dma_d_data", false,-1, 31,0);
    tracep->declBit(c+80,"dma_d_corrupt", false,-1);
    tracep->declBit(c+81,"dma_d_valid", false,-1);
    tracep->declBit(c+82,"dma_d_ready", false,-1);
    tracep->pushNamePrefix("openPolarisDMACore ");
    tracep->declBus(c+85,"TL_AW", false,-1, 31,0);
    tracep->declBit(c+57,"dmac_clock_i", false,-1);
    tracep->declBit(c+58,"dmac_reset_i", false,-1);
    tracep->declBit(c+59,"dmac_tx_i", false,-1);
    tracep->declBus(c+60,"dmac_source_address_i", false,-1, 31,0);
    tracep->declBus(c+61,"dmac_dest_address_i", false,-1, 31,0);
    tracep->declBus(c+62,"dmac_bytes_tx_i", false,-1, 31,0);
    tracep->declBit(c+63,"dmac_busy_o", false,-1);
    tracep->declBit(c+64,"dmac_done_o", false,-1);
    tracep->declBit(c+65,"dmac_err_o", false,-1);
    tracep->declBus(c+66,"dma_a_opcode", false,-1, 2,0);
    tracep->declBus(c+67,"dma_a_param", false,-1, 2,0);
    tracep->declBus(c+68,"dma_a_size", false,-1, 3,0);
    tracep->declBus(c+69,"dma_a_address", false,-1, 31,0);
    tracep->declBus(c+70,"dma_a_mask", false,-1, 3,0);
    tracep->declBus(c+71,"dma_a_data", false,-1, 31,0);
    tracep->declBit(c+72,"dma_a_corrupt", false,-1);
    tracep->declBit(c+73,"dma_a_valid", false,-1);
    tracep->declBit(c+74,"dma_a_ready", false,-1);
    tracep->declBus(c+75,"dma_d_opcode", false,-1, 2,0);
    tracep->declBus(c+76,"dma_d_param", false,-1, 1,0);
    tracep->declBus(c+77,"dma_d_size", false,-1, 3,0);
    tracep->declBit(c+78,"dma_d_denied", false,-1);
    tracep->declBus(c+79,"dma_d_data", false,-1, 31,0);
    tracep->declBit(c+80,"dma_d_corrupt", false,-1);
    tracep->declBit(c+81,"dma_d_valid", false,-1);
    tracep->declBit(c+82,"dma_d_ready", false,-1);
    tracep->declBus(c+2,"bytesRemaining", false,-1, 31,0);
    tracep->declBit(c+83,"write_fifo", false,-1);
    tracep->declBit(c+3,"full", false,-1);
    tracep->declBit(c+84,"read_fifo", false,-1);
    tracep->declBus(c+4,"read_data", false,-1, 31,0);
    tracep->declBit(c+5,"empty", false,-1);
    tracep->declBus(c+6,"current_source_address", false,-1, 31,0);
    tracep->declBus(c+7,"current_destination_address", false,-1, 31,0);
    tracep->declBus(c+8,"dma_state", false,-1, 1,0);
    tracep->declBus(c+86,"IDLE", false,-1, 1,0);
    tracep->declBus(c+87,"DMA_READ", false,-1, 1,0);
    tracep->declBus(c+88,"DMA_AWAIT", false,-1, 1,0);
    tracep->declBus(c+89,"DMA_WRITE", false,-1, 1,0);
    tracep->declBus(c+9,"max_burst_size_from_dest_addr", false,-1, 3,0);
    tracep->declBus(c+10,"bytes_0", false,-1, 31,0);
    tracep->declBus(c+11,"max_burst_size_from_src_addr", false,-1, 3,0);
    tracep->declBus(c+12,"bytes_1", false,-1, 31,0);
    tracep->declBus(c+13,"max_burst_size_from_remainder", false,-1, 3,0);
    tracep->declBus(c+14,"bytes_2", false,-1, 31,0);
    tracep->declBus(c+15,"min_stage1", false,-1, 3,0);
    tracep->declBus(c+16,"minimum", false,-1, 3,0);
    tracep->declBus(c+17,"min_stage1_bsize", false,-1, 31,0);
    tracep->declBus(c+18,"minimum_bytes", false,-1, 31,0);
    tracep->declBus(c+19,"byte_count", false,-1, 7,0);
    tracep->declBus(c+20,"count_store", false,-1, 7,0);
    tracep->declBus(c+21,"size_store", false,-1, 3,0);
    tracep->declBus(c+22,"minimum_bytes_r", false,-1, 31,0);
    tracep->pushNamePrefix("fifo ");
    tracep->declBus(c+85,"FW", false,-1, 31,0);
    tracep->declBus(c+85,"DW", false,-1, 31,0);
    tracep->declBit(c+57,"i_clk", false,-1);
    tracep->declBit(c+58,"i_reset", false,-1);
    tracep->declBit(c+83,"i_wr_en", false,-1);
    tracep->declBus(c+79,"i_wr_data", false,-1, 31,0);
    tracep->declBit(c+3,"o_full", false,-1);
    tracep->declBit(c+84,"i_rd", false,-1);
    tracep->declBus(c+4,"o_rd_data", false,-1, 31,0);
    tracep->declBit(c+5,"o_empty", false,-1);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+23+i*1,"fifo", true,(i+0), 31,0);
    }
    tracep->declBus(c+55,"read_ptr", false,-1, 5,0);
    tracep->declBus(c+56,"write_ptr", false,-1, 5,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_init_top(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_init_top\n"); );
    // Body
    VopenPolarisDMACore___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VopenPolarisDMACore___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VopenPolarisDMACore___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_register(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VopenPolarisDMACore___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VopenPolarisDMACore___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VopenPolarisDMACore___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_full_sub_0(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_full_top_0\n"); );
    // Init
    VopenPolarisDMACore___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VopenPolarisDMACore___024root*>(voidSelf);
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VopenPolarisDMACore___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VopenPolarisDMACore___024root__trace_full_sub_0(VopenPolarisDMACore___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->openPolarisDMACore__DOT__bytesRemaining),32);
    bufp->fullBit(oldp+3,(vlSelf->openPolarisDMACore__DOT__full));
    bufp->fullIData(oldp+4,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo
                            [(0x1fU & (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr))]),32);
    bufp->fullBit(oldp+5,(((IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr) 
                           == (IData)(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr))));
    bufp->fullIData(oldp+6,(vlSelf->openPolarisDMACore__DOT__current_source_address),32);
    bufp->fullIData(oldp+7,(vlSelf->openPolarisDMACore__DOT__current_destination_address),32);
    bufp->fullCData(oldp+8,(vlSelf->openPolarisDMACore__DOT__dma_state),2);
    bufp->fullCData(oldp+9,(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_dest_addr),4);
    bufp->fullIData(oldp+10,(vlSelf->openPolarisDMACore__DOT__bytes_0),32);
    bufp->fullCData(oldp+11,(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_src_addr),4);
    bufp->fullIData(oldp+12,(vlSelf->openPolarisDMACore__DOT__bytes_1),32);
    bufp->fullCData(oldp+13,(vlSelf->openPolarisDMACore__DOT__max_burst_size_from_remainder),4);
    bufp->fullIData(oldp+14,(vlSelf->openPolarisDMACore__DOT__bytes_2),32);
    bufp->fullCData(oldp+15,(vlSelf->openPolarisDMACore__DOT__min_stage1),4);
    bufp->fullCData(oldp+16,(vlSelf->openPolarisDMACore__DOT__minimum),4);
    bufp->fullIData(oldp+17,(((IData)(vlSelf->openPolarisDMACore__DOT____VdfgTmp_h70d1c48f__0)
                               ? vlSelf->openPolarisDMACore__DOT__bytes_0
                               : vlSelf->openPolarisDMACore__DOT__bytes_1)),32);
    bufp->fullIData(oldp+18,(vlSelf->openPolarisDMACore__DOT__minimum_bytes),32);
    bufp->fullCData(oldp+19,(vlSelf->openPolarisDMACore__DOT__byte_count),8);
    bufp->fullCData(oldp+20,(vlSelf->openPolarisDMACore__DOT__count_store),8);
    bufp->fullCData(oldp+21,(vlSelf->openPolarisDMACore__DOT__size_store),4);
    bufp->fullIData(oldp+22,(vlSelf->openPolarisDMACore__DOT__minimum_bytes_r),32);
    bufp->fullIData(oldp+23,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[0]),32);
    bufp->fullIData(oldp+24,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[1]),32);
    bufp->fullIData(oldp+25,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[2]),32);
    bufp->fullIData(oldp+26,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[3]),32);
    bufp->fullIData(oldp+27,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[4]),32);
    bufp->fullIData(oldp+28,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[5]),32);
    bufp->fullIData(oldp+29,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[6]),32);
    bufp->fullIData(oldp+30,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[7]),32);
    bufp->fullIData(oldp+31,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[8]),32);
    bufp->fullIData(oldp+32,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[9]),32);
    bufp->fullIData(oldp+33,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[10]),32);
    bufp->fullIData(oldp+34,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[11]),32);
    bufp->fullIData(oldp+35,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[12]),32);
    bufp->fullIData(oldp+36,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[13]),32);
    bufp->fullIData(oldp+37,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[14]),32);
    bufp->fullIData(oldp+38,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[15]),32);
    bufp->fullIData(oldp+39,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[16]),32);
    bufp->fullIData(oldp+40,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[17]),32);
    bufp->fullIData(oldp+41,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[18]),32);
    bufp->fullIData(oldp+42,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[19]),32);
    bufp->fullIData(oldp+43,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[20]),32);
    bufp->fullIData(oldp+44,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[21]),32);
    bufp->fullIData(oldp+45,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[22]),32);
    bufp->fullIData(oldp+46,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[23]),32);
    bufp->fullIData(oldp+47,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[24]),32);
    bufp->fullIData(oldp+48,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[25]),32);
    bufp->fullIData(oldp+49,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[26]),32);
    bufp->fullIData(oldp+50,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[27]),32);
    bufp->fullIData(oldp+51,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[28]),32);
    bufp->fullIData(oldp+52,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[29]),32);
    bufp->fullIData(oldp+53,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[30]),32);
    bufp->fullIData(oldp+54,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__fifo[31]),32);
    bufp->fullCData(oldp+55,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__read_ptr),6);
    bufp->fullCData(oldp+56,(vlSelf->openPolarisDMACore__DOT__fifo__DOT__write_ptr),6);
    bufp->fullBit(oldp+57,(vlSelf->dmac_clock_i));
    bufp->fullBit(oldp+58,(vlSelf->dmac_reset_i));
    bufp->fullBit(oldp+59,(vlSelf->dmac_tx_i));
    bufp->fullIData(oldp+60,(vlSelf->dmac_source_address_i),32);
    bufp->fullIData(oldp+61,(vlSelf->dmac_dest_address_i),32);
    bufp->fullIData(oldp+62,(vlSelf->dmac_bytes_tx_i),32);
    bufp->fullBit(oldp+63,(vlSelf->dmac_busy_o));
    bufp->fullBit(oldp+64,(vlSelf->dmac_done_o));
    bufp->fullBit(oldp+65,(vlSelf->dmac_err_o));
    bufp->fullCData(oldp+66,(vlSelf->dma_a_opcode),3);
    bufp->fullCData(oldp+67,(vlSelf->dma_a_param),3);
    bufp->fullCData(oldp+68,(vlSelf->dma_a_size),4);
    bufp->fullIData(oldp+69,(vlSelf->dma_a_address),32);
    bufp->fullCData(oldp+70,(vlSelf->dma_a_mask),4);
    bufp->fullIData(oldp+71,(vlSelf->dma_a_data),32);
    bufp->fullBit(oldp+72,(vlSelf->dma_a_corrupt));
    bufp->fullBit(oldp+73,(vlSelf->dma_a_valid));
    bufp->fullBit(oldp+74,(vlSelf->dma_a_ready));
    bufp->fullCData(oldp+75,(vlSelf->dma_d_opcode),3);
    bufp->fullCData(oldp+76,(vlSelf->dma_d_param),2);
    bufp->fullCData(oldp+77,(vlSelf->dma_d_size),4);
    bufp->fullBit(oldp+78,(vlSelf->dma_d_denied));
    bufp->fullIData(oldp+79,(vlSelf->dma_d_data),32);
    bufp->fullBit(oldp+80,(vlSelf->dma_d_corrupt));
    bufp->fullBit(oldp+81,(vlSelf->dma_d_valid));
    bufp->fullBit(oldp+82,(vlSelf->dma_d_ready));
    bufp->fullBit(oldp+83,(vlSelf->openPolarisDMACore__DOT__write_fifo));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->dma_a_ready) 
                            & ((IData)(vlSelf->openPolarisDMACore__DOT__byte_count) 
                               != (IData)(vlSelf->openPolarisDMACore__DOT__count_store)))));
    bufp->fullIData(oldp+85,(0x20U),32);
    bufp->fullCData(oldp+86,(0U),2);
    bufp->fullCData(oldp+87,(1U),2);
    bufp->fullCData(oldp+88,(2U),2);
    bufp->fullCData(oldp+89,(3U),2);
}
