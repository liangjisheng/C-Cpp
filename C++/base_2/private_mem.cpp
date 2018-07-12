
// 在类的继承中，基类的私有成员在派生类中是不可见的，这种不可见是指在派生类的
// 成员函数，或者通过派生类对象(指针、引用)不能直接访问他们，但是不能直接访问
// 并不代表不能访问，在派生类中可以通过调用基类的公有函数的方式间接的访问基类
// 私有成员，包括私有成员变量和有成员函数

#include <iostream>

using namespace std;

class A
{
	int i;
	void PrivateFunc() 
	{ cout << "This is a private function of base class" << endl; } 
public:
	A() { i = 5; }
	int GetI() { return i; }
	void UsePrivateFunc() { PrivateFunc(); }
};

class B : public A
{
public:
	void PrintBaseI() { cout << GetI() << endl; }
	void UsePrivateFunction() { UsePrivateFunc(); }
};

int main()
{
	B b;
	b.PrintBaseI();
	b.UsePrivateFunction();

	system("pause");
	return 0;
}