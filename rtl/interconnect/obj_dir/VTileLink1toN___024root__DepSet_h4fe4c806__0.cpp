// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTileLink1toN.h for the primary calling header

#include "verilated.h"

#include "VTileLink1toN__Syms.h"
#include "VTileLink1toN___024root.h"

extern const VlUnpacked<CData/*0:0*/, 512> VTileLink1toN__ConstPool__TABLE_h86d9788e_0;
extern const VlUnpacked<SData/*11:0*/, 16> VTileLink1toN__ConstPool__TABLE_h942e113f_0;

VL_INLINE_OPT void VTileLink1toN___024root___ico_sequent__TOP__0(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___ico_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    vlSelf->TileLink1toN__DOT__working_master_a_valid 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld) 
           | (IData)(vlSelf->master_a_valid));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[0U] 
        = (IData)((((QData)((IData)(vlSelf->master_a_mask)) 
                    << 0x21U) | (((QData)((IData)(vlSelf->master_a_data)) 
                                  << 1U) | (QData)((IData)(vlSelf->master_a_corrupt)))));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[1U] 
        = ((vlSelf->master_a_address << 5U) | (IData)(
                                                      ((((QData)((IData)(vlSelf->master_a_mask)) 
                                                         << 0x21U) 
                                                        | (((QData)((IData)(vlSelf->master_a_data)) 
                                                            << 1U) 
                                                           | (QData)((IData)(vlSelf->master_a_corrupt)))) 
                                                       >> 0x20U)));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[2U] 
        = (((IData)(vlSelf->master_a_opcode) << 0x10U) 
           | (((IData)(vlSelf->master_a_param) << 0xdU) 
              | (((IData)(vlSelf->master_a_size) << 9U) 
                 | (((IData)(vlSelf->master_a_source) 
                     << 5U) | (vlSelf->master_a_address 
                               >> 0x1bU)))));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7 
        = (((QData)((IData)((7U & (IData)(vlSelf->slave_d_opcode)))) 
            << 0x2cU) | (((QData)((IData)((3U & (IData)(vlSelf->slave_d_param)))) 
                          << 0x2aU) | (((QData)((IData)(
                                                        (0xfU 
                                                         & (IData)(vlSelf->slave_d_size)))) 
                                        << 0x26U) | 
                                       (((QData)((IData)(
                                                         (0xfU 
                                                          & (IData)(vlSelf->slave_d_source)))) 
                                         << 0x22U) 
                                        | (((QData)((IData)(
                                                            (1U 
                                                             & (IData)(vlSelf->slave_d_denied)))) 
                                            << 0x21U) 
                                           | (((QData)((IData)(vlSelf->slave_d_data)) 
                                               << 1U) 
                                              | (QData)((IData)(
                                                                (1U 
                                                                 & (IData)(vlSelf->slave_d_corrupt))))))))));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7 
        = (((QData)((IData)((7U & ((IData)(vlSelf->slave_d_opcode) 
                                   >> 3U)))) << 0x2cU) 
           | (((QData)((IData)((3U & ((IData)(vlSelf->slave_d_param) 
                                      >> 2U)))) << 0x2aU) 
              | (((QData)((IData)((0xfU & ((IData)(vlSelf->slave_d_size) 
                                           >> 4U)))) 
                  << 0x26U) | (((QData)((IData)((0xfU 
                                                 & ((IData)(vlSelf->slave_d_source) 
                                                    >> 4U)))) 
                                << 0x22U) | (((QData)((IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->slave_d_denied) 
                                                                  >> 1U)))) 
                                              << 0x21U) 
                                             | (((QData)((IData)(
                                                                 (vlSelf->slave_d_data 
                                                                  >> 0x20U))) 
                                                 << 1U) 
                                                | (QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlSelf->slave_d_corrupt) 
                                                                      >> 1U))))))))));
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld) 
           | ((IData)(vlSelf->slave_d_valid) >> 1U));
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5 
        = (1U & ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld) 
                 | (IData)(vlSelf->slave_d_valid)));
    if (vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld) {
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
            = vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[0U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
            = vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[1U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
            = vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[2U];
    } else {
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
            = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[0U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
            = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[1U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
            = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[2U];
    }
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld)
            ? vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data
            : vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7);
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld)
            ? vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data
            : vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7);
    vlSelf->TileLink1toN__DOT__working_slave_d_valid 
        = (((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5) 
            << 1U) | (IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5));
    vlSelf->TileLink1toN__DOT__slave_select = ((((0x1000U 
                                                  <= 
                                                  ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                    << 0x1bU) 
                                                   | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                      >> 5U))) 
                                                 & ((0x2000U 
                                                     > 
                                                     ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                       << 0x1bU) 
                                                      | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                         >> 5U))) 
                                                    & (IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid))) 
                                                << 1U) 
                                               | ((0x2000U 
                                                   <= 
                                                   ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                     << 0x1bU) 
                                                    | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                       >> 5U))) 
                                                  & ((0x10000000U 
                                                      > 
                                                      ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                        << 0x1bU) 
                                                       | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                          >> 5U))) 
                                                     & (IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid))));
    vlSelf->TileLink1toN__DOT__working_slave_d_data 
        = (((QData)((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                             >> 1U))) << 0x20U) | (QData)((IData)(
                                                                  (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                                   >> 1U))));
    vlSelf->TileLink1toN__DOT__working_slave_d_opcode 
        = ((0x38U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                              >> 0x2cU)) << 3U)) | 
           (7U & (IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                          >> 0x2cU))));
    vlSelf->TileLink1toN__DOT__working_slave_d_param 
        = ((0xcU & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                             >> 0x2aU)) << 2U)) | (3U 
                                                   & (IData)(
                                                             (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                              >> 0x2aU))));
    vlSelf->TileLink1toN__DOT__working_slave_d_source 
        = ((0xf0U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                              >> 0x22U)) << 4U)) | 
           (0xfU & (IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                            >> 0x22U))));
    vlSelf->TileLink1toN__DOT__working_slave_d_size 
        = ((0xf0U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                              >> 0x26U)) << 4U)) | 
           (0xfU & (IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                            >> 0x26U))));
    __Vtableidx1 = (((0x100U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                                         >> 0x21U)) 
                                << 8U)) | (0x80U & 
                                           ((IData)(
                                                    (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                     >> 0x21U)) 
                                            << 7U))) 
                    | (((IData)(vlSelf->TileLink1toN__DOT__block) 
                        << 5U) | (((IData)(vlSelf->TileLink1toN__DOT__locked_slave_select) 
                                   << 3U) | (((IData)(vlSelf->TileLink1toN__DOT__lock) 
                                              << 2U) 
                                             | (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid)))));
    vlSelf->TileLink1toN__DOT__resp_denied = VTileLink1toN__ConstPool__TABLE_h86d9788e_0
        [__Vtableidx1];
    __Vtableidx2 = (((0x100U & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4) 
                                << 8U)) | (0x80U & 
                                           ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4) 
                                            << 7U))) 
                    | (((IData)(vlSelf->TileLink1toN__DOT__block) 
                        << 5U) | (((IData)(vlSelf->TileLink1toN__DOT__locked_slave_select) 
                                   << 3U) | (((IData)(vlSelf->TileLink1toN__DOT__lock) 
                                              << 2U) 
                                             | (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid)))));
    vlSelf->TileLink1toN__DOT__resp_corrupt = VTileLink1toN__ConstPool__TABLE_h86d9788e_0
        [__Vtableidx2];
    vlSelf->TileLink1toN__DOT__bitscan = 0U;
    vlSelf->TileLink1toN__DOT__once = 0U;
    vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 2U, vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n)) {
            if ((1U & (((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                        >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n)) 
                       & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                           ? ((IData)(vlSelf->TileLink1toN__DOT__locked_slave_select) 
                              >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n))
                           : (~ ((IData)(vlSelf->TileLink1toN__DOT__block) 
                                 >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n))))))) {
                vlSelf->TileLink1toN__DOT__bitscan 
                    = (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n);
                vlSelf->TileLink1toN__DOT__once = 1U;
                goto __Vlabel1;
            } else {
                vlSelf->TileLink1toN__DOT__once = 0U;
                vlSelf->TileLink1toN__DOT__bitscan = 0U;
            }
            vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n 
                = ((IData)(1U) + vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n);
        }
        __Vlabel1: ;
    }
    vlSelf->TileLink1toN__DOT__master_stalled = (0U 
                                                 != 
                                                 ((~ (IData)(vlSelf->slave_a_ready)) 
                                                  & (IData)(vlSelf->TileLink1toN__DOT__slave_select)));
    vlSelf->TileLink1toN__DOT__resp_size = (0xfU & 
                                            ((1U == 
                                              (1U & 
                                               ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                    ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                    : 
                                                   (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                              ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_size)
                                              : ((2U 
                                                  == 
                                                  ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                   & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                       ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                       : 
                                                      (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                                  ? 
                                                 ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_size) 
                                                  >> 4U)
                                                  : 0U)));
    vlSelf->TileLink1toN__DOT__twoormore = 0U;
    vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 2U, vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n)) {
            if (((((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                   >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n)) 
                  & ((1U & vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n) 
                     != (IData)(vlSelf->TileLink1toN__DOT__bitscan))) 
                 & (IData)(vlSelf->TileLink1toN__DOT__once))) {
                vlSelf->TileLink1toN__DOT__twoormore = 1U;
                goto __Vlabel2;
            } else {
                vlSelf->TileLink1toN__DOT__twoormore = 0U;
            }
            vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n 
                = ((IData)(1U) + vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n);
        }
        __Vlabel2: ;
    }
    vlSelf->TileLink1toN__DOT__skidbuffer__DOT__hold_data 
        = ((IData)(vlSelf->TileLink1toN__DOT__master_stalled) 
           & ((IData)(vlSelf->master_a_ready) & ((IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid) 
                                                 & (IData)(vlSelf->master_a_valid))));
    __Vtableidx3 = vlSelf->TileLink1toN__DOT__resp_size;
    vlSelf->TileLink1toN__DOT__number_to_write = VTileLink1toN__ConstPool__TABLE_h942e113f_0
        [__Vtableidx3];
    vlSelf->TileLink1toN__DOT__burst = (((IData)(vlSelf->TileLink1toN__DOT__once) 
                                         & ((IData)(vlSelf->master_d_ready) 
                                            & (2U < (IData)(vlSelf->TileLink1toN__DOT__resp_size)))) 
                                        | (IData)(vlSelf->TileLink1toN__DOT__lock));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3 
        = (1U & ((~ (IData)(vlSelf->master_d_ready)) 
                 | ((~ (IData)(vlSelf->TileLink1toN__DOT__bitscan)) 
                    & (IData)(vlSelf->TileLink1toN__DOT__twoormore))));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3 
        = (1U & ((~ (IData)(vlSelf->master_d_ready)) 
                 | ((IData)(vlSelf->TileLink1toN__DOT__bitscan) 
                    & (IData)(vlSelf->TileLink1toN__DOT__twoormore))));
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data 
        = ((IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3) 
           & ((~ (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld)) 
              & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5) 
                 & ((IData)(vlSelf->slave_d_valid) 
                    >> 1U))));
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data 
        = ((IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3) 
           & ((~ (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld)) 
              & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5) 
                 & (IData)(vlSelf->slave_d_valid))));
}

