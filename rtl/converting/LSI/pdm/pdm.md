PDM

PDM uses PDP to access the internal state of any processor implementing the protocol.

PDP:
PDP is a method of accessing the internal state of a processor.

Follwing are the list of signals:
Command channel:
c_valid: 1 bit, Master -> Slave
c_op: 4 bits, Master-> Slave
c_param: 5 bits, Master -> Slave (MUST be actual register file state, not speculative) so read from ROB side if an out of order CPU is used
c_addr: implementation defined, Master -> Slave

r_valid: 1 bit, Slave -> Master
r_result: 32 bit, Slave -> Master
r_code: 5 bit, Slave -> Master

c_valid being asserted signals the start of a command

c_op legend:
0000 - view pc
0001 - set pc
0010 - view register file state
0011 - set register file state
0100 - halt cpu
0101 - resume cpu
0110 - reset cpu + halt
1000 - read memory/io
1001 - store memory/io
1010 - cache flush
1011 - tlb flush
1100 - run instruction
1101 - state probe (NORMAL, HALTED)


c_param:
when read/store memory/io:
0000 - physical read/store byte
0001 - physical read/store 2 bytes
0010 - physical read/store 4 bytes
0011 - RESERVED
0100 - virtual read/store byte
0101 - virtual read/store 2 bytes
0110 - virtual read/store 4 bytes
0111 - Reserved
when tlb flush:
0000 - instruction tlb flush
0001 - data tlb flush
0010 - all tlb flush
when cache flush:
0000 - instruction cache flush
0001 - data cache flush
0010 - all flush

d_code:
00000 - Hit a breakpoint
1xxxx - RISC-V exceptions

All debug sessions must start with halt cpu to freeze the CPU and leave it to the debugger.
When in debug mode, all CPUs must ignore any interrupts

this interface is between a pdp enabled CPU and a pdm

A CPU MUST ALWAYS BE ABLE TO SERVICE A DEBUG REQUEST.

