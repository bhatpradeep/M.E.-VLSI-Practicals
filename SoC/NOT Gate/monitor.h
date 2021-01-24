//monitor.h
#include "systemc.h"
SC_MODULE(monitor)
{
sc_in<bool> a1,d1;
void mon()
{
cout<< "Inputs: "<<a1 << " Output: "<<d1 <<endl;
}
SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive <<a1 <<d1;
}
};
