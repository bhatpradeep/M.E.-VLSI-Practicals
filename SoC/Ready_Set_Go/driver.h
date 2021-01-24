#include"systemc.h"

SC_MODULE(driver)
{
	
       
	sc_out<bool>  rst;
		sc_in<bool>  clk;
	
     
	void inputs()
	{
         
	    rst.write(true); wait(10,SC_NS);
 
        rst.write(false); wait(10,SC_NS);

		
	}

	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive<<clk.pos();
	}
};
