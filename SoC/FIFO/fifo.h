#include"systemc.h"
SC_MODULE(fifo1){
	sc_fifo<int>packet_fifo;
	int val;
	void fiforead(void){
		
		for (;;)
		{
			wait(3,SC_NS);
			packet_fifo.read(val);
			cout<<sc_time_stamp()<<":read"<<val<<endl;
			cout<<sc_time_stamp()<<"no of data in fifo"<<packet_fifo.num_available()<<endl;
		}
	}
	void fifowrite(void){
		for (;;)
		{
			
		wait(2,SC_NS);
		val++;
		packet_fifo.write(val);
		cout<<sc_time_stamp()<<":write"<<val<<endl;
		cout<<sc_time_stamp()<<"no of free slots in fifo"<<packet_fifo.num_free()<<endl;
		}
	}
SC_CTOR(fifo1):packet_fifo(25){
	SC_THREAD(fifowrite);
	SC_THREAD(fiforead);
	}	
};