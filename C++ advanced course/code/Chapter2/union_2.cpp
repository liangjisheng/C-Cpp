
// union可以定义构造函数、成员函数、析构函数，但不能作为基类使用，
// 不能有虚函数，不能有静态数据成员或引用成员

#include <iostream>

using std::cout;
using std::endl;


class someClass
{
	int num;
public:
	void show() { cout << num << endl; }
};

// union成员的默认访问权限是public的，允许其它类的对象成为它的数据成员
// 但要求该对象的所属类不能定义构造函数、析构函数或者赋值操作符函数，
union A
{
	char c;
	int i;
	double d;
	someClass s;
};


union B
{
	char c;
	int i;
	double d;
	B() { d = 8.9; }
};


// 没有联合类型名，只是定义了一个变量u
union
{
	char c;
	int i;
	double d;
	void show() { cout << c << endl; }
}u = {'U'};


int main()
{
	// 只能为union的第一个成员提供初始化
	A a = {'A'};
	B b;
	cout << a.c << endl;
	cout << b.d << endl;
	a.s.show();
	u.show();

	// 匿名联合中的变量与其它局部变量具有相同的作用域级别
	// 匿名联合中不允许有成员函数，不能有私有或者保护成员
	// 全局匿名联合中的成员必须是全局或者静态变量
	union
	{
		int p;
		int q;
	};
	p = 3;
	cout << q << endl;

	system("pause");
	return 0;
}