
// 下面以一种特殊的方式访问基类的私有成员

#include <iostream>

using namespace std;

class A
{
	int i;
	void PrivateFunc()
	{ cout << "This is a private function of base class" << endl; }
public:
	A() { i = 5; }
};

class B : public A
{
public:
	void PrintBaseI()
	{
		int *p = reinterpret_cast<int*>(this);
		cout << *p << endl;
	}

	void UsePrivateFunction()
	{
		// 虽然类A中并没有提供访问私有成员函数PrivateFunc的共有函数
		// 但在程序的代码区依然存有函数PrivateFunc的代码，通过内联
		// 汇编获取该函数的入口地址
		void (*fun)();
		_asm{
			mov eax, A::PrivateFunc;
			mov fun, eax;
		}
		fun();
	}
};


int main()
{
	B b;
	b.PrintBaseI();
	b.UsePrivateFunction();

	system("pause");
	return 0;
}