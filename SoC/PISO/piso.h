#include "systemc.h"
SC_MODULE(piso){
sc_out<bool> output;
sc_in<bool> clk, shift;
sc_uint<4> temp;
sc_in<sc_bv<4> > data_in;
int i = 0;


void piso_operation()
{
 if(shift.read())
 {
 temp = data_in.read();
 output.write(temp[i].to_bool());
 if(i<4)
   i++;
 }
 else
  {
    temp = data_in.read();
    i = 0;
  }
}
SC_CTOR(piso)
{
SC_METHOD(piso_operation);
sensitive <<clk.pos();
}
};

