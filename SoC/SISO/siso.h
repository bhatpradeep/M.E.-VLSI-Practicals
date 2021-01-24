#include "systemc.h"
SC_MODULE(siso){
sc_in<bool> input, clk;
sc_out<bool> output;
sc_uint<4> temp, buffer = "0000";



void siso_operation()
{
 temp = buffer;
 temp[3] = temp[2];
 temp[2] = temp[1];
 temp[1] = temp[0];
 temp[0] = input;
 temp[0] = input;
 buffer = temp;
 

 output.write(temp[3].to_bool());
 
  
 
 
}
SC_CTOR(siso)
{
SC_METHOD(siso_operation);
sensitive <<input<< clk.pos();
}
};

