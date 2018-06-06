
// 在构造函数中调用虚函数，对虚函数的调用实际上是实调用，这是虚函数
// 实调用的另一个例子，从概念上说，在一个对象的构造函数运行完毕之前
// 这个对象还没有完全诞生，所以在构造函数中调用虚函数，实际上都是实调用

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show() { cout << "in A" << endl; }
	A() { show(); }
};

class B : public A
{
public:
	virtual void show() { cout << "in B" << endl; }
};

int main()
{
	A a;
	B b;

	system("pause");
	return 0;
}