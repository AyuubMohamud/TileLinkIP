#include "VTileLink1toN.h"
#include "/opt/oss-cad-suite/share/verilator/include/verilated_vcd_c.h"
#include <cstdio>
uint64_t sim_time = 0;
void toggle_clock(VTileLink1toN* interconnect, VerilatedVcdC* trace) {
    interconnect->tilelink_clock_i = 1;
    interconnect->eval();
    trace->dump(sim_time);
    sim_time++;
    interconnect->tilelink_clock_i = 0;
    interconnect->eval();
    trace->dump(sim_time);
    sim_time++;
}

int main() {
    VTileLink1toN* tilelink = new VTileLink1toN;
    Verilated::traceEverOn(true);
    VerilatedVcdC* trace = new VerilatedVcdC;
    tilelink->trace(trace, 6);
    trace->open("waveform.vcd");
    tilelink->tilelink_reset_i = 1;
    toggle_clock(tilelink, trace);
    tilelink->tilelink_reset_i = 0;
    tilelink->master_a_address = 0x00002000;
    tilelink->master_a_corrupt = 0;
    tilelink->master_a_size = 2;
    tilelink->master_a_data = 0x0F0F0F0F;
    tilelink->master_a_valid = 1;
    tilelink->master_d_ready = 1;
    toggle_clock(tilelink, trace);
    tilelink->master_a_valid = 0;
    tilelink->slave_a_ready = 0b11;
    toggle_clock(tilelink, trace);
    tilelink->slave_d_valid = 0b01|0b10;
    tilelink->slave_d_size = 4;
    tilelink->slave_d_data = 0xe0e0e0e000000000|0x0f0f0f0f;
    toggle_clock(tilelink, trace);
    tilelink->slave_d_data = 0xf0f0f0f0;
    toggle_clock(tilelink, trace);
    toggle_clock(tilelink, trace);
    toggle_clock(tilelink, trace);
    tilelink->slave_d_valid = 0;
    toggle_clock(tilelink, trace);
    toggle_clock(tilelink, trace);
    toggle_clock(tilelink, trace);
    trace->close();
    delete tilelink;
    return 0;
}