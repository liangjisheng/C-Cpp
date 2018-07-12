
// C++类的非静态成员函数默认都提供了this指针，调用非静态成员函数时，编译器
// 会自动把this指针加到函数形参里去，正常情况下，静态函数是不能访问非静态
// 成员变量的，但在回调函数下，就会有些问题
// C语言里主要体现的就是回调函数，C++里面就是仿函数

#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	A() { m_a = 0; }
	// 只能访问m_staticA，不能访问m_a
	static void test() { m_staticA += 1; }
	void NoStatic() { m_a += 1; }
	int GetNum() { return m_a; }
	static int m_staticA;
private:
	int m_a;
};

int A::m_staticA = 0;

typedef void (A::*FunPtr)();
typedef void (*FunPtrNoMemFun)();


int main()
{
	A a;

	FunPtr p = &A::NoStatic;
	(a.*p)();
	cout << a.GetNum() << endl;

	FunPtrNoMemFun pNo = &A::test;
	pNo();
	cout << A::m_staticA << endl;

	system("pause");
	return 0;
}