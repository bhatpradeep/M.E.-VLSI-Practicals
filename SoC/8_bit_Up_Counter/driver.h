#include<systemc.h>
SC_MODULE(driver)
{
sc_out<bool> rst;
sc_in<bool> clk;
void inputs()
{
rst.write(true);
//rst = true;
wait(5,SC_NS);

rst.write(false);
//rst = false;
wait(5,SC_NS);
}
SC_CTOR(driver)
{
SC_THREAD(inputs);
sensitive_pos << clk;
}
};
