
/***********************************************************
 * @name: namespace_3.cpp
 * @brief: namespace
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:15:21
 * @version: 1.0
 **********************************************************/

#include <iostream>

using std::cout;
using std::endl;

namespace A 
{
	int a, b, c;
	int fun() { return a + b + c; }
}

namespace B 
{
	int a, b, c;
	int fun() { return a + b + c; }
}

namespace 
{
	int a, b, c;
	int fun() { return a + b + c; }
}

namespace aa = A;		//命名空间别名
namespace bb = B;

int main(int argc, char *argv[])
{
	std::cout << "hello,world" << std::endl;
	a = 9, b = 5, c = 6;
	cout << "fun()=" << fun() << endl;
	A::a = 1; A::b = 2; A::c = 3;
	cout << "A::fun()=" << A::fun() << endl;
	B::a = 2; B::b = 5; B::c = 8;
	cout << "B::fun()=" << B::fun() << endl;
	cout << "aa::fun()=" << aa::fun() << endl;
	cout << "bb::fun()=" << bb::fun() << endl;

	getchar();
	return 0;
}

