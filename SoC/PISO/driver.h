//driver.h
#include "systemc.h"
SC_MODULE(driver)
{
sc_out<sc_bv<4> > data_in;
sc_out<bool> shift;
sc_in<bool> clk;
void inputs()
{

data_in.write(5); 
shift.write(false);
wait(5,SC_NS);
shift.write(true);
wait(16,SC_NS);


}
SC_CTOR(driver)
{
SC_THREAD(inputs);
sensitive <<clk.pos();
}
};
