
// 外部函数(静态函数)的地址可以赋给void*指针，但类的非静态成员函数不行，
// 类的非静态成员函数的特殊性在于其中的代码要修改类的对象的状态，因此
// 在函数调用之前，必须生成该类的对象，并且将对象的地址传递给该函数。
// 调用类的非静态成员函数有两个前提条件：已知函数的入口地址和已知类对象
// 的首地址，如果可以换将类的非静态成员函数的入口地址赋给void*型指针
// 那么就可以进一步将void*型的指针转换成函数指针，从而抛开对象的地址而
// 直接调用类的非静态成员函数，这样做破坏了面向对象的封装性

#include <iostream>

using std::cout;
using std::endl;

void print() { cout << "External function" << endl; }

class A
{
public:
	void print() { cout << "A's member function" << endl; }
};

typedef void(*func)();


int main()
{
	func p;
	void *v;
	v = (void*)&print;
	p = (func)v;
	p();

	// 不能将类的非静态成员函数的地址转换为void*类型
	// v = (void*)&A::print;			// error
	// p = (func)v;
	// p();

	system("pause");
	return 0;
}