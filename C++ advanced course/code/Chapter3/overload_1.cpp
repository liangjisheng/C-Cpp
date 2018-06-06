
// 不同作用域中定义的函数可能形成隐藏，但不会形成重载，C++中严格规定只有在
// 同一作用域中定义的函数才能形成重载

#include <iostream>

using std::cout;
using std::endl;

void func(char *s) 
{ cout << "This is a global function with name" << s << endl; }

class A
{
	void func() { cout << "This is a member function of A" << endl; }
public:
	void useFunc()
	{
		// func("test");			// A::func()隐藏了外部函数func(char*)
		func();
		::func("test");
	}

	// 类的静态成员函数与实例成员函数可以形成重载
	static void func(int i) 
	{ cout << "A::func() parameter is " << i << endl; }
};


class B : public A
{
public:
	void useFunc(int i) { cout << "In B's useFunc(), i = " << i << endl; }
};


int main()
{
	A::func(4);
	A a;
	a.useFunc();
	B b;
	// b.useFunc();					// A::useFunc()被B::useFunc()隐藏
	b.useFunc(6);

	system("pause");
	return 0;
}