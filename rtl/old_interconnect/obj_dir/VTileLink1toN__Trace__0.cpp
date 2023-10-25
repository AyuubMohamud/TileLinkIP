// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTileLink1toN__Syms.h"


void VTileLink1toN___024root__trace_chg_sub_0(VTileLink1toN___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTileLink1toN___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_chg_top_0\n"); );
    // Init
    VTileLink1toN___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTileLink1toN___024root*>(voidSelf);
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTileLink1toN___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTileLink1toN___024root__trace_chg_sub_0(VTileLink1toN___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgWData(oldp+0,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7),83);
        bufp->chgQData(oldp+3,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7),47);
        bufp->chgQData(oldp+5,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7),47);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+7,(vlSelf->TileLink1toN__DOT__master_stalled));
        bufp->chgCData(oldp+8,((7U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                      >> 0x10U))),3);
        bufp->chgCData(oldp+9,((7U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                      >> 0xdU))),3);
        bufp->chgCData(oldp+10,((0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                         >> 9U))),4);
        bufp->chgCData(oldp+11,((0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                         >> 5U))),4);
        bufp->chgIData(oldp+12,(((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                  << 0x1bU) | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                               >> 5U))),32);
        bufp->chgCData(oldp+13,((0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                         >> 1U))),4);
        bufp->chgIData(oldp+14,(((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                  << 0x1fU) | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
                                               >> 1U))),32);
        bufp->chgBit(oldp+15,((1U & vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U])));
        bufp->chgBit(oldp+16,(vlSelf->TileLink1toN__DOT__working_master_a_valid));
        bufp->chgCData(oldp+17,(vlSelf->TileLink1toN__DOT__slave_select),2);
        bufp->chgCData(oldp+18,((((IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3) 
                                  << 1U) | (IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3))),2);
        bufp->chgCData(oldp+19,(vlSelf->TileLink1toN__DOT__working_slave_d_opcode),6);
        bufp->chgCData(oldp+20,(vlSelf->TileLink1toN__DOT__working_slave_d_param),4);
        bufp->chgCData(oldp+21,(vlSelf->TileLink1toN__DOT__working_slave_d_size),8);
        bufp->chgCData(oldp+22,(vlSelf->TileLink1toN__DOT__working_slave_d_source),8);
        bufp->chgCData(oldp+23,(((2U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                                                 >> 0x21U)) 
                                        << 1U)) | (1U 
                                                   & (IData)(
                                                             (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                              >> 0x21U))))),2);
        bufp->chgQData(oldp+24,(vlSelf->TileLink1toN__DOT__working_slave_d_data),64);
        bufp->chgCData(oldp+26,(((2U & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4) 
                                        << 1U)) | (1U 
                                                   & (IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4)))),2);
        bufp->chgCData(oldp+27,(vlSelf->TileLink1toN__DOT__working_slave_d_valid),2);
        bufp->chgBit(oldp+28,(vlSelf->TileLink1toN__DOT__bitscan));
        bufp->chgBit(oldp+29,(vlSelf->TileLink1toN__DOT__once));
        bufp->chgBit(oldp+30,(vlSelf->TileLink1toN__DOT__twoormore));
        bufp->chgBit(oldp+31,(vlSelf->TileLink1toN__DOT__burst));
        bufp->chgCData(oldp+32,((7U & ((1U == (1U & 
                                               ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                    ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                    : 
                                                   (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                        ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_opcode)
                                        : ((2U == ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                   & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                       ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                       : 
                                                      (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                            ? ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_opcode) 
                                               >> 3U)
                                            : 0U)))),3);
        bufp->chgCData(oldp+33,((3U & ((1U == (1U & 
                                               ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                    ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                    : 
                                                   (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                        ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_param)
                                        : ((2U == ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                   & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                       ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                       : 
                                                      (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                            ? ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_param) 
                                               >> 2U)
                                            : 0U)))),2);
        bufp->chgCData(oldp+34,(vlSelf->TileLink1toN__DOT__resp_size),4);
        bufp->chgCData(oldp+35,((0xfU & ((1U == (1U 
                                                 & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                    & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                        ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                        : 
                                                       (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                          ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_source)
                                          : ((2U == 
                                              ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                               & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                   ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                   : 
                                                  (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                              ? ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_source) 
                                                 >> 4U)
                                              : 0U)))),4);
        bufp->chgIData(oldp+36,(((1U == (1U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                               & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                   ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                   : 
                                                  (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                  ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_data)
                                  : ((2U == ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                             & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                 ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                 : 
                                                (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                      ? (IData)((vlSelf->TileLink1toN__DOT__working_slave_d_data 
                                                 >> 0x20U))
                                      : 0U))),32);
        bufp->chgBit(oldp+37,(vlSelf->TileLink1toN__DOT__resp_denied));
        bufp->chgBit(oldp+38,(vlSelf->TileLink1toN__DOT__resp_corrupt));
        bufp->chgSData(oldp+39,(vlSelf->TileLink1toN__DOT__number_to_write),12);
        bufp->chgWData(oldp+40,(vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4),83);
        bufp->chgBit(oldp+43,(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__hold_data));
        bufp->chgBit(oldp+44,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3));
        bufp->chgQData(oldp+45,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4),47);
        bufp->chgBit(oldp+47,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5));
        bufp->chgBit(oldp+48,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data));
        bufp->chgBit(oldp+49,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3));
        bufp->chgQData(oldp+50,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4),47);
        bufp->chgBit(oldp+52,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5));
        bufp->chgBit(oldp+53,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data));
        bufp->chgIData(oldp+54,(vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n),32);
        bufp->chgIData(oldp+55,(vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+56,(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld));
        bufp->chgCData(oldp+57,((((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld) 
                                  << 1U) | (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld))),2);
        bufp->chgCData(oldp+58,(vlSelf->TileLink1toN__DOT__block),2);
        bufp->chgBit(oldp+59,(vlSelf->TileLink1toN__DOT__lock));
        bufp->chgCData(oldp+60,(vlSelf->TileLink1toN__DOT__locked_slave_select),2);
        bufp->chgSData(oldp+61,(vlSelf->TileLink1toN__DOT__burst_counters),12);
        bufp->chgBit(oldp+62,(vlSelf->TileLink1toN__DOT__burst_ending));
        bufp->chgWData(oldp+63,(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data),83);
        bufp->chgBit(oldp+66,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld));
        bufp->chgQData(oldp+67,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data),47);
        bufp->chgBit(oldp+69,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld));
        bufp->chgQData(oldp+70,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data),47);
        bufp->chgIData(oldp+72,(vlSelf->TileLink1toN__DOT__unnamedblk3__DOT__x),32);
        bufp->chgIData(oldp+73,(vlSelf->TileLink1toN__DOT__unnamedblk4__DOT__n),32);
    }
    bufp->chgBit(oldp+74,(vlSelf->tilelink_clock_i));
    bufp->chgBit(oldp+75,(vlSelf->tilelink_reset_i));
    bufp->chgCData(oldp+76,(vlSelf->master_a_opcode),3);
    bufp->chgCData(oldp+77,(vlSelf->master_a_param),3);
    bufp->chgCData(oldp+78,(vlSelf->master_a_size),4);
    bufp->chgCData(oldp+79,(vlSelf->master_a_source),4);
    bufp->chgIData(oldp+80,(vlSelf->master_a_address),32);
    bufp->chgCData(oldp+81,(vlSelf->master_a_mask),4);
    bufp->chgIData(oldp+82,(vlSelf->master_a_data),32);
    bufp->chgBit(oldp+83,(vlSelf->master_a_corrupt));
    bufp->chgBit(oldp+84,(vlSelf->master_a_valid));
    bufp->chgBit(oldp+85,(vlSelf->master_a_ready));
    bufp->chgCData(oldp+86,(vlSelf->master_d_opcode),3);
    bufp->chgCData(oldp+87,(vlSelf->master_d_param),2);
    bufp->chgCData(oldp+88,(vlSelf->master_d_size),4);
    bufp->chgCData(oldp+89,(vlSelf->master_d_source),4);
    bufp->chgBit(oldp+90,(vlSelf->master_d_denied));
    bufp->chgIData(oldp+91,(vlSelf->master_d_data),32);
    bufp->chgBit(oldp+92,(vlSelf->master_d_corrupt));
    bufp->chgBit(oldp+93,(vlSelf->master_d_valid));
    bufp->chgBit(oldp+94,(vlSelf->master_d_ready));
    bufp->chgCData(oldp+95,(vlSelf->slave_a_opcode),6);
    bufp->chgCData(oldp+96,(vlSelf->slave_a_param),6);
    bufp->chgCData(oldp+97,(vlSelf->slave_a_size),8);
    bufp->chgCData(oldp+98,(vlSelf->slave_a_source),8);
    bufp->chgQData(oldp+99,(vlSelf->slave_a_address),64);
    bufp->chgCData(oldp+101,(vlSelf->slave_a_mask),8);
    bufp->chgQData(oldp+102,(vlSelf->slave_a_data),64);
    bufp->chgCData(oldp+104,(vlSelf->slave_a_corrupt),2);
    bufp->chgCData(oldp+105,(vlSelf->slave_a_valid),2);
    bufp->chgCData(oldp+106,(vlSelf->slave_a_ready),2);
    bufp->chgCData(oldp+107,(vlSelf->slave_d_opcode),6);
    bufp->chgCData(oldp+108,(vlSelf->slave_d_param),4);
    bufp->chgCData(oldp+109,(vlSelf->slave_d_size),8);
    bufp->chgCData(oldp+110,(vlSelf->slave_d_source),8);
    bufp->chgCData(oldp+111,(vlSelf->slave_d_denied),2);
    bufp->chgQData(oldp+112,(vlSelf->slave_d_data),64);
    bufp->chgCData(oldp+114,(vlSelf->slave_d_corrupt),2);
    bufp->chgCData(oldp+115,(vlSelf->slave_d_valid),2);
    bufp->chgCData(oldp+116,(vlSelf->slave_d_ready),2);
    bufp->chgBit(oldp+117,((1U & (IData)(vlSelf->slave_d_valid))));
    bufp->chgBit(oldp+118,((1U & ((IData)(vlSelf->slave_d_valid) 
                                  >> 1U))));
}

void VTileLink1toN___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_cleanup\n"); );
    // Init
    VTileLink1toN___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTileLink1toN___024root*>(voidSelf);
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
