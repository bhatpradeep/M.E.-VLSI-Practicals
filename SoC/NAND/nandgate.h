#include "systemc.h"
SC_MODULE(nandgate){
sc_in<bool> a1;
sc_in<bool> b1;
sc_in<bool> c1;
sc_out<bool> d1;
void compute_nand()
{
d1.write(!(a1.read() && b1.read() && c1.read()));
}
SC_CTOR(nandgate)
{
SC_METHOD(compute_nand);
sensitive <<a1 <<b1 <<c1;
}
};
