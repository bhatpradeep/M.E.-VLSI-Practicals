//monitor.h
#include "systemc.h"
SC_MODULE(monitor)
{
sc_in<bool> output, clk;
sc_in<sc_bv<4> > data_in;

void mon()
{
cout<< "Inputs: "<<data_in << " Output: "<< output <<endl;
}
SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive <<clk.pos();
}
};
