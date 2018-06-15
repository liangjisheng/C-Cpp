
#include <iostream>

using std::cout;
using std::endl;

// 模板元编程的目标是在编译是执行一些计算，而不是在运行是执行。
// 元编程基本上是C++之上的一个小型编程语言。

// 下面演示了在编译是计算一个数的阶乘，使用的模板递归，
// 需要一个递归模板和用于停止递归的基本模板，0的阶乘为1，用作基本模板

template<unsigned char f>
class Factorial
{
public:
	static const unsigned long long val = (f * Factorial<f - 1>::val);
};


// 基本模板的特化
template<>
class Factorial<0>
{
public:
	static const unsigned long long val = 1;
};


// test
int main()
{
	cout << Factorial<6>::val << endl;

	system("pause");
	return 0;
}