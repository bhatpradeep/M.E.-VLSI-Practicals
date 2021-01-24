#include<systemc.h>
SC_MODULE(driver)
{
sc_out<bool> d;
sc_in<bool> clk;
void inputs()
{
d.write(false);

wait(5,SC_NS);

d.write(true);

wait(5,SC_NS);
}
SC_CTOR(driver)
{
SC_THREAD(inputs);
sensitive_pos << clk;
}
};
