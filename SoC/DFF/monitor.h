#include<systemc.h>
SC_MODULE(monitor){

sc_in<bool> d, q; // qbar;
void mon()
{
cout<< "Inputs: "<<d << "Output: "<<q <<endl;
}
SC_CTOR(monitor)
{
SC_METHOD(mon);
sensitive <<d <<q;
}
};
