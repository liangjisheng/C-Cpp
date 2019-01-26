
// 表面上看，有很多类的构造函数根本没有使用初始化列表，但实际上，以后写内容不管
// 有没有显示写进初始化列表，都会别强行加进去。这些内容包括：
// 1、如果该类是某个类的派生类，那么他的直接基类的构造函数一定要出现在初始化列表
// 中，要么是程序员显示的在初始化列表中调用直接基类的构造函数，否则编译器把直接
// 基类的默认构造函数插入到初始化列表中
// 2、如果该类包含其它类的对象作为数据成员，那么这些对象的初始化工作也一定要在
// 初始化列表中完成。要么是程序员显示的在初始化在列表中给出对象的构造形式，否则
// 编译器会在初始化列表中调用这些对象的默认构造函数来完成初始化

#include <iostream>

using std::cout;
using std::endl;

class A
{
	int num;
public:
	A() { cout << "In default constructor" << endl; }
	A(int i) { cout << "In user-defined constructor" << endl; num = i; }
	A& operator= (const A& a)
	{
		cout << "Using assignment" << endl;
		num = a.num;
		return *this;
	}
	void show() { cout << num << endl; }
};


class B
{
	A a;
public:
	B(int i);
	void show() { a.show(); }
};

// 先调用A(int)生成一个无名对象，再调用赋值运算符
B::B(int i) { a = A(i); }


class B1
{
	A a;
public:
	B1(int i);
	void show() { a.show(); }
};

// 先调用A(int)生成一个无名对象，再调用赋值运算符
B1::B1(int i) : a(i) {}


int main()
{
	B b(1);
	b.show();

	B1 b1(1);
	b1.show();

	system("pause");
	return 0;
}

