// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTileLink1toN.h for the primary calling header

#include "verilated.h"

#include "VTileLink1toN__Syms.h"
#include "VTileLink1toN__Syms.h"
#include "VTileLink1toN___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__ico(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG

void VTileLink1toN___024root___eval_triggers__ico(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (0U == vlSelf->__VicoIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTileLink1toN___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__act(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG

void VTileLink1toN___024root___eval_triggers__act(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tilelink_clock_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tilelink_clock_i__0))));
    vlSelf->__Vtrigprevexpr___TOP__tilelink_clock_i__0 
        = vlSelf->tilelink_clock_i;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTileLink1toN___024root___dump_triggers__act(vlSelf);
    }
#endif
}
