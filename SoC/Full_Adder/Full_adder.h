#include "systemc.h"
SC_MODULE(full_adder)
{
sc_in<bool> a, b, cin;
sc_out<bool> sum, carry;


void compute_full_adder()
{
sum.write(a.read() ^ b.read() ^ cin.read());
carry.write((a.read() & b.read()) | (b.read() & cin.read()) | (cin.read() & a.read()));
}

SC_CTOR(full_adder)
{
SC_METHOD(compute_full_adder);
sensitive <<a <<b <<cin;
}
};
