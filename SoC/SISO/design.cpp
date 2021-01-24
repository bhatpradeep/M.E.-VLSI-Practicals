#include "systemc.h"
#include "siso.h"
#include "driver.h"
#include "monitor.h"
int sc_main( int argc, char* argv[] ) 
{
sc_signal<bool> input, output;
sc_clock clk("clk",10,SC_NS,0.5);


siso s("siso");
driver drive("driver");
monitor mon("monitor");

s.output(output);
s.input(input); 
s.clk(clk); 
 

drive.input(input);
drive.clk(clk);  
 
mon.input(input);
mon.output(output); 
mon.clk(clk);


//Waveform
sc_trace_file *Tf;
Tf= sc_create_vcd_trace_file("traces");
sc_trace(Tf, input, "input"); 
sc_trace(Tf, output, "output");
sc_trace(Tf, clk, "clk"); 
sc_start(80, SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
