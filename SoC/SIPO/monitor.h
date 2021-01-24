//monitor.h
#include "systemc.h"
SC_MODULE(monitor)
{
sc_in<bool> input, clk;
sc_in<sc_bv<4> > data_out;

void mon()
{
cout<< "Inputs: "<<input << " Output: "<< data_out <<endl;
}
SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive <<clk.pos() <<input ;
}
};
