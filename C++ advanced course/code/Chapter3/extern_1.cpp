
// C++支持重载，而C不支持重载，由于这个原因，全局变量或函数被C++编译后在
// 符号库中的名字与C语言不同

#include <iostream>

using std::cout;
using std::endl;

int gvar = 5;

void testfunc() { gvar++; }

int testfunc(int para) { return para + 1; }


int main()
{
	cout << gvar << endl;
	testfunc();
	cout << gvar << endl;
	cout << testfunc(gvar) << endl;

	system("pause");
	return 0;
}