void VTileLink1toN___024root___eval_ico(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTileLink1toN___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VTileLink1toN___024root___eval_act(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTileLink1toN___024root___nba_sequent__TOP__0(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__TileLink1toN__DOT__lock;
    __Vdly__TileLink1toN__DOT__lock = 0;
    SData/*11:0*/ __Vdly__TileLink1toN__DOT__burst_counters;
    __Vdly__TileLink1toN__DOT__burst_counters = 0;
    // Body
    __Vdly__TileLink1toN__DOT__burst_counters = vlSelf->TileLink1toN__DOT__burst_counters;
    __Vdly__TileLink1toN__DOT__lock = vlSelf->TileLink1toN__DOT__lock;
    vlSelf->TileLink1toN__DOT__unnamedblk3__DOT__x = 2U;
    vlSelf->TileLink1toN__DOT__unnamedblk4__DOT__n = 2U;
    if (vlSelf->tilelink_reset_i) {
        __Vdly__TileLink1toN__DOT__burst_counters = 0U;
        vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[0U] = 0U;
        vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[1U] = 0U;
        vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[2U] = 0U;
        vlSelf->master_d_valid = 0U;
        vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld = 0U;
        vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data = 0ULL;
        vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data = 0ULL;
        vlSelf->slave_a_valid = (2U & (IData)(vlSelf->slave_a_valid));
        vlSelf->slave_a_valid = (1U & (IData)(vlSelf->slave_a_valid));
        vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld = 0U;
        vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld = 0U;
    } else {
        if (((((IData)(vlSelf->TileLink1toN__DOT__burst) 
               & (~ (IData)(vlSelf->TileLink1toN__DOT__lock))) 
              & (IData)(vlSelf->TileLink1toN__DOT__once)) 
             & (IData)(vlSelf->master_d_ready))) {
            __Vdly__TileLink1toN__DOT__burst_counters 
                = vlSelf->TileLink1toN__DOT__number_to_write;
        } else if (((((IData)(vlSelf->TileLink1toN__DOT__lock) 
                      & (IData)(vlSelf->TileLink1toN__DOT__once)) 
                     & (IData)(vlSelf->master_d_ready)) 
                    & (~ (IData)(vlSelf->TileLink1toN__DOT__burst_ending)))) {
            __Vdly__TileLink1toN__DOT__burst_counters 
                = (0xfffU & ((IData)(vlSelf->TileLink1toN__DOT__burst_counters) 
                             - (IData)(1U)));
        }
        if (vlSelf->TileLink1toN__DOT__skidbuffer__DOT__hold_data) {
            vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[0U] 
                = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[0U];
            vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[1U] 
                = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[1U];
            vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[2U] 
                = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[2U];
            vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld = 1U;
        } else if ((1U & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled)))) {
            vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld = 0U;
        }
        if (((IData)(vlSelf->TileLink1toN__DOT__once) 
             & (IData)(vlSelf->master_d_ready))) {
            vlSelf->master_d_valid = 1U;
        } else if (((~ (IData)(vlSelf->TileLink1toN__DOT__once)) 
                    & (IData)(vlSelf->master_d_ready))) {
            vlSelf->master_d_valid = 0U;
        }
        if (vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data) {
            vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data 
                = vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7;
            vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld = 1U;
        } else if ((1U & (~ (IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3)))) {
            vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld = 0U;
        }
        if (vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data) {
            vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data 
                = vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7;
            vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld = 1U;
        } else if ((1U & (~ (IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3)))) {
            vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld = 0U;
        }
        if ((((IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid) 
              & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled))) 
             & (IData)(vlSelf->TileLink1toN__DOT__slave_select))) {
            vlSelf->slave_a_valid = (1U | (IData)(vlSelf->slave_a_valid));
        } else if ((1U & (((~ (IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid)) 
                           | (~ (IData)(vlSelf->TileLink1toN__DOT__slave_select))) 
                          & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled))))) {
            vlSelf->slave_a_valid = (2U & (IData)(vlSelf->slave_a_valid));
        }
        if ((((IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid) 
              & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled))) 
             & ((IData)(vlSelf->TileLink1toN__DOT__slave_select) 
                >> 1U))) {
            vlSelf->slave_a_valid = (2U | (IData)(vlSelf->slave_a_valid));
        } else if ((1U & (((~ (IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid)) 
                           | (~ ((IData)(vlSelf->TileLink1toN__DOT__slave_select) 
                                 >> 1U))) & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled))))) {
            vlSelf->slave_a_valid = (1U & (IData)(vlSelf->slave_a_valid));
        }
    }
    __Vdly__TileLink1toN__DOT__lock = (1U & ((~ (IData)(vlSelf->tilelink_reset_i)) 
                                             & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                 ? 
                                                (~ (IData)(vlSelf->TileLink1toN__DOT__burst_ending))
                                                 : 
                                                (((IData)(vlSelf->TileLink1toN__DOT__once) 
                                                  & (IData)(vlSelf->master_d_ready)) 
                                                 & (2U 
                                                    < (IData)(vlSelf->TileLink1toN__DOT__resp_size))))));
    if ((1U & (~ (IData)(vlSelf->tilelink_reset_i)))) {
        if (((IData)(vlSelf->TileLink1toN__DOT__once) 
             & (IData)(vlSelf->master_d_ready))) {
            vlSelf->master_d_denied = vlSelf->TileLink1toN__DOT__resp_denied;
            vlSelf->master_d_corrupt = vlSelf->TileLink1toN__DOT__resp_corrupt;
            vlSelf->master_d_size = vlSelf->TileLink1toN__DOT__resp_size;
            if ((1U == (1U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                              & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                  ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                  : (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))) {
                vlSelf->master_d_param = (3U & (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_param));
                vlSelf->master_d_source = (0xfU & (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_source));
                vlSelf->master_d_opcode = (7U & (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_opcode));
                vlSelf->master_d_data = (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_data);
            } else if ((2U == ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                               & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                   ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                   : (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))) {
                vlSelf->master_d_param = (3U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_param) 
                                                >> 2U));
                vlSelf->master_d_source = (0xfU & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_source) 
                                                   >> 4U));
                vlSelf->master_d_opcode = (7U & ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_opcode) 
                                                 >> 3U));
                vlSelf->master_d_data = (IData)((vlSelf->TileLink1toN__DOT__working_slave_d_data 
                                                 >> 0x20U));
            } else {
                vlSelf->master_d_param = (3U & 0U);
                vlSelf->master_d_source = (0xfU & 0U);
                vlSelf->master_d_opcode = (7U & 0U);
                vlSelf->master_d_data = 0U;
            }
        }
        if ((((IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid) 
              & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled))) 
             & (IData)(vlSelf->TileLink1toN__DOT__slave_select))) {
            vlSelf->slave_a_corrupt = ((2U & (IData)(vlSelf->slave_a_corrupt)) 
                                       | (1U & vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U]));
            vlSelf->slave_a_address = ((0xffffffff00000000ULL 
                                        & vlSelf->slave_a_address) 
                                       | (IData)((IData)(
                                                         ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                           << 0x1bU) 
                                                          | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                             >> 5U)))));
            vlSelf->slave_a_size = ((0xf0U & (IData)(vlSelf->slave_a_size)) 
                                    | (0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                               >> 9U)));
            vlSelf->slave_a_data = ((0xffffffff00000000ULL 
                                     & vlSelf->slave_a_data) 
                                    | (IData)((IData)(
                                                      ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                        << 0x1fU) 
                                                       | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
                                                          >> 1U)))));
            vlSelf->slave_a_mask = ((0xf0U & (IData)(vlSelf->slave_a_mask)) 
                                    | (0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                               >> 1U)));
            vlSelf->slave_a_opcode = ((0x38U & (IData)(vlSelf->slave_a_opcode)) 
                                      | (7U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                               >> 0x10U)));
            vlSelf->slave_a_param = ((0x38U & (IData)(vlSelf->slave_a_param)) 
                                     | (7U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                              >> 0xdU)));
            vlSelf->slave_a_source = ((0xf0U & (IData)(vlSelf->slave_a_source)) 
                                      | (0xfU & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                 >> 5U)));
        }
        if ((((IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid) 
              & (~ (IData)(vlSelf->TileLink1toN__DOT__master_stalled))) 
             & ((IData)(vlSelf->TileLink1toN__DOT__slave_select) 
                >> 1U))) {
            vlSelf->slave_a_corrupt = ((1U & (IData)(vlSelf->slave_a_corrupt)) 
                                       | (2U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
                                                << 1U)));
            vlSelf->slave_a_address = ((0xffffffffULL 
                                        & vlSelf->slave_a_address) 
                                       | ((QData)((IData)(
                                                          ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                            << 0x1bU) 
                                                           | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                              >> 5U)))) 
                                          << 0x20U));
            vlSelf->slave_a_size = ((0xfU & (IData)(vlSelf->slave_a_size)) 
                                    | (0xf0U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                >> 5U)));
            vlSelf->slave_a_data = ((0xffffffffULL 
                                     & vlSelf->slave_a_data) 
                                    | ((QData)((IData)(
                                                       ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                         << 0x1fU) 
                                                        | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
                                                           >> 1U)))) 
                                       << 0x20U));
            vlSelf->slave_a_mask = ((0xfU & (IData)(vlSelf->slave_a_mask)) 
                                    | (0xf0U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                << 3U)));
            vlSelf->slave_a_opcode = ((7U & (IData)(vlSelf->slave_a_opcode)) 
                                      | (0x38U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                  >> 0xdU)));
            vlSelf->slave_a_param = ((7U & (IData)(vlSelf->slave_a_param)) 
                                     | (0x38U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                 >> 0xaU)));
            vlSelf->slave_a_source = ((0xfU & (IData)(vlSelf->slave_a_source)) 
                                      | (0xf0U & (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                  >> 1U)));
        }
    }
    vlSelf->TileLink1toN__DOT__burst_counters = __Vdly__TileLink1toN__DOT__burst_counters;
    vlSelf->TileLink1toN__DOT__lock = __Vdly__TileLink1toN__DOT__lock;
    vlSelf->master_a_ready = (1U & (~ (IData)(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld)));
    vlSelf->TileLink1toN__DOT__working_master_a_valid 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld) 
           | (IData)(vlSelf->master_a_valid));
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld) 
           | ((IData)(vlSelf->slave_d_valid) >> 1U));
    vlSelf->slave_d_ready = (3U & (~ (((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld) 
                                       << 1U) | (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld))));
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5 
        = (1U & ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld) 
                 | (IData)(vlSelf->slave_d_valid)));
    vlSelf->TileLink1toN__DOT__block = ((2U & (IData)(vlSelf->TileLink1toN__DOT__block)) 
                                        | ((~ (IData)(vlSelf->tilelink_reset_i)) 
                                           & ((~ ((~ (IData)(vlSelf->TileLink1toN__DOT__twoormore)) 
                                                  & ((~ (IData)(vlSelf->TileLink1toN__DOT__burst)) 
                                                     | ((IData)(vlSelf->TileLink1toN__DOT__burst) 
                                                        & (IData)(vlSelf->TileLink1toN__DOT__burst_ending))))) 
                                              & ((IData)(vlSelf->TileLink1toN__DOT__twoormore) 
                                                 & (~ (IData)(vlSelf->TileLink1toN__DOT__bitscan))))));
    vlSelf->TileLink1toN__DOT__block = ((1U & (IData)(vlSelf->TileLink1toN__DOT__block)) 
                                        | (((~ (IData)(vlSelf->tilelink_reset_i)) 
                                            & ((~ (
                                                   (~ (IData)(vlSelf->TileLink1toN__DOT__twoormore)) 
                                                   & ((~ (IData)(vlSelf->TileLink1toN__DOT__burst)) 
                                                      | ((IData)(vlSelf->TileLink1toN__DOT__burst) 
                                                         & (IData)(vlSelf->TileLink1toN__DOT__burst_ending))))) 
                                               & ((IData)(vlSelf->TileLink1toN__DOT__twoormore) 
                                                  & (IData)(vlSelf->TileLink1toN__DOT__bitscan)))) 
                                           << 1U));
    vlSelf->TileLink1toN__DOT__locked_slave_select 
        = ((2U & (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)) 
           | ((~ (IData)(vlSelf->tilelink_reset_i)) 
              & (((~ (IData)(vlSelf->TileLink1toN__DOT__bitscan)) 
                  & (IData)(vlSelf->TileLink1toN__DOT__once)) 
                 & (IData)(vlSelf->TileLink1toN__DOT__burst))));
    vlSelf->TileLink1toN__DOT__locked_slave_select 
        = ((1U & (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)) 
           | (((~ (IData)(vlSelf->tilelink_reset_i)) 
               & (((IData)(vlSelf->TileLink1toN__DOT__bitscan) 
                   & (IData)(vlSelf->TileLink1toN__DOT__once)) 
                  & (IData)(vlSelf->TileLink1toN__DOT__burst))) 
              << 1U));
    vlSelf->TileLink1toN__DOT__working_slave_d_valid 
        = (((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5) 
            << 1U) | (IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5));
    vlSelf->TileLink1toN__DOT__burst_ending = ((0U 
                                                == (IData)(vlSelf->TileLink1toN__DOT__burst_counters)) 
                                               & (IData)(vlSelf->TileLink1toN__DOT__lock));
    vlSelf->TileLink1toN__DOT__bitscan = 0U;
    vlSelf->TileLink1toN__DOT__once = 0U;
    vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 2U, vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n)) {
            if ((1U & (((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                        >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n)) 
                       & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                           ? ((IData)(vlSelf->TileLink1toN__DOT__locked_slave_select) 
                              >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n))
                           : (~ ((IData)(vlSelf->TileLink1toN__DOT__block) 
                                 >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n))))))) {
                vlSelf->TileLink1toN__DOT__bitscan 
                    = (1U & vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n);
                vlSelf->TileLink1toN__DOT__once = 1U;
                goto __Vlabel3;
            } else {
                vlSelf->TileLink1toN__DOT__once = 0U;
                vlSelf->TileLink1toN__DOT__bitscan = 0U;
            }
            vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n 
                = ((IData)(1U) + vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n);
        }
        __Vlabel3: ;
    }
    vlSelf->TileLink1toN__DOT__twoormore = 0U;
    vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 2U, vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n)) {
            if (((((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                   >> (1U & vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n)) 
                  & ((1U & vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n) 
                     != (IData)(vlSelf->TileLink1toN__DOT__bitscan))) 
                 & (IData)(vlSelf->TileLink1toN__DOT__once))) {
                vlSelf->TileLink1toN__DOT__twoormore = 1U;
                goto __Vlabel4;
            } else {
                vlSelf->TileLink1toN__DOT__twoormore = 0U;
            }
            vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n 
                = ((IData)(1U) + vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n);
        }
        __Vlabel4: ;
    }
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3 
        = (1U & ((~ (IData)(vlSelf->master_d_ready)) 
                 | ((~ (IData)(vlSelf->TileLink1toN__DOT__bitscan)) 
                    & (IData)(vlSelf->TileLink1toN__DOT__twoormore))));
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3 
        = (1U & ((~ (IData)(vlSelf->master_d_ready)) 
                 | ((IData)(vlSelf->TileLink1toN__DOT__bitscan) 
                    & (IData)(vlSelf->TileLink1toN__DOT__twoormore))));
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data 
        = ((IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3) 
           & ((~ (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld)) 
              & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5) 
                 & ((IData)(vlSelf->slave_d_valid) 
                    >> 1U))));
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data 
        = ((IData)(vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3) 
           & ((~ (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld)) 
              & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5) 
                 & (IData)(vlSelf->slave_d_valid))));
}

