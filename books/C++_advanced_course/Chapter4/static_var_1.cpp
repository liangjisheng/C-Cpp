
// 在语法上，类的静态成员变量也可以继承，可以通过派生类的类名来访问基类中
// 声明的静态变量，这是不管是通过基类来访问还是通过派生类来访问，都是指的同样
// 的变量

#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	static int num;
};

int A::num = 10;

class B : public A
{
public:
	static void change() { num = 12; }
};

// int B::num = 14;				// 错误，不能后多次初始化静态变量


class A1
{
public:
	static int num;
};

int A1::num = 10;

class B1 : public A1
{
public:
	static double num;
	static void change() { num = 12; }
};

double B1::num = 14;


int main()
{
	cout << B::num << endl;
	B::change();
	cout << A::num << endl;
	cout << B::num << endl;

	cout << endl;
	cout << B1::num << endl;
	B1::change();
	cout << A1::num << endl;
	cout << B1::num << endl;

	system("pause");
	return 0;
}