# Autogenerated by LiteX / git: 9854c9f3
set -e

xst -ifn litesdcard_core.xst

netgen -ofmt verilog -w -sim litesdcard_core.ngc litesdcard_core_synth.v

ngdbuild  -uc litesdcard_core.ucf litesdcard_core.ngc litesdcard_core.ngd

map -ol high -w -o litesdcard_core_map.ncd litesdcard_core.ngd litesdcard_core.pcf
par -ol high -w litesdcard_core_map.ncd litesdcard_core.ncd litesdcard_core.pcf
bitgen -g Binary:Yes -w litesdcard_core.ncd litesdcard_core.bit
