
#include <iostream>

using std::cout;
using std::endl;

class A
{
	int num;
public:
	A() { num = 5; }
	void show() { cout << this << endl; cout << num << endl; }
};

class B : public A
{
	double dig;
public:
	virtual void f() {}
	void showAddr() { cout << this << endl; } 
};


int main()
{
	B b;
	cout << &b << endl;
	cout << (void*)&b << endl;
	b.showAddr();					// 显示的是b的首地址

	cout << "\n\nBase class address:";
	A *p = &b;
	// 显示的是基类的首地址，和b的首地址是不一样的，且包含在b的首地址中
	cout << p << endl;
	p->show();			// 显示基类的地址
	b.show();			// 显示的也是基类的地址


	system("pause");
	return 0;
}