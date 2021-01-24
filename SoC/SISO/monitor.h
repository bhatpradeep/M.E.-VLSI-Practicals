//monitor.h
#include "systemc.h"
SC_MODULE(monitor)
{
sc_in<bool> output, input, clk;

void mon()
{
cout<< "Inputs: "<<input << " Output: "<<output  <<endl;
}
SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive <<clk.pos() <<input <<output;
}
};
