
// 在实际应用中，绝大多数的虚调用的确是借助于指针或引用实现的
// 但是这并不说明其它方式就一定不能实现虚调用

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show() { cout << "in A" << endl; }
	void callfunc() { show(); }
};

class B : public A
{
public:
	virtual void show() { cout << "in B" << endl; }
};

int main()
{
	B b;
	// 函数调用b.callfunc()，但实际执行的是A::callfunc()，show()是一个虚函数
	// 这个一个虚调用，它是在运行时才决定使用派生类中的虚函数还是基类中的虚函数
	b.callfunc();

	system("pause");
	return 0;
}