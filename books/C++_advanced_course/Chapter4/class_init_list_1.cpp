
// 对于普通数据成员而言，使用初始化列表和在构造函数体内赋初值效果是一样的
// 另外一些情况下，只能使用初始化列表对成员进行初始化，例如，数据成员是
// 引用、常变量、类对象(该类没有提供不带参数的构造函数)等

#include <iostream>

using std::cout;
using std::endl;


class A
{
	int num;
public:
	A(int i) { num = i; }
	void show() { cout << num << endl; }
};


class B
{
	int &r;
	const double PI;
	A a;
public:
	B(int i);
	void show() 
	{
		cout << r << endl;
		cout << PI << endl;
		a.show();
	}
};

int e = 5;

// 不能用参数i初始化引用r，否则输出的是一个随机数
B::B(int i) : r(e), PI(3.1415926), a(i) {}

//B::B(int i)
//{
//	r = e;				// 这是为引用赋值，并不是初始化
//	PI = 3.1415926;		// 常量的值不允许改变
//	a = A(i);			// 在调用类B的构造函数之前会先调用类A的构造函数A(),
//						// 而类A的无参数的构造函数并没有定义
//}

int main()
{
	// 定义了一个无名的对象，并调用show()成员函数
	B(1).show();

	system("pause");
	return 0;
}