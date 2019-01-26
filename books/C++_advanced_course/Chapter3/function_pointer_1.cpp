
// C++成员函数指针的使用

#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	int RetInt() { return 100; }
};

class B
{
public:
	int (A::*pFun)(void);			// 定义了一个指向类A中的成员函数指针
	void Print(A &obj)
	{
		int val = (obj.*pFun)();
		cout << "Val = " << val << endl;
	}
};


int main()
{
	A a;
	B b;
	// 为成员函数指针赋值的时候，并不需要制定函数所操作的对象，
	// 取某个类的成员函数的地址，必须显示使用取地址运算符&,这与外部函数取
	// 入口地址的要求不同，原因是避免与类的普通静态成员相混淆
	b.pFun = &A::RetInt;
	// 调用的时候指明给你参数所操作的对象
	b.Print(a);

	system("pause");
	return 0;
}