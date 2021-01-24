#include "systemc.h"
SC_MODULE(sipo){
sc_in<bool> input, clk;
sc_uint<4> temp, buffer = "0000";
sc_out<sc_bv<4> > data_out;


void sipo_operation()
{
 temp = buffer;
 temp[3] = temp[2];
 temp[2] = temp[1];
 temp[1] = temp[0];
 temp[0] = input;
 temp[0] = input;
 buffer = temp;
 
 data_out.write(temp);
}
SC_CTOR(sipo)
{
SC_METHOD(sipo_operation);
sensitive <<input<< clk.pos();
}
};

