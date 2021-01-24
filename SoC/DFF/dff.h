#include<systemc.h>
SC_MODULE(dff){
sc_in<bool> d;
sc_in<bool> clk;
sc_out<bool> q;
//sc_out<bool> qbar;

void compute_dff()
{

q.write(d.read());
//qbar.write(!(q.read()));
}

SC_CTOR(dff)
{
SC_METHOD(compute_dff);
sensitive_pos <<clk;
}
};