VL_INLINE_OPT void VTileLink1toN___024root___nba_sequent__TOP__1(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    if (vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld) {
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
            = vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[0U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
            = vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[1U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
            = vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data[2U];
    } else {
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[0U] 
            = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[0U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
            = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[1U];
        vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
            = vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7[2U];
    }
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld)
            ? vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data
            : vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7);
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
        = ((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld)
            ? vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data
            : vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7);
    vlSelf->TileLink1toN__DOT__slave_select = ((((0x1000U 
                                                  <= 
                                                  ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                    << 0x1bU) 
                                                   | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                      >> 5U))) 
                                                 & ((0x2000U 
                                                     > 
                                                     ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                       << 0x1bU) 
                                                      | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                         >> 5U))) 
                                                    & (IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid))) 
                                                << 1U) 
                                               | ((0x2000U 
                                                   <= 
                                                   ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                     << 0x1bU) 
                                                    | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                       >> 5U))) 
                                                  & ((0x10000000U 
                                                      > 
                                                      ((vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[2U] 
                                                        << 0x1bU) 
                                                       | (vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4[1U] 
                                                          >> 5U))) 
                                                     & (IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid))));
    vlSelf->TileLink1toN__DOT__working_slave_d_data 
        = (((QData)((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                             >> 1U))) << 0x20U) | (QData)((IData)(
                                                                  (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                                   >> 1U))));
    vlSelf->TileLink1toN__DOT__working_slave_d_opcode 
        = ((0x38U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                              >> 0x2cU)) << 3U)) | 
           (7U & (IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                          >> 0x2cU))));
    vlSelf->TileLink1toN__DOT__working_slave_d_param 
        = ((0xcU & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                             >> 0x2aU)) << 2U)) | (3U 
                                                   & (IData)(
                                                             (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                              >> 0x2aU))));
    vlSelf->TileLink1toN__DOT__working_slave_d_source 
        = ((0xf0U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                              >> 0x22U)) << 4U)) | 
           (0xfU & (IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                            >> 0x22U))));
    vlSelf->TileLink1toN__DOT__working_slave_d_size 
        = ((0xf0U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                              >> 0x26U)) << 4U)) | 
           (0xfU & (IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                            >> 0x26U))));
    __Vtableidx1 = (((0x100U & ((IData)((vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 
                                         >> 0x21U)) 
                                << 8U)) | (0x80U & 
                                           ((IData)(
                                                    (vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 
                                                     >> 0x21U)) 
                                            << 7U))) 
                    | (((IData)(vlSelf->TileLink1toN__DOT__block) 
                        << 5U) | (((IData)(vlSelf->TileLink1toN__DOT__locked_slave_select) 
                                   << 3U) | (((IData)(vlSelf->TileLink1toN__DOT__lock) 
                                              << 2U) 
                                             | (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid)))));
    vlSelf->TileLink1toN__DOT__resp_denied = VTileLink1toN__ConstPool__TABLE_h86d9788e_0
        [__Vtableidx1];
    __Vtableidx2 = (((0x100U & ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4) 
                                << 8U)) | (0x80U & 
                                           ((IData)(vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4) 
                                            << 7U))) 
                    | (((IData)(vlSelf->TileLink1toN__DOT__block) 
                        << 5U) | (((IData)(vlSelf->TileLink1toN__DOT__locked_slave_select) 
                                   << 3U) | (((IData)(vlSelf->TileLink1toN__DOT__lock) 
                                              << 2U) 
                                             | (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid)))));
    vlSelf->TileLink1toN__DOT__resp_corrupt = VTileLink1toN__ConstPool__TABLE_h86d9788e_0
        [__Vtableidx2];
    vlSelf->TileLink1toN__DOT__master_stalled = (0U 
                                                 != 
                                                 ((~ (IData)(vlSelf->slave_a_ready)) 
                                                  & (IData)(vlSelf->TileLink1toN__DOT__slave_select)));
    vlSelf->TileLink1toN__DOT__resp_size = (0xfU & 
                                            ((1U == 
                                              (1U & 
                                               ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                    ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                    : 
                                                   (~ (IData)(vlSelf->TileLink1toN__DOT__block))))))
                                              ? (IData)(vlSelf->TileLink1toN__DOT__working_slave_d_size)
                                              : ((2U 
                                                  == 
                                                  ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_valid) 
                                                   & ((IData)(vlSelf->TileLink1toN__DOT__lock)
                                                       ? (IData)(vlSelf->TileLink1toN__DOT__locked_slave_select)
                                                       : 
                                                      (~ (IData)(vlSelf->TileLink1toN__DOT__block)))))
                                                  ? 
                                                 ((IData)(vlSelf->TileLink1toN__DOT__working_slave_d_size) 
                                                  >> 4U)
                                                  : 0U)));
    vlSelf->TileLink1toN__DOT__skidbuffer__DOT__hold_data 
        = ((IData)(vlSelf->TileLink1toN__DOT__master_stalled) 
           & ((IData)(vlSelf->master_a_ready) & ((IData)(vlSelf->TileLink1toN__DOT__working_master_a_valid) 
                                                 & (IData)(vlSelf->master_a_valid))));
    __Vtableidx3 = vlSelf->TileLink1toN__DOT__resp_size;
    vlSelf->TileLink1toN__DOT__number_to_write = VTileLink1toN__ConstPool__TABLE_h942e113f_0
        [__Vtableidx3];
    vlSelf->TileLink1toN__DOT__burst = (((IData)(vlSelf->TileLink1toN__DOT__once) 
                                         & ((IData)(vlSelf->master_d_ready) 
                                            & (2U < (IData)(vlSelf->TileLink1toN__DOT__resp_size)))) 
                                        | (IData)(vlSelf->TileLink1toN__DOT__lock));
}

