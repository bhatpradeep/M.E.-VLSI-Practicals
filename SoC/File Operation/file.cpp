#include <iostream>
#include <systemc.h>
#include <fstream>
#include <sstream>

using namespace std;

int sc_main(int agrc, char *argv[])
{
	sc_int<4> data;
	int val;
	/*ofstream fo;
	
	fo.open("text.txt");
	if(fo)
	{
		cout<<"file is opened in write"<<endl;
	}
	else
		cout << "file cannot be opened"<< endl;

	while(fo)
	{
		getline(cin, data);
		stringstream data1(data);
		data1>>val;
		if(val == -1)
				break;
		fo << data << endl;
	}

	fo.close();*/

	ifstream fin;

	fin.open("text.txt");
	if(fin)
	{
		cout<<"file is opened in read"<<endl;
	}
	else
		cout << "file cannot be opened"<< endl;

	while(fin)
	{
		//getline(fin,data);
		//stringstream data1(data);
		//data1>>val;
		fin >> data;
		cout << data.to_string(SC_HEX) << endl; 
		//cout << data << endl;
	}
	fin.close();

	return 0;
}