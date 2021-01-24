#include "systemc.h"
#include "notgate.h"
#include "driver.h"
#include "monitor.h"
int sc_main( int argc, char* argv[] ) 
{
sc_signal<bool> a1,d1;
notgate ngate("notgate");
driver drive("driver");
monitor mon("monitor");
ngate.a1(a1);  
ngate.d1(d1);
drive.a1(a1);  
mon.a1(a1); 
mon.d1(d1);

//Waveform
sc_trace_file*Tf;
Tf= sc_create_vcd_trace_file("traces");
sc_trace(Tf, a1, "a1"); 
sc_trace(Tf, d1, "d1");
sc_start(50,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