void VTileLink1toN___024root___eval_nba(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTileLink1toN___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        VTileLink1toN___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void VTileLink1toN___024root___eval_triggers__ico(VTileLink1toN___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__ico(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG
void VTileLink1toN___024root___eval_triggers__act(VTileLink1toN___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__act(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__nba(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG

void VTileLink1toN___024root___eval(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval\n"); );
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
        VTileLink1toN___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VTileLink1toN___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("TileLink1toN.sv", 3, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VTileLink1toN___024root___eval_ico(vlSelf);
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
            VTileLink1toN___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTileLink1toN___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("TileLink1toN.sv", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VTileLink1toN___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTileLink1toN___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("TileLink1toN.sv", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTileLink1toN___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTileLink1toN___024root___eval_debug_assertions(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->tilelink_clock_i & 0xfeU))) {
        Verilated::overWidthError("tilelink_clock_i");}
    if (VL_UNLIKELY((vlSelf->tilelink_reset_i & 0xfeU))) {
        Verilated::overWidthError("tilelink_reset_i");}
    if (VL_UNLIKELY((vlSelf->master_a_opcode & 0xf8U))) {
        Verilated::overWidthError("master_a_opcode");}
    if (VL_UNLIKELY((vlSelf->master_a_param & 0xf8U))) {
        Verilated::overWidthError("master_a_param");}
    if (VL_UNLIKELY((vlSelf->master_a_size & 0xf0U))) {
        Verilated::overWidthError("master_a_size");}
    if (VL_UNLIKELY((vlSelf->master_a_source & 0xf0U))) {
        Verilated::overWidthError("master_a_source");}
    if (VL_UNLIKELY((vlSelf->master_a_mask & 0xf0U))) {
        Verilated::overWidthError("master_a_mask");}
    if (VL_UNLIKELY((vlSelf->master_a_corrupt & 0xfeU))) {
        Verilated::overWidthError("master_a_corrupt");}
    if (VL_UNLIKELY((vlSelf->master_a_valid & 0xfeU))) {
        Verilated::overWidthError("master_a_valid");}
    if (VL_UNLIKELY((vlSelf->master_d_ready & 0xfeU))) {
        Verilated::overWidthError("master_d_ready");}
    if (VL_UNLIKELY((vlSelf->slave_a_ready & 0xfcU))) {
        Verilated::overWidthError("slave_a_ready");}
    if (VL_UNLIKELY((vlSelf->slave_d_opcode & 0xc0U))) {
        Verilated::overWidthError("slave_d_opcode");}
    if (VL_UNLIKELY((vlSelf->slave_d_param & 0xf0U))) {
        Verilated::overWidthError("slave_d_param");}
    if (VL_UNLIKELY((vlSelf->slave_d_denied & 0xfcU))) {
        Verilated::overWidthError("slave_d_denied");}
    if (VL_UNLIKELY((vlSelf->slave_d_corrupt & 0xfcU))) {
        Verilated::overWidthError("slave_d_corrupt");}
    if (VL_UNLIKELY((vlSelf->slave_d_valid & 0xfcU))) {
        Verilated::overWidthError("slave_d_valid");}
}
#endif  // VL_DEBUG
