
// 可以通过内联汇编的方式获得类的非静态成员函数的入口地址

#include <iostream>

using std::cout;
using std::endl;

void print() { cout << "External function" << endl; }

class A
{
public:
	// 如果A中的print()没有访问A中的数据成员，那么内联汇编获取此函数的地址
	// 是可以运行的，如果print()访问了A中的数据成员，就会引发运行是错误
	void print() { cout << "A's member function" << endl; }
};

typedef void(*func)();


int main()
{
	func p;
	void *v;
	v = (void *)print;
	p = (func)v;
	p();

	_asm{
		lea eax, A::print;
		mov v, eax;
	}
	p = (func)v;
	p();

	system("pause");
	return 0;
}