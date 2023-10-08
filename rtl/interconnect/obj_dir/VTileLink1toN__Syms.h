// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTILELINK1TON__SYMS_H_
#define VERILATED_VTILELINK1TON__SYMS_H_  // guard

#include "/opt/oss-cad-suite/share/verilator/include/verilated.h"

// INCLUDE MODEL CLASS

#include "VTileLink1toN.h"

// INCLUDE MODULE CLASSES
#include "VTileLink1toN___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VTileLink1toN__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VTileLink1toN* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VTileLink1toN___024root        TOP;

    // CONSTRUCTORS
    VTileLink1toN__Syms(VerilatedContext* contextp, const char* namep, VTileLink1toN* modelp);
    ~VTileLink1toN__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
