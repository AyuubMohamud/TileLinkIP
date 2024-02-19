#include <cstdio>
#include "VopenPolarisDMACore.h"
#include "/opt/oss-cad-suite/share/verilator/include/verilated_vcd_c.h"
int main() {
    auto* dut = new VopenPolarisDMACore;
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");
    dut->eval();
    dut->dma_a_ready = 1;
    dut->dma_d_valid = 1;
    dut->dmac_tx_i = 1;
    dut->dmac_bytes_tx_i = 32;
    dut->dmac_source_address_i = 4;
    dut->dmac_dest_address_i = 400;
    vluint64_t simtime = 0;
    dut->dmac_clock_i = 1;
    dut->eval();
    m_trace->dump(simtime);
    simtime++;
    dut->dmac_clock_i = 0;
    dut->eval();
    m_trace->dump(simtime);
    simtime++;
    dut->dmac_tx_i = 0;
    while (simtime < 300) {
        dut->dmac_clock_i^=1;
        dut->eval();
        m_trace->dump(simtime);
        simtime++;
    }
    m_trace->close();
    delete dut;
}