
// 一个类中的私有静态成员变量和公共静态成员变量

#include <iostream>

using std::cout;
using std::endl;

class A
{
private:
	static int pri_sta;		// 声明
public:
	static int pub_sta;		// 声明
	// 非静态成员函数可以访问非静态成员变量和静态成员变量，因为第一个参数
	// 默认是this;非静态成员函数访问静态成员变量时，静态成员变量一定要有
	// 定义，而不能只是声明；而静态成员函数只能访问静态成员变量，不能访问
	// 非静态成员变量，因为静态成员的第一个参数不是this指针
	int GetPriSta() const { return pri_sta; }
};

int A::pri_sta = 1;		// 定义(定义相当于分配内存),并初始化
int A::pub_sta = 2;		// 定义(定义相当于分配内存),并初始化

int main()
{
	// A::pri_sta = 3;		// error can not access private member

	A a;
	cout << a.GetPriSta() << endl;

	system("pause");
	return 0;
}