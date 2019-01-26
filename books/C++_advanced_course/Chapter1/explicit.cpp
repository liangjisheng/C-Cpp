
// explicit:禁止隐式调用类的单参数构造函数，实际上有两种情况：一是禁止隐式
// 调用拷贝构造函数，二是禁止类对象之间的隐式转换。类对象之间的隐式转换值利用
// 一个已经存在的其它类型的对象来创建本类的新对象，而不显示调用本类的构造函数
// 单参数的构造函数有被称为转换构造函数

#include <iostream>

using std::cout;
using std::endl;


class A
{
	int num;
public:
	A();
	A(int num);
	A(const A& src);
	friend void Show(const A& src);
};

A::A()
{
	cout << "default constructor" << endl;
	num = 0;
}

A::A(int num)
{
	cout << "single parameter constructor" << endl;
	this->num = num;
}

A::A(const A& src)
{
	cout << "copy constructor" << endl;
	num = src.num;
}

void Show(const A& src)
{
	cout << src.num << endl;
}


// 在类的定义中，在任何一个单参数构造函数前加explicit
// 就可以禁止对该构造函数的隐式调用
class B
{
	int num;
public:
	B();
	explicit B(int num);				// 禁止隐式调用
	explicit B(const B& src);			// 禁止隐式调用
	friend void Show1(const B& src);
};

B::B()
{
	cout << "defBult constructor" << endl;
	num = 0;
}

B::B(int num)
{
	cout << "single parameter constructor" << endl;
	this->num = num;
}

B::B(const B& src)
{
	cout << "copy constructor" << endl;
	num = src.num;
}

void Show1(const B& src)
{
	cout << src.num << endl;
}


int main()
{
	A a1 = 37;
	Show(a1);
	A a2 = a1;	
	Show(a2);
	Show(47);
	cout << endl;

	// 禁止隐式调用会产生下面的三处编译问题
	//B b1 = 37;			// error
	B b1(37);				// ok
	Show1(b1);
	//B b2 = b1;			// error
	B b2(b1);				// ok
	Show1(b2);
	//Show1(47);			// error
	Show1(B(47));			// ok

	system("pause");
	return 0;
}