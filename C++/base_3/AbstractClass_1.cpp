
#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	void f1();
	virtual void f2();
	virtual void f3() = 0;
	virtual ~A() {}
};

void A::f1() { cout << "A::f1()" << endl; }

void A::f2() { cout << "A::f2()" << endl; }

// 纯虚函数可以不用实现，就算实现了，也会被编译器忽略了
void A::f3() /* = 0 */ { cout << "A::f3()" << endl; }

class B : public A
{
public:
	void f1();
	virtual void f2();
	virtual void f3();
	virtual ~B() {}
};

void B::f1() { cout << "B::f1()" << endl; }

void B::f2() { cout << "B::f2()" << endl; }

void B::f3() { cout << "B::f3()" << endl; }


int main()
{
	A *pA = new B();
	pA->f1();
	pA->f2();
	pA->f3();

	delete pA;
	pA = NULL;

	system("pause");
	return 0;
}