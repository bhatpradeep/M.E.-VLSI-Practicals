#include "systemc.h"
SC_MODULE(driver)
{
  sc_out<bool> a, b;
  void input()
  {
    a.write(false);
    b.write(false);
    wait(5, SC_NS);
 
    a.write(false);
    b.write(true);
    wait(5, SC_NS);

    a.write(true);
    b.write(false);
    wait(5, SC_NS);

    a.write(true);
    b.write(true);
    wait(5, SC_NS);
  }
   SC_CTOR(driver)
   {
      SC_THREAD(input);
      sensitive <<a <<b;
   }
};
