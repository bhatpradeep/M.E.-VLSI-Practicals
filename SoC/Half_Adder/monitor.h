#include "systemc.h"
SC_MODULE(monitor)
{
  sc_in<bool> a, b, sum, carry;
  void mon()
  {
    cout << "inputs" << a << b << "Outputs" << sum << carry << endl;
  }
  
  SC_CTOR(monitor)
  {
    SC_METHOD(mon);
    sensitive << a << b << sum << carry;
  }
};
