#include "systemc.h"
#include "piso.h"
#include "driver.h"
#include "monitor.h"
int sc_main( int argc, char* argv[] ) 
{
sc_signal<bool> output, shift;
sc_clock clk("clk",5,SC_NS,0.5);
sc_signal<sc_bv<4> > data_in;

piso s("piso");
driver drive("driver");
monitor mon("monitor");

s.output(output); 
s.shift(shift);
s.clk(clk); 
s.data_in(data_in);

drive.data_in(data_in);
drive.clk(clk);  
drive.shift(shift);
 
mon.output(output);
mon.data_in(data_in);
mon.clk(clk);


//Waveform
sc_trace_file *Tf;
Tf= sc_create_vcd_trace_file("traces");
sc_trace(Tf, output, "output"); 
sc_trace(Tf, clk, "clk"); 
sc_trace(Tf, data_in, "data_in");
sc_start(60, SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
