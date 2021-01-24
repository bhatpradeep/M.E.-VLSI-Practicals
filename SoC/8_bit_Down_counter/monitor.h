#include<systemc.h>
SC_MODULE(monitor){

sc_in<sc_bv<8> > count;
void mon()
{
cout<< "Down Counter: "<<count <<endl;
}
SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive <<count;
}
};
