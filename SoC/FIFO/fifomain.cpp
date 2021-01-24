#include"systemc.h"
#include"fifo.h"
int sc_main(int argc,char *argv[])
{
	fifo1 ff("exff");
	sc_start(10,SC_NS);
	return 0;
}