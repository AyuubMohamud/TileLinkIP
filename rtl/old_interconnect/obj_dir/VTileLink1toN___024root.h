// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTileLink1toN.h for the primary calling header

#ifndef VERILATED_VTILELINK1TON___024ROOT_H_
#define VERILATED_VTILELINK1TON___024ROOT_H_  // guard

#include "/opt/oss-cad-suite/share/verilator/include/verilated.h"


class VTileLink1toN__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTileLink1toN___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(tilelink_clock_i,0,0);
        VL_IN8(tilelink_reset_i,0,0);
        VL_IN8(master_a_opcode,2,0);
        VL_IN8(master_a_param,2,0);
        VL_IN8(master_a_size,3,0);
        VL_IN8(master_a_source,3,0);
        VL_IN8(master_a_mask,3,0);
        VL_IN8(master_a_corrupt,0,0);
        VL_IN8(master_a_valid,0,0);
        VL_OUT8(master_a_ready,0,0);
        VL_OUT8(master_d_opcode,2,0);
        VL_OUT8(master_d_param,1,0);
        VL_OUT8(master_d_size,3,0);
        VL_OUT8(master_d_source,3,0);
        VL_OUT8(master_d_denied,0,0);
        VL_OUT8(master_d_corrupt,0,0);
        VL_OUT8(master_d_valid,0,0);
        VL_IN8(master_d_ready,0,0);
        VL_OUT8(slave_a_opcode,5,0);
        VL_OUT8(slave_a_param,5,0);
        VL_OUT8(slave_a_size,7,0);
        VL_OUT8(slave_a_source,7,0);
        VL_OUT8(slave_a_mask,7,0);
        VL_OUT8(slave_a_corrupt,1,0);
        VL_OUT8(slave_a_valid,1,0);
        VL_IN8(slave_a_ready,1,0);
        VL_IN8(slave_d_opcode,5,0);
        VL_IN8(slave_d_param,3,0);
        VL_IN8(slave_d_size,7,0);
        VL_IN8(slave_d_source,7,0);
        VL_IN8(slave_d_denied,1,0);
        VL_IN8(slave_d_corrupt,1,0);
        VL_IN8(slave_d_valid,1,0);
        VL_OUT8(slave_d_ready,1,0);
        CData/*0:0*/ TileLink1toN__DOT__master_stalled;
        CData/*0:0*/ TileLink1toN__DOT__working_master_a_valid;
        CData/*1:0*/ TileLink1toN__DOT__slave_select;
        CData/*5:0*/ TileLink1toN__DOT__working_slave_d_opcode;
        CData/*3:0*/ TileLink1toN__DOT__working_slave_d_param;
        CData/*7:0*/ TileLink1toN__DOT__working_slave_d_size;
        CData/*7:0*/ TileLink1toN__DOT__working_slave_d_source;
        CData/*1:0*/ TileLink1toN__DOT__working_slave_d_valid;
        CData/*1:0*/ TileLink1toN__DOT__block;
        CData/*0:0*/ TileLink1toN__DOT__lock;
        CData/*1:0*/ TileLink1toN__DOT__locked_slave_select;
        CData/*0:0*/ TileLink1toN__DOT__bitscan;
        CData/*0:0*/ TileLink1toN__DOT__once;
        CData/*0:0*/ TileLink1toN__DOT__twoormore;
        CData/*0:0*/ TileLink1toN__DOT__burst;
        CData/*0:0*/ TileLink1toN__DOT__burst_ending;
        CData/*3:0*/ TileLink1toN__DOT__resp_size;
        CData/*0:0*/ TileLink1toN__DOT__resp_denied;
        CData/*0:0*/ TileLink1toN__DOT__resp_corrupt;
        CData/*0:0*/ TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber5;
        CData/*0:0*/ TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber3;
        CData/*0:0*/ TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber5;
        CData/*0:0*/ TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber3;
        CData/*0:0*/ TileLink1toN__DOT__skidbuffer__DOT__held_vld;
        CData/*0:0*/ TileLink1toN__DOT__skidbuffer__DOT__hold_data;
        CData/*0:0*/ TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_vld;
        CData/*0:0*/ TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__hold_data;
        CData/*0:0*/ TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_vld;
        CData/*0:0*/ TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__hold_data;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tilelink_clock_i__0;
    };
    struct {
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ TileLink1toN__DOT__burst_counters;
        SData/*11:0*/ TileLink1toN__DOT__number_to_write;
        VL_IN(master_a_address,31,0);
        VL_IN(master_a_data,31,0);
        VL_OUT(master_d_data,31,0);
        VlWide<3>/*82:0*/ TileLink1toN__DOT____Vcellinp__skidbuffer____pinNumber7;
        VlWide<3>/*82:0*/ TileLink1toN__DOT____Vcellout__skidbuffer____pinNumber4;
        IData/*31:0*/ TileLink1toN__DOT__unnamedblk1__DOT__n;
        IData/*31:0*/ TileLink1toN__DOT__unnamedblk2__DOT__n;
        IData/*31:0*/ TileLink1toN__DOT__unnamedblk3__DOT__x;
        IData/*31:0*/ TileLink1toN__DOT__unnamedblk4__DOT__n;
        VlWide<3>/*82:0*/ TileLink1toN__DOT__skidbuffer__DOT__held_data;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
        VL_OUT64(slave_a_address,63,0);
        VL_OUT64(slave_a_data,63,0);
        VL_IN64(slave_d_data,63,0);
        QData/*63:0*/ TileLink1toN__DOT__working_slave_d_data;
        QData/*46:0*/ TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber7;
        QData/*46:0*/ TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer____pinNumber4;
        QData/*46:0*/ TileLink1toN__DOT____Vcellinp__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber7;
        QData/*46:0*/ TileLink1toN__DOT____Vcellout__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer____pinNumber4;
        QData/*46:0*/ TileLink1toN__DOT__skidbufferInstantiation__BRA__0__KET____DOT__slave_skidbuffer__DOT__held_data;
        QData/*46:0*/ TileLink1toN__DOT__skidbufferInstantiation__BRA__1__KET____DOT__slave_skidbuffer__DOT__held_data;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTileLink1toN__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTileLink1toN___024root(VTileLink1toN__Syms* symsp, const char* v__name);
    ~VTileLink1toN___024root();
    VL_UNCOPYABLE(VTileLink1toN___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
