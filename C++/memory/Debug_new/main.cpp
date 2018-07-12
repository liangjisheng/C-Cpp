
#include <iostream>
#include "debug_new.h"

using std::cout;
using std::endl;

int main()
{
	_CrtDumpMemoryLeaks(); 
	REG_DEBUG_NEW;

	char *p = new char[2];
	p[0] = 'a';
	p[1] = 'b';

	cout << "--End--" << endl;

	system("pause");
	return 0;
}