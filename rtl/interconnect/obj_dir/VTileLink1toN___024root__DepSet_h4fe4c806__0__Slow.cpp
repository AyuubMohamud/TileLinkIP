// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTileLink1toN.h for the primary calling header

#include "verilated.h"

#include "VTileLink1toN__Syms.h"
#include "VTileLink1toN___024root.h"

VL_ATTR_COLD void VTileLink1toN___024root___eval_static(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTileLink1toN___024root___eval_initial(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__tilelink_clock_i__0 
        = vlSelf->tilelink_clock_i;
}

VL_ATTR_COLD void VTileLink1toN___024root___eval_final(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTileLink1toN___024root___eval_triggers__stl(VTileLink1toN___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__stl(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___eval_stl(VTileLink1toN___024root* vlSelf);

VL_ATTR_COLD void VTileLink1toN___024root___eval_settle(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTileLink1toN___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTileLink1toN___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("TileLink1toN.sv", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTileLink1toN___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__stl(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 512> VTileLink1toN__ConstPool__TABLE_h86d9788e_0;
extern const VlUnpacked<SData/*11:0*/, 16> VTileLink1toN__ConstPool__TABLE_h942e113f_0;

VL_ATTR_COLD void VTileLink1toN___024root___stl_sequent__TOP__0(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    vlSelf->slave_d_ready = (3U & (~ (((IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld) 
                                       << 1U) | (IData)(vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld))));
    vlSelf->TileLink1toN__DOT__burst_ending = ((0U 
                                                == (IData)(vlSelf->TileLink1toN__DOT__burst_counters)) 
                                               & (IData)(vlSelf->TileLink1toN__DOT__lock));
    vlSelf->master_a_ready = (1U & (~ (IData)(vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld)));
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

VL_ATTR_COLD void VTileLink1toN___024root___eval_stl(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTileLink1toN___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__ico(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__act(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tilelink_clock_i)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__nba(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tilelink_clock_i)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTileLink1toN___024root___ctor_var_reset(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tilelink_clock_i = VL_RAND_RESET_I(1);
    vlSelf->tilelink_reset_i = VL_RAND_RESET_I(1);
    vlSelf->master_a_opcode = VL_RAND_RESET_I(3);
    vlSelf->master_a_param = VL_RAND_RESET_I(3);
    vlSelf->master_a_size = VL_RAND_RESET_I(4);
    vlSelf->master_a_source = VL_RAND_RESET_I(4);
    vlSelf->master_a_address = VL_RAND_RESET_I(32);
    vlSelf->master_a_mask = VL_RAND_RESET_I(4);
    vlSelf->master_a_data = VL_RAND_RESET_I(32);
    vlSelf->master_a_corrupt = VL_RAND_RESET_I(1);
    vlSelf->master_a_valid = VL_RAND_RESET_I(1);
    vlSelf->master_a_ready = VL_RAND_RESET_I(1);
    vlSelf->master_d_opcode = VL_RAND_RESET_I(3);
    vlSelf->master_d_param = VL_RAND_RESET_I(2);
    vlSelf->master_d_size = VL_RAND_RESET_I(4);
    vlSelf->master_d_source = VL_RAND_RESET_I(4);
    vlSelf->master_d_denied = VL_RAND_RESET_I(1);
    vlSelf->master_d_data = VL_RAND_RESET_I(32);
    vlSelf->master_d_corrupt = VL_RAND_RESET_I(1);
    vlSelf->master_d_valid = VL_RAND_RESET_I(1);
    vlSelf->master_d_ready = VL_RAND_RESET_I(1);
    vlSelf->slave_a_opcode = VL_RAND_RESET_I(6);
    vlSelf->slave_a_param = VL_RAND_RESET_I(6);
    vlSelf->slave_a_size = VL_RAND_RESET_I(8);
    vlSelf->slave_a_source = VL_RAND_RESET_I(8);
    vlSelf->slave_a_address = VL_RAND_RESET_Q(64);
    vlSelf->slave_a_mask = VL_RAND_RESET_I(8);
    vlSelf->slave_a_data = VL_RAND_RESET_Q(64);
    vlSelf->slave_a_corrupt = VL_RAND_RESET_I(2);
    vlSelf->slave_a_valid = VL_RAND_RESET_I(2);
    vlSelf->slave_a_ready = VL_RAND_RESET_I(2);
    vlSelf->slave_d_opcode = VL_RAND_RESET_I(6);
    vlSelf->slave_d_param = VL_RAND_RESET_I(4);
    vlSelf->slave_d_size = VL_RAND_RESET_I(8);
    vlSelf->slave_d_source = VL_RAND_RESET_I(8);
    vlSelf->slave_d_denied = VL_RAND_RESET_I(2);
    vlSelf->slave_d_data = VL_RAND_RESET_Q(64);
    vlSelf->slave_d_corrupt = VL_RAND_RESET_I(2);
    vlSelf->slave_d_valid = VL_RAND_RESET_I(2);
    vlSelf->slave_d_ready = VL_RAND_RESET_I(2);
    vlSelf->TileLink1toN__DOT__master_stalled = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__working_master_a_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(83, vlSelf->TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7);
    VL_RAND_RESET_W(83, vlSelf->TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4);
    vlSelf->TileLink1toN__DOT__slave_select = VL_RAND_RESET_I(2);
    vlSelf->TileLink1toN__DOT__working_slave_d_opcode = VL_RAND_RESET_I(6);
    vlSelf->TileLink1toN__DOT__working_slave_d_param = VL_RAND_RESET_I(4);
    vlSelf->TileLink1toN__DOT__working_slave_d_size = VL_RAND_RESET_I(8);
    vlSelf->TileLink1toN__DOT__working_slave_d_source = VL_RAND_RESET_I(8);
    vlSelf->TileLink1toN__DOT__working_slave_d_data = VL_RAND_RESET_Q(64);
    vlSelf->TileLink1toN__DOT__working_slave_d_valid = VL_RAND_RESET_I(2);
    vlSelf->TileLink1toN__DOT__block = VL_RAND_RESET_I(2);
    vlSelf->TileLink1toN__DOT__lock = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__locked_slave_select = VL_RAND_RESET_I(2);
    vlSelf->TileLink1toN__DOT__burst_counters = VL_RAND_RESET_I(12);
    vlSelf->TileLink1toN__DOT__bitscan = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__once = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__twoormore = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__burst = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__burst_ending = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__resp_size = VL_RAND_RESET_I(4);
    vlSelf->TileLink1toN__DOT__resp_denied = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__resp_corrupt = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__number_to_write = VL_RAND_RESET_I(12);
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7 = VL_RAND_RESET_Q(47);
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5 = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4 = VL_RAND_RESET_Q(47);
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3 = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7 = VL_RAND_RESET_Q(47);
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5 = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4 = VL_RAND_RESET_Q(47);
    vlSelf->TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3 = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__unnamedblk1__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->TileLink1toN__DOT__unnamedblk2__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->TileLink1toN__DOT__unnamedblk3__DOT__x = VL_RAND_RESET_I(32);
    vlSelf->TileLink1toN__DOT__unnamedblk4__DOT__n = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(83, vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_data);
    vlSelf->TileLink1toN__DOT__skidbuffer__DOT__held_vld = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__skidbuffer__DOT__hold_data = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data = VL_RAND_RESET_Q(47);
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data = VL_RAND_RESET_Q(47);
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld = VL_RAND_RESET_I(1);
    vlSelf->TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tilelink_clock_i__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
