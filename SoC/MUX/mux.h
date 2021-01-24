#include<systemc.h>

SC_MODULE(mux2_1)
{
sc_in<bool> in0, in1, sel;
sc_out<bool> out;

  void mux2_1_operation()
   {
     switch(sel)
     {
      case 0: out.write(in0.read());
      break;
      
      case 1: out.write(in1.read());
      break;
      
      default: cout << "Invalid Operation" <<endl;
      break;
      
      }
   }
   
   SC_CTOR(mux2_1)
   {
   SC_METHOD(mux2_1_operation);
   sensitive << in0 << in1 <<sel;
   }
};
