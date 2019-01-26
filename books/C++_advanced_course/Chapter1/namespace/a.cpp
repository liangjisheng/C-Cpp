
#include <iostream>

using namespace std;

static int gvar = 8;

void show1() { cout << gvar << endl; }


namespace
{
	double dvar = 3.8;
	extern int gvar1;
}


namespace 
{
	int gvar1 = 91;
}


void show3()
{
	cout << gvar1 << endl;
	cout << dvar << endl;
}