
// 虚函数一般被声明为公有的，这样实现虚函数调用会比较方便，但C++语言并没有
// 要求虚函数必须是公有的，将虚函数设置成私有和受保护的并不妨碍虚函数之间
// 的覆盖和虚函数调用

#include <iostream>

using namespace std;

class A
{
	virtual void f1() { cout << "A's f1()" << endl; }
public:
	void func() { f1(); }
};

class B : public A
{
public:
	void f1() { cout << "B's f1()" << endl; }
};


int main()
{
	A a;
	B b;
	A *pa;
	B *pb;

	pa = &a;
	pa->func();
	pa = &b;
	pa->func();
	pb = &b;
	pb->f1();

	system("pause");
	return 0;
}

