// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTileLink1toN.h for the primary calling header

#include "verilated.h"

#include "VTileLink1toN__Syms.h"
#include "VTileLink1toN__Syms.h"
#include "VTileLink1toN___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTileLink1toN___024root___dump_triggers__stl(VTileLink1toN___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTileLink1toN___024root___eval_triggers__stl(VTileLink1toN___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTileLink1toN__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTileLink1toN___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (0U == vlSelf->__VstlIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTileLink1toN___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
