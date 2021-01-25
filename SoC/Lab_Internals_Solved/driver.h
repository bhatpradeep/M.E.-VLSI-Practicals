#include "systemc.h"

SC_MODULE(driver)
{
	sc_out<sc_lv<8> > din;
	sc_out<bool>rst, ri, ao;
	sc_in<bool>clk;

	void inputs()
	{
		rst.write(true);
		ri.write(true);
		ao.write(true);
		din.write(8);
		wait(10, SC_NS);

	    rst.write(false);
		ri.write(false);
		ao.write(false);
		din.write(7);
		wait(10, SC_NS);
		
	    rst.write(false);
		ri.write(false);
		ao.write(true);
		din.write(9);
		wait(10, SC_NS); 
		
	    rst.write(false);
		ri.write(true);
		ao.write(false);
		din.write(10);
		wait(10, SC_NS); 

	    rst.write(false);
		ri.write(true);
		ao.write(true);
		din.write(3);
		wait(10, SC_NS);

  
	}

	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive<<clk.pos();
	}
};
