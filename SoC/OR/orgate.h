#include "systemc.h"
SC_MODULE(orgate){
sc_in<bool> a1;
sc_in<bool> b1;
sc_in<bool> c1;
sc_out<bool> d1;
void compute_or()
{
d1.write(a1.read() || b1.read() || c1.read());
}
SC_CTOR(orgate)
{
SC_METHOD(compute_or);
sensitive <<a1 <<b1 <<c1;
}
};
