#include<systemc.h>
#include "counter.h"
#include "driver.h"
#include "monitor.h"

  int sc_main(int argc, char* argv[]){
  sc_signal<sc_bv<8> > count;
  sc_signal<bool> rst;
  sc_clock clk("clk",10,SC_NS,0.5);

  counter up("counter");
  driver drive("driver");
  monitor mon("monitor");
 
  up.count(count);
  up.clk(clk);
  up.rst(rst);

   drive.rst(rst);
   drive.clk(clk);

   mon.count(count);

   
   sc_trace_file *Tf;
   Tf=sc_create_vcd_trace_file("traces");
   sc_trace(Tf, count, "count");
   sc_trace(Tf, clk, "clk");
   sc_trace(Tf, rst, "rst");
   sc_start(60,SC_NS);
   sc_close_vcd_trace_file(Tf);
   return 0;
   }
