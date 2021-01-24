#include"systemc.h"

SC_MODULE(Counter)
{
       
		sc_in<bool> rst;
       sc_in<bool> clk;
		
	
       sc_out<sc_uint<2> >  count;
        sc_uint<2> temp;

	void compute_down_count()
	{
      
      if (rst.read()) 
      { 
         temp =3;
         count.write(temp);
      } 
      else 
       { 
      
         temp--;
         count.write(temp);
      
       
       }
	}
	
	SC_CTOR(Counter)
	{
		SC_METHOD(compute_down_count);
		sensitive<<clk.pos();
	}
};
