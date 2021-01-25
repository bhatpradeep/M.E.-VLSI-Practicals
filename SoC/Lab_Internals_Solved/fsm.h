#include "systemc.h"

SC_MODULE(fsm)
{
	sc_in<bool>rst, clk, ri, ao;
	sc_in<sc_lv<8> > din;
	sc_out<sc_lv<8> > dout;		
	sc_out<bool>ro, ai, w, out;
	sc_uint<2>state, next_state;

	void update_state()			/* Function to update the state */
	{
		if(rst.read() == true)
			state = 0;
			
		
		else
			state = next_state;

	}

	void ns_logic()				/* Function to update the next state */
	{
		switch(state)			/* Determining the next state and o/p */
		{
			case 0: 
				if(ri.read())
				{
					next_state = 1;
	                out.write(true);
					w.write(1);  //setting write high
					dout.write(din.read());   // passing input to dout
				}
				else
				{
					next_state = 0;
					out.write(false);
					w.write(0);
					dout.write(dout.read()); //looping dout as it is
				}
				break;

			case 1:
				if((ri.read() & ao.read())==0)
				{
					next_state = 2;
					out.write(false);
					ro.write(1); // setting the ro high, indiacating value is written.
				}
				else if(!ri.read() & !ao.read() == 1)
				{
					next_state = 3; //if ri falls low, it goes to state 3
					out.write(false);
				}
				
				else if(ri.read() & !ao.read() == 1)
				{
					next_state = 1; //if this happens, it goes to state 1
					out.write(true);
				}
				
				else if(!ri.read() & ao.read() == 0)
				{
					next_state = 0; //if this happens, it goes to state 0
					out.write(false);
				}
				break;

			case 2:
				if(ro.read())
				{
					next_state = 2;
					out.write(false);
				}
				else
				{
					next_state = 0;
					out.write(false);
				}
				break;
				
			case 3:
				if(ao.read())
				{
					next_state = 3;
					out.write(false);
				}
				else
				{
					next_state = 0;
					out.write(false);
				}
				break;

			default:
				{
					next_state = 0;
					out.write(false);
				}
				break;
		}
		//cout <<sc_time_stamp()<<"\tSTATE: "<<state<<"\tNEXT_STATE: "<<next_state<<endl;
	}
		SC_CTOR(fsm)
		{
			SC_METHOD(update_state);
			sensitive<<clk.pos()<<rst;

			SC_METHOD(ns_logic);
			sensitive<<clk.pos()<<ao << ri <<rst;
		}
	
};
