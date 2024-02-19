// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VopenPolarisDMACore.h for the primary calling header

#include "verilated.h"

#include "VopenPolarisDMACore__Syms.h"
#include "VopenPolarisDMACore__Syms.h"
#include "VopenPolarisDMACore___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__ico(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG

void VopenPolarisDMACore___024root___eval_triggers__ico(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (0U == vlSelf->__VicoIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VopenPolarisDMACore___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VopenPolarisDMACore___024root___dump_triggers__act(VopenPolarisDMACore___024root* vlSelf);
#endif  // VL_DEBUG

void VopenPolarisDMACore___024root___eval_triggers__act(VopenPolarisDMACore___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VopenPolarisDMACore__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VopenPolarisDMACore___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->dmac_clock_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__dmac_clock_i__0))));
    vlSelf->__Vtrigprevexpr___TOP__dmac_clock_i__0 
        = vlSelf->dmac_clock_i;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VopenPolarisDMACore___024root___dump_triggers__act(vlSelf);
    }
#endif
}
