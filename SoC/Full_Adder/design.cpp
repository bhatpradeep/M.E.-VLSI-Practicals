#include "systemc.h"
#include "Full_adder.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
   sc_signal<bool> a, b, cin, sum, carry;
   
   full_adder fa("full_adder");
   driver drive("driver");
   monitor monit("monitor");

   fa.a(a);
   fa.b(b);
   fa.cin(cin);
   fa.sum(sum);
   fa.carry(carry);

   drive.a(a);
   drive.b(b);
   drive.cin(cin);

   monit.a(a);
   monit.b(b);
   monit.cin(cin);
   monit.sum(sum);
   monit.carry(carry);

   sc_trace_file*Tf;
   Tf=sc_create_vcd_trace_file("traces");
   sc_trace(Tf, a, "a");
   sc_trace(Tf, b, "b");
   sc_trace(Tf, cin, "cin");
   sc_trace(Tf, sum, "sum");
   sc_trace(Tf, carry, "carry");
   sc_start(40,SC_NS);
   sc_close_vcd_trace_file(Tf);
   return 0;
}
