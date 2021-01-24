#include<systemc.h>
#include "mux.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
sc_signal<bool> in0, in1, select, out;

mux2_1 mux("mux");
driver drive("driver");
monitor mon("monitor");

mux.in0(in0);
mux.in1(in1);
mux.sel(select);
mux.out(out);

drive.in0(in0);
drive.in1(in1);
drive.sel(select);

mon.in0(in0);
mon.in1(in1);
mon.sel(select);
mon.out(out);

sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, in0, "in0"); 
sc_trace(Tf, in1, "in1");
sc_trace(Tf, select, "select");
sc_trace(Tf, out, "out");
sc_start(50,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
