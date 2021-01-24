#include<systemc.h>
#include"driver.h"
#include"monitor.h"
#include"counter.h"

int sc_main(int argc , char * argv[])
{
    sc_signal<sc_uint<2> >  count;
       sc_clock clk("clk", 10, SC_NS, 0.5); 
        
	sc_signal<bool> rst;

	
   driver drive("driver");
	monitor mon("monitor");
     Counter down("ready_set_go_counter");

     down.count(count);
     down.rst(rst);
     down.clk(clk);
     drive.clk(clk);
     drive.rst(rst);
   
           
    mon.clk(clk);
	mon.count(count);
  

  

	//waveform
	sc_trace_file *tf;

	tf = sc_create_vcd_trace_file("traces");
sc_trace(tf,clk,"clk");
    sc_trace(tf,rst,"rst");
	sc_trace(tf,count,"count");
	
	sc_start(60,SC_NS);
	sc_close_vcd_trace_file(tf);

	return 0;
}
