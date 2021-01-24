#include "systemc.h"
#include "sipo.h"
#include "driver.h"
#include "monitor.h"
int sc_main( int argc, char* argv[] ) 
{
sc_signal<bool> input;
sc_clock clk("clk",10,SC_NS,0.5);
sc_signal<sc_bv<4> > data_out;

sipo s("sipo");
driver drive("driver");
monitor mon("monitor");

s.input(input); 
s.clk(clk); 
s.data_out(data_out);

drive.input(input);
drive.clk(clk);  
 
mon.input(input);
mon.data_out(data_out);
mon.clk(clk);


//Waveform
sc_trace_file *Tf;
Tf= sc_create_vcd_trace_file("traces");
sc_trace(Tf, input, "input"); 
sc_trace(Tf, clk, "clk"); 
sc_trace(Tf, data_out, "data_out");
sc_start(80, SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
