//driver.h
#include "systemc.h"
SC_MODULE(driver)
{
sc_out<bool> input;
sc_in<bool> clk;
void inputs()
{

input.write(true);
wait(10,SC_NS);
input.write(false);
wait(10,SC_NS);
input.write(true);
wait(10,SC_NS);
input.write(false);
wait(10,SC_NS);


}
SC_CTOR(driver)
{
SC_THREAD(inputs);
sensitive <<clk.pos() <<input;
}
};
