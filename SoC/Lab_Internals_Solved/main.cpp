#include "systemc.h"
#include "driver.h"
#include "fsm.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<bool>rst, out;
	sc_signal<bool>ri, ai, ro, ao, w;
	sc_clock clk("clk", 10, SC_NS, 0.5);
	sc_signal<sc_lv<8> > din, dout;


	fsm f("state_machine");
	driver drive ("driver");


	f.rst(rst);
	f.clk(clk);
	f.out(out);
	f.ri(ri);
	f.ai(ai);
	f.ro(ro);
	f.ao(ao);
	f.w(w);
	f.din(din);
	f.dout(dout);

	drive.rst(rst);
	drive.din(din);
    drive.ri(ri);
    drive.ao(ao);
	drive.clk(clk);


	/* Waveform view */
	sc_trace_file *Tf;

	Tf = sc_create_vcd_trace_file("traces");

	sc_trace(Tf, rst, "rst");

	sc_trace(Tf, ri, "ri");
	sc_trace(Tf, ao, "ao");
	sc_trace(Tf, ai, "ai");
	sc_trace(Tf, ro, "ro");
	sc_trace(Tf, din, "din");
	sc_trace(Tf, out, "out");
	sc_trace(Tf, dout, "dout");
	sc_trace(Tf, w, "w");
	sc_trace(Tf, clk, "clk");


	sc_start(120,SC_NS);
	sc_close_vcd_trace_file(Tf);


	return 0;
}
