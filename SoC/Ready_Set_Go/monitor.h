#include<systemc.h>

SC_MODULE(monitor)
{
 sc_in<bool> clk;
        sc_in<sc_uint<2> > count;

	void mon()
	{	
		switch(count.read())
		{
		case 3: cout << "Counter value:"<< count << " -> Ready"<<endl;break;
		case 2: cout << "Counter value:"<< count << " -> Set"<<endl;break;
	 case 1: cout << "Counter value:"<< count << " -> Go"<<endl;
		break;
		}
		
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive << clk.pos();
	}
};
