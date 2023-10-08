// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTileLink1toN__Syms.h"


VL_ATTR_COLD void VTileLink1toN___024root__trace_init_sub__TOP__0(VTileLink1toN___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+75,"tilelink_clock_i", false,-1);
    tracep->declBit(c+76,"tilelink_reset_i", false,-1);
    tracep->declBus(c+77,"master_a_opcode", false,-1, 2,0);
    tracep->declBus(c+78,"master_a_param", false,-1, 2,0);
    tracep->declBus(c+79,"master_a_size", false,-1, 3,0);
    tracep->declBus(c+80,"master_a_source", false,-1, 3,0);
    tracep->declBus(c+81,"master_a_address", false,-1, 31,0);
    tracep->declBus(c+82,"master_a_mask", false,-1, 3,0);
    tracep->declBus(c+83,"master_a_data", false,-1, 31,0);
    tracep->declBit(c+84,"master_a_corrupt", false,-1);
    tracep->declBit(c+85,"master_a_valid", false,-1);
    tracep->declBit(c+86,"master_a_ready", false,-1);
    tracep->declBus(c+87,"master_d_opcode", false,-1, 2,0);
    tracep->declBus(c+88,"master_d_param", false,-1, 1,0);
    tracep->declBus(c+89,"master_d_size", false,-1, 3,0);
    tracep->declBus(c+90,"master_d_source", false,-1, 3,0);
    tracep->declBit(c+91,"master_d_denied", false,-1);
    tracep->declBus(c+92,"master_d_data", false,-1, 31,0);
    tracep->declBit(c+93,"master_d_corrupt", false,-1);
    tracep->declBit(c+94,"master_d_valid", false,-1);
    tracep->declBit(c+95,"master_d_ready", false,-1);
    tracep->declBus(c+96,"slave_a_opcode", false,-1, 5,0);
    tracep->declBus(c+97,"slave_a_param", false,-1, 5,0);
    tracep->declBus(c+98,"slave_a_size", false,-1, 7,0);
    tracep->declBus(c+99,"slave_a_source", false,-1, 7,0);
    tracep->declQuad(c+100,"slave_a_address", false,-1, 63,0);
    tracep->declBus(c+102,"slave_a_mask", false,-1, 7,0);
    tracep->declQuad(c+103,"slave_a_data", false,-1, 63,0);
    tracep->declBus(c+105,"slave_a_corrupt", false,-1, 1,0);
    tracep->declBus(c+106,"slave_a_valid", false,-1, 1,0);
    tracep->declBus(c+107,"slave_a_ready", false,-1, 1,0);
    tracep->declBus(c+108,"slave_d_opcode", false,-1, 5,0);
    tracep->declBus(c+109,"slave_d_param", false,-1, 3,0);
    tracep->declBus(c+110,"slave_d_size", false,-1, 7,0);
    tracep->declBus(c+111,"slave_d_source", false,-1, 7,0);
    tracep->declBus(c+112,"slave_d_denied", false,-1, 1,0);
    tracep->declQuad(c+113,"slave_d_data", false,-1, 63,0);
    tracep->declBus(c+115,"slave_d_corrupt", false,-1, 1,0);
    tracep->declBus(c+116,"slave_d_valid", false,-1, 1,0);
    tracep->declBus(c+117,"slave_d_ready", false,-1, 1,0);
    tracep->pushNamePrefix("TileLink1toN ");
    tracep->declQuad(c+120,"slave_addresses", false,-1, 63,0);
    tracep->declQuad(c+122,"slave_end_addresses", false,-1, 63,0);
    tracep->declBit(c+75,"tilelink_clock_i", false,-1);
    tracep->declBit(c+76,"tilelink_reset_i", false,-1);
    tracep->declBus(c+77,"master_a_opcode", false,-1, 2,0);
    tracep->declBus(c+78,"master_a_param", false,-1, 2,0);
    tracep->declBus(c+79,"master_a_size", false,-1, 3,0);
    tracep->declBus(c+80,"master_a_source", false,-1, 3,0);
    tracep->declBus(c+81,"master_a_address", false,-1, 31,0);
    tracep->declBus(c+82,"master_a_mask", false,-1, 3,0);
    tracep->declBus(c+83,"master_a_data", false,-1, 31,0);
    tracep->declBit(c+84,"master_a_corrupt", false,-1);
    tracep->declBit(c+85,"master_a_valid", false,-1);
    tracep->declBit(c+86,"master_a_ready", false,-1);
    tracep->declBus(c+87,"master_d_opcode", false,-1, 2,0);
    tracep->declBus(c+88,"master_d_param", false,-1, 1,0);
    tracep->declBus(c+89,"master_d_size", false,-1, 3,0);
    tracep->declBus(c+90,"master_d_source", false,-1, 3,0);
    tracep->declBit(c+91,"master_d_denied", false,-1);
    tracep->declBus(c+92,"master_d_data", false,-1, 31,0);
    tracep->declBit(c+93,"master_d_corrupt", false,-1);
    tracep->declBit(c+94,"master_d_valid", false,-1);
    tracep->declBit(c+95,"master_d_ready", false,-1);
    tracep->declBus(c+96,"slave_a_opcode", false,-1, 5,0);
    tracep->declBus(c+97,"slave_a_param", false,-1, 5,0);
    tracep->declBus(c+98,"slave_a_size", false,-1, 7,0);
    tracep->declBus(c+99,"slave_a_source", false,-1, 7,0);
    tracep->declQuad(c+100,"slave_a_address", false,-1, 63,0);
    tracep->declBus(c+102,"slave_a_mask", false,-1, 7,0);
    tracep->declQuad(c+103,"slave_a_data", false,-1, 63,0);
    tracep->declBus(c+105,"slave_a_corrupt", false,-1, 1,0);
    tracep->declBus(c+106,"slave_a_valid", false,-1, 1,0);
    tracep->declBus(c+107,"slave_a_ready", false,-1, 1,0);
    tracep->declBus(c+108,"slave_d_opcode", false,-1, 5,0);
    tracep->declBus(c+109,"slave_d_param", false,-1, 3,0);
    tracep->declBus(c+110,"slave_d_size", false,-1, 7,0);
    tracep->declBus(c+111,"slave_d_source", false,-1, 7,0);
    tracep->declBus(c+112,"slave_d_denied", false,-1, 1,0);
    tracep->declQuad(c+113,"slave_d_data", false,-1, 63,0);
    tracep->declBus(c+115,"slave_d_corrupt", false,-1, 1,0);
    tracep->declBus(c+116,"slave_d_valid", false,-1, 1,0);
    tracep->declBus(c+117,"slave_d_ready", false,-1, 1,0);
    tracep->declBit(c+8,"master_stalled", false,-1);
    tracep->declBus(c+9,"working_master_a_opcode", false,-1, 2,0);
    tracep->declBus(c+10,"working_master_a_param", false,-1, 2,0);
    tracep->declBus(c+11,"working_master_a_size", false,-1, 3,0);
    tracep->declBus(c+12,"working_master_a_source", false,-1, 3,0);
    tracep->declBus(c+13,"working_master_a_address", false,-1, 31,0);
    tracep->declBus(c+14,"working_master_a_mask", false,-1, 3,0);
    tracep->declBus(c+15,"working_master_a_data", false,-1, 31,0);
    tracep->declBit(c+16,"working_master_a_corrupt", false,-1);
    tracep->declBit(c+17,"working_master_a_valid", false,-1);
    tracep->declBit(c+57,"busy", false,-1);
    tracep->declBus(c+18,"slave_select", false,-1, 1,0);
    tracep->declBus(c+19,"slaveResponseStalled", false,-1, 1,0);
    tracep->declBus(c+20,"working_slave_d_opcode", false,-1, 5,0);
    tracep->declBus(c+21,"working_slave_d_param", false,-1, 3,0);
    tracep->declBus(c+22,"working_slave_d_size", false,-1, 7,0);
    tracep->declBus(c+23,"working_slave_d_source", false,-1, 7,0);
    tracep->declBus(c+24,"working_slave_d_denied", false,-1, 1,0);
    tracep->declQuad(c+25,"working_slave_d_data", false,-1, 63,0);
    tracep->declBus(c+27,"working_slave_d_corrupt", false,-1, 1,0);
    tracep->declBus(c+28,"working_slave_d_valid", false,-1, 1,0);
    tracep->declBus(c+58,"working_slave_d_busy", false,-1, 1,0);
    tracep->declBus(c+59,"block", false,-1, 1,0);
    tracep->declBit(c+60,"lock", false,-1);
    tracep->declBus(c+61,"locked_slave_select", false,-1, 1,0);
    tracep->declBus(c+62,"burst_counters", false,-1, 11,0);
    tracep->declBus(c+29,"bitscan", false,-1, 0,0);
    tracep->declBit(c+30,"once", false,-1);
    tracep->declBit(c+31,"twoormore", false,-1);
    tracep->declBit(c+32,"burst", false,-1);
    tracep->declBit(c+63,"burst_ending", false,-1);
    tracep->declBus(c+33,"resp_opcode", false,-1, 2,0);
    tracep->declBus(c+34,"resp_param", false,-1, 1,0);
    tracep->declBus(c+35,"resp_size", false,-1, 3,0);
    tracep->declBus(c+36,"resp_id", false,-1, 3,0);
    tracep->declBus(c+37,"resp_data", false,-1, 31,0);
    tracep->declBit(c+38,"resp_denied", false,-1);
    tracep->declBit(c+39,"resp_corrupt", false,-1);
    tracep->declBus(c+40,"number_to_write", false,-1, 11,0);
    tracep->pushNamePrefix("address_decode ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("skidbuffer ");
    tracep->declBus(c+124,"DW", false,-1, 31,0);
    tracep->declBit(c+75,"clk_i", false,-1);
    tracep->declBit(c+76,"reset_i", false,-1);
    tracep->declBit(c+8,"combinational_busy_i", false,-1);
    tracep->declArray(c+41,"cycle_data_o", false,-1, 82,0);
    tracep->declBit(c+17,"cycle_vld_o", false,-1);
    tracep->declBit(c+57,"registered_busy_o", false,-1);
    tracep->declArray(c+1,"registered_data_i", false,-1, 82,0);
    tracep->declBit(c+85,"registered_vld_i", false,-1);
    tracep->declArray(c+64,"held_data", false,-1, 82,0);
    tracep->declBit(c+57,"held_vld", false,-1);
    tracep->declBit(c+44,"hold_data", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("skidbufferInstantiation ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("skidbufferInstantiation[0] ");
    tracep->pushNamePrefix("slave_skidbuffer ");
    tracep->declBus(c+125,"DW", false,-1, 31,0);
    tracep->declBit(c+75,"clk_i", false,-1);
    tracep->declBit(c+76,"reset_i", false,-1);
    tracep->declBit(c+45,"combinational_busy_i", false,-1);
    tracep->declQuad(c+46,"cycle_data_o", false,-1, 46,0);
    tracep->declBit(c+48,"cycle_vld_o", false,-1);
    tracep->declBit(c+67,"registered_busy_o", false,-1);
    tracep->declQuad(c+4,"registered_data_i", false,-1, 46,0);
    tracep->declBit(c+118,"registered_vld_i", false,-1);
    tracep->declQuad(c+68,"held_data", false,-1, 46,0);
    tracep->declBit(c+67,"held_vld", false,-1);
    tracep->declBit(c+49,"hold_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("skidbufferInstantiation[1] ");
    tracep->pushNamePrefix("slave_skidbuffer ");
    tracep->declBus(c+125,"DW", false,-1, 31,0);
    tracep->declBit(c+75,"clk_i", false,-1);
    tracep->declBit(c+76,"reset_i", false,-1);
    tracep->declBit(c+50,"combinational_busy_i", false,-1);
    tracep->declQuad(c+51,"cycle_data_o", false,-1, 46,0);
    tracep->declBit(c+53,"cycle_vld_o", false,-1);
    tracep->declBit(c+70,"registered_busy_o", false,-1);
    tracep->declQuad(c+6,"registered_data_i", false,-1, 46,0);
    tracep->declBit(c+119,"registered_vld_i", false,-1);
    tracep->declQuad(c+71,"held_data", false,-1, 46,0);
    tracep->declBit(c+70,"held_vld", false,-1);
    tracep->declBit(c+54,"hold_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("slaveRequest ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("stallLogic ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+55,"n", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->declBus(c+56,"n", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk3 ");
    tracep->declBus(c+73,"x", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk4 ");
    tracep->declBus(c+74,"n", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VTileLink1toN___024root__trace_init_top(VTileLink1toN___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_init_top\n"); );
    // Body
    VTileLink1toN___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTileLink1toN___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTileLink1toN___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTileLink1toN___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTileLink1toN___024root__trace_register(VTileLink1toN___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTileLink1toN___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTileLink1toN___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTileLink1toN___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTileLink1toN___024root__trace_full_sub_0(VTileLink1toN___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTileLink1toN___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_full_top_0\n"); );
    // Init
    VTileLink1toN___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTileLink1toN___024root*>(voidSelf);
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTileLink1toN___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTileLink1toN___024root__trace_full_sub_0(VTileLink1toN___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullWData(oldp+1,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7),83);
    bufp->fullQData(oldp+4,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7),47);
    bufp->fullQData(oldp+6,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7),47);
    bufp->fullBit(oldp+8,(vlSelf->TileLink1toN__DOT__master_stalled));
    bufp->fullCData(oldp+9,((7U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                   >> 0x10U))),3);
    bufp->fullCData(oldp+10,((7U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                    >> 0xdU))),3);
    bufp->fullCData(oldp+11,((0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                      >> 9U))),4);
    bufp->fullCData(oldp+12,((0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                      >> 5U))),4);
    bufp->fullIData(oldp+13,(((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                               << 0x1bU) | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                            >> 5U))),32);
    bufp->fullCData(oldp+14,((0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                      >> 1U))),4);
    bufp->fullIData(oldp+15,(((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                               << 0x1fU) | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
                                            >> 1U))),32);
    bufp->fullBit(oldp+16,((1U & vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U])));
    bufp->fullBit(oldp+17,(vlSelf->TileLink1toN__DOT__working_master_a_valid));
    bufp->fullCData(oldp+18,(vlSelf->TileLink1toN__DOT__slave_select),2);
    bufp->fullCData(oldp+19,((((IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3) 
                               << 1U) | (IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3))),2);
    bufp->fullCData(oldp+20,(vlSelf->TileLink1toN__DOT__working_slave_d_opcode),6);
    bufp->fullCData(oldp+21,(vlSelf->TileLink1toN__DOT__working_slave_d_param),4);
    bufp->fullCData(oldp+22,(vlSelf->TileLink1toN__DOT__working_slave_d_size),8);
    bufp->fullCData(oldp+23,(vlSelf->TileLink1toN__DOT__working_slave_d_source),8);
    bufp->fullCData(oldp+24,(((2U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                                              >> 0x21U)) 
                                     << 1U)) | (1U 
                                                & (IData)(
                                                          (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                           >> 0x21U))))),2);
    bufp->fullQData(oldp+25,(vlSelf->TileLink1toN__DOT__working_slave_d_data),64);
    bufp->fullCData(oldp+27,(((2U & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4) 
                                     << 1U)) | (1U 
                                                & (IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4)))),2);
    bufp->fullCData(oldp+28,(vlSelf->TileLink1toN__DOT__working_slave_d_valid),2);
    bufp->fullBit(oldp+29,(vlSelf->TileLink1toN__DOT__bitscan));
    bufp->fullBit(oldp+30,(vlSelf->TileLink1toN__DOT__once));
    bufp->fullBit(oldp+31,(vlSelf->TileLink1toN__DOT__twoormore));
    bufp->fullBit(oldp+32,(vlSelf->TileLink1toN__DOT__burst));
    bufp->fullCData(oldp+33,((7U & ((1U == (1U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
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
                                            >> 3U) : 0U)))),3);
    bufp->fullCData(oldp+34,((3U & ((1U == (1U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
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
                                            >> 2U) : 0U)))),2);
    bufp->fullCData(oldp+35,(vlSelf->TileLink1toN__DOT__resp_size),4);
    bufp->fullCData(oldp+36,((0xfU & ((1U == (1U & 
                                              ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                               & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                   ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                   : 
                                                  (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                       ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_source)
                                       : ((2U == ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                  & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                      ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                      : 
                                                     (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                           ? ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_source) 
                                              >> 4U)
                                           : 0U)))),4);
    bufp->fullIData(oldp+37,(((1U == (1U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                            & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                : (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                               ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_data)
                               : ((2U == ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                          & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                              ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                              : (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                   ? (IData)((vlSelf->TileLink1toN__DOT__working_slave_d_data 
                                              >> 0x20U))
                                   : 0U))),32);
    bufp->fullBit(oldp+38,(vlSelf->TileLink1toN__DOT__resp_denied));
    bufp->fullBit(oldp+39,(vlSelf->TileLink1toN__DOT__resp_corrupt));
    bufp->fullSData(oldp+40,(vlSelf->TileLink1toN__DOT__number_to_write),12);
    bufp->fullWData(oldp+41,(vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4),83);
    bufp->fullBit(oldp+44,(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__hold_data));
    bufp->fullBit(oldp+45,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3));
    bufp->fullQData(oldp+46,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4),47);
    bufp->fullBit(oldp+48,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5));
    bufp->fullBit(oldp+49,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data));
    bufp->fullBit(oldp+50,(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3));
    bufp->fullQData(oldp+51,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4),47);
    bufp->fullBit(oldp+53,(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5));
    bufp->fullBit(oldp+54,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data));
    bufp->fullIData(oldp+55,(vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n),32);
    bufp->fullIData(oldp+56,(vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n),32);
    bufp->fullBit(oldp+57,(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld));
    bufp->fullCData(oldp+58,((((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld) 
                               << 1U) | (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld))),2);
    bufp->fullCData(oldp+59,(vlSelf->TileLink1toN__DOT__block),2);
    bufp->fullBit(oldp+60,(vlSelf->TileLink1toN__DOT__lock));
    bufp->fullCData(oldp+61,(vlSelf->TileLink1toN__DOT__locked_slave_select),2);
    bufp->fullSData(oldp+62,(vlSelf->TileLink1toN__DOT__burst_counters),12);
    bufp->fullBit(oldp+63,(vlSelf->TileLink1toN__DOT__burst_ending));
    bufp->fullWData(oldp+64,(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data),83);
    bufp->fullBit(oldp+67,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld));
    bufp->fullQData(oldp+68,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data),47);
    bufp->fullBit(oldp+70,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld));
    bufp->fullQData(oldp+71,(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data),47);
    bufp->fullIData(oldp+73,(vlSelf->TileLink1toN__DOT__unnamedblk3__DOT__x),32);
    bufp->fullIData(oldp+74,(vlSelf->TileLink1toN__DOT__unnamedblk4__DOT__n),32);
    bufp->fullBit(oldp+75,(vlSelf->tilelink_clock_i));
    bufp->fullBit(oldp+76,(vlSelf->tilelink_reset_i));
    bufp->fullCData(oldp+77,(vlSelf->master_a_opcode),3);
    bufp->fullCData(oldp+78,(vlSelf->master_a_param),3);
    bufp->fullCData(oldp+79,(vlSelf->master_a_size),4);
    bufp->fullCData(oldp+80,(vlSelf->master_a_source),4);
    bufp->fullIData(oldp+81,(vlSelf->master_a_address),32);
    bufp->fullCData(oldp+82,(vlSelf->master_a_mask),4);
    bufp->fullIData(oldp+83,(vlSelf->master_a_data),32);
    bufp->fullBit(oldp+84,(vlSelf->master_a_corrupt));
    bufp->fullBit(oldp+85,(vlSelf->master_a_valid));
    bufp->fullBit(oldp+86,(vlSelf->master_a_ready));
    bufp->fullCData(oldp+87,(vlSelf->master_d_opcode),3);
    bufp->fullCData(oldp+88,(vlSelf->master_d_param),2);
    bufp->fullCData(oldp+89,(vlSelf->master_d_size),4);
    bufp->fullCData(oldp+90,(vlSelf->master_d_source),4);
    bufp->fullBit(oldp+91,(vlSelf->master_d_denied));
    bufp->fullIData(oldp+92,(vlSelf->master_d_data),32);
    bufp->fullBit(oldp+93,(vlSelf->master_d_corrupt));
    bufp->fullBit(oldp+94,(vlSelf->master_d_valid));
    bufp->fullBit(oldp+95,(vlSelf->master_d_ready));
    bufp->fullCData(oldp+96,(vlSelf->slave_a_opcode),6);
    bufp->fullCData(oldp+97,(vlSelf->slave_a_param),6);
    bufp->fullCData(oldp+98,(vlSelf->slave_a_size),8);
    bufp->fullCData(oldp+99,(vlSelf->slave_a_source),8);
    bufp->fullQData(oldp+100,(vlSelf->slave_a_address),64);
    bufp->fullCData(oldp+102,(vlSelf->slave_a_mask),8);
    bufp->fullQData(oldp+103,(vlSelf->slave_a_data),64);
    bufp->fullCData(oldp+105,(vlSelf->slave_a_corrupt),2);
    bufp->fullCData(oldp+106,(vlSelf->slave_a_valid),2);
    bufp->fullCData(oldp+107,(vlSelf->slave_a_ready),2);
    bufp->fullCData(oldp+108,(vlSelf->slave_d_opcode),6);
    bufp->fullCData(oldp+109,(vlSelf->slave_d_param),4);
    bufp->fullCData(oldp+110,(vlSelf->slave_d_size),8);
    bufp->fullCData(oldp+111,(vlSelf->slave_d_source),8);
    bufp->fullCData(oldp+112,(vlSelf->slave_d_denied),2);
    bufp->fullQData(oldp+113,(vlSelf->slave_d_data),64);
    bufp->fullCData(oldp+115,(vlSelf->slave_d_corrupt),2);
    bufp->fullCData(oldp+116,(vlSelf->slave_d_valid),2);
    bufp->fullCData(oldp+117,(vlSelf->slave_d_ready),2);
    bufp->fullBit(oldp+118,((1U & (IData)(vlSelf->slave_d_valid))));
    bufp->fullBit(oldp+119,((1U & ((IData)(vlSelf->slave_d_valid) 
                                   >> 1U))));
    bufp->fullQData(oldp+120,(0x100000002000ULL),64);
    bufp->fullQData(oldp+122,(0x200010000000ULL),64);
    bufp->fullIData(oldp+124,(0x53U),32);
    bufp->fullIData(oldp+125,(0x2fU),32);
}
