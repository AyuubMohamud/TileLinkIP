#include <cstdio>
#include "Vtilelink_xbr.h"
#include "/opt/oss-cad-suite/share/verilator/include/verilated_vcd_c.h"
uint64_t sim_time = 0;
void toggle_clk(Vtilelink_xbr* interconnect, VerilatedVcdC* trace) {
    interconnect->tilelink_clock_i = 1;
    interconnect->eval();
    trace->dump(sim_time);
    interconnect->tilelink_clock_i = 0;
    interconnect->eval();
    trace->dump(sim_time);
}

int main(int argc, char** argv) {
    Vtilelink_xbr* interconnect = new Vtilelink_xbr;
    Verilated::traceEverOn(true);
    VerilatedVcdC* trace = new VerilatedVcdC;
    interconnect->trace(trace, 6);
    trace->open("waveform.vcd");
    interconnect->eval();

    interconnect->a_opcode[0] = 1;
    interconnect->a_address[0] = 0x00001000;
    interconnect->a_corrupt[0] = 0;
    interconnect->a_data[0] = 64;
    interconnect->a_mask[0] = 0b1111;
    interconnect->a_param[0] = 0;
    interconnect->a_valid[0] = 1;
    interconnect->a_size[0] = 3;
    interconnect->a_source[0] = 0;
    
    toggle_clk(interconnect, trace);
    interconnect->a_valid[0] = 0;
    toggle_clk(interconnect, trace);

    trace->close();
    delete interconnect;
    return 0;
}