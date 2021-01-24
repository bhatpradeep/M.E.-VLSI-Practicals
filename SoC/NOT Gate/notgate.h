//notgate.h  bitwise
#include "systemc.h"
SC_MODULE(notgate){
sc_in<bool> a1;
sc_out<bool> d1;
void compute_not()
{
d1.write(!a1.read());
}
SC_CTOR(notgate)
{
SC_METHOD(compute_not);
sensitive <<a1;
}
};

