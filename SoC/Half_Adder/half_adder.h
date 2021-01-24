#include "systemc.h"
SC_MODULE(half_adder)
{
sc_in<bool> a, b;
sc_out<bool> sum, carry;


void compute_half_adder()
{
sum.write(a.read() ^ b.read());
carry.write(a.read() & b.read());
}

SC_CTOR(half_adder)
{
SC_METHOD(compute_half_adder);
sensitive <<a <<b;
}
};
