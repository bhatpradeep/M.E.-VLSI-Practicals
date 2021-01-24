#include<systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
  sc_signal<bool> d, q; // qbar;
  sc_clock clk("clk",10,SC_NS,0.5);
  dff df("dff");
  driver drive("driver");
  monitor mon("monitor");
 
  df.d(d);
 df.clk(clk);
 df.q(q);
// df.qbar(qbar);

  drive.d(d);
  drive.clk(clk);

   mon.d(d);
   //mon.clk(clk);
   mon.q(q);
  // mon.qbar(qbar);
   
   sc_trace_file *Tf;
   Tf=sc_create_vcd_trace_file("traces");
   sc_trace(Tf, d, "d");
   sc_trace(Tf, clk, "clk");
   sc_trace(Tf, q, "q");
  // sc_trace(Tf, qbar, "qbar");
   sc_start(60,SC_NS);
   sc_close_vcd_trace_file(Tf);
   return 0;
   }
