#include<systemc.h>
SC_MODULE(counter){
sc_out<sc_bv<8> > count;
sc_in<bool> clk, rst;
sc_uint<8> data;


void compute_up_count()
{
  if(rst.read())
  {
    data = true;
  }
  else
  {
    data = data - 1;
  }

count.write(data);

}

SC_CTOR(counter)
{
SC_METHOD(compute_up_count);
sensitive_pos <<clk;
}
};
