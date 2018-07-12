
// static函数是没有虚函数的，static函数实际上是加了访问控制的全局函数
// 全局函数是没有虚函数的
// 派生类的friend函数可以访问派生类本身的一切变量，包括从父类继承下来的
// protected域中的变量，但对于父类来说，它并不是friend的

#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	static int a;
	static void fun() { cout << "in class Base" << endl; }
};

int Base::a = 100;

class Derived : public Base
{
public:
	static void fun() { cout << "in class Derived" << endl; }
};

class Derived1 : public Derived
{
public:
	static void fun() { cout << "in class Derived1" << endl; }
};

int main()
{
	// 派生类继承下来基类的静态变量，是在同一个地址处的，只有一处对象
	// 派生类的静态变量的地址和基类的是一样的
	cout << "静态数据成员可以被继承" << endl;
	cout << "Base static var: " << Base::a << endl;
	cout << "address: " << &Base::a << endl;
	cout << "Derived static var: " << Derived::a << endl;
	cout << "address: " << &Derived::a << endl;

	Base::fun();				// Base
	Derived::Base::fun();		// Base
	Derived::fun();				// Derived
	Derived1::Base::fun();		// Base
	Derived1::Derived::fun();	// Derived
	Derived1::fun();			// Derived1

	system("pause");
	return 0;
}