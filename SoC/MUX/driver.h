#include<systemc.h>

SC_MODULE(driver)
{
sc_out<bool> in0, in1, sel;

 void input()
 {
   in0.write(false);
   in1.write(false);
   sel.write(false);
   wait(5,SC_NS);
   
   in0.write(false);
   in1.write(true);
   sel.write(true);
   wait(5,SC_NS);
   
    in0.write(true);
   in1.write(false);
   sel.write(false);
   wait(5,SC_NS);
   
    in0.write(true);
   in1.write(true);
   sel.write(false);
   wait(5,SC_NS);
  }
  
  SC_CTOR(driver)
  {
  SC_THREAD(input);
  sensitive << in0 << in1 << sel;
  }
};



