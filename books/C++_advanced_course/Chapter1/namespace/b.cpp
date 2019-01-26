
// 如果两个cpp文件中定义了相同的全局变量(函数)，就会发生重定义错误
// 如果将他们声明为全局静态变量(函数)，就可以避免重定义错误
// 出了可以使用static关键字避免全局变量(函数)的重定义错误之外，
// 还可以通过匿名名字空间的方式实现
// 在一个源文件中，可以定义多个匿名名字空间，在概念上同一源文件中的
// 多个匿名名字空间的内容会被合并在一起形成一个统一的匿名名字空间

#include <iostream>

using namespace std;

static int gvar = 4;

void show2() { cout << gvar << endl; }


namespace
{
	int gvar1 = 5;
	extern double dvar;
}


void show4()
{
	cout << gvar1 << endl;
	cout << dvar << endl;
}

namespace { double dvar = 7.6; }



int main()
{
	void show1();			// 必须先声明下show1()函数，否则会找不到
	show1();
	show2();
	cout << "\n\n";

	void show3();
	show3();
	show4();

	system("pause");
	return 0;
}

