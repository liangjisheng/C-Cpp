
// VC++中，类的成员函数在调用之前，编译器生成的汇编代码将对象的首地址送入
// 寄存器ecx，因此如果通过内联汇编代码获取了类的非静态成员函数的入口地址
// 在调用函数之前，还应该将类对象的首地址送入寄存器ecx中，保证正确的调用

#include <iostream>

using std::cout;
using std::endl;

typedef void(*func)();


class A
{
	int i;
public:
	A() { i = 5; }
	void print() { cout << i << endl; }
};

void Invoke(A& a)
{
	func p;
	_asm{
		lea eax, A::print			// 将A中的print的地址送入eax寄存器中
		mov p, eax					// 将eax寄存器中的值赋给p
		// 去掉这条语句会在运行时抛出异常,内存的非法访问
		mov ecx, a					// 将对象地址送入ecx寄存器
	}
	p();
}

void Invoke1(A a)
{
	func p;
	_asm{
		lea eax, A::print
		mov p, eax
		// 将放在堆栈上的实参的副本的地址送入寄存器ecx中
		lea ecx, a
	}
	p();
}


int main()
{
	A a;
	Invoke(a);
	Invoke1(a);

	system("pause");
	return 0;
}