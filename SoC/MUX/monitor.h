#include<systemc.h>

SC_MODULE(monitor)
{
sc_in<bool> in0, in1, sel, out;

void mon()
{
cout<< "Input0: "<< in0 << "Input1:"<< in1<< "Selcect:" << sel << "Output: "<< out <<endl;
}

SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive << in0 <<in1 << sel << out;
}
};
