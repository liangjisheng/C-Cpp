
// this指针在对象的构造函数中就可以使用了，构造函数是在对象获得内存空间后
// 对成员变量进行初始化的过程，下面使用一个全局指针管理新产生的某个类或其
// 派生类的对象

#include <iostream>

using std::cout;
using std::endl;

extern class A *pA;		// 声明变量pA

class A
{
public:
	A() { pA = this; }
	virtual void show() { cout << "in A" << endl; }
};

class B : public A
{
	int i;
public:
	B() { i = 5; }
	void show()
	{
		cout << "in B" << endl;
		cout << "i = " << i << endl;
	}
};

A *pA;			// 定义变量pA


int main()
{
	B b;
	pA = &b;
	pA->show();

	system("pause");
	return 0;
}