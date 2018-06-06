
// 两种情况下，需要对赋值操作符进行重载：一是赋值号两边的表达式类型不一样
// (且无法进行转换),一是需要进行深拷贝，赋值操作符只能通过类的成员函数的形
// 式进行重载，这就说明了，如果要将用户自定义类型的值传递给基本数据类型变量
// 只能使用类型转换机制，而不能利用重载

#include <iostream>

using namespace std;

class A
{
	int num;
public:
	A() 
	{
		cout << "default ctor" << endl;
		num = 0; 
	}
	A(int i) 
	{
		cout << "single int param ctor" << endl;
		num = i; 
	}
	A(const A& src) 
	{
		cout << "copy ctor" << endl;
		num = src.num;
	}
	A& operator=(const A& src)
	{
		cout << "operato= obj param" << endl;
		num = src.num;
		return *this;
	}
	A& operator=(int i)
	{
		cout << "operato= int param" << endl;
		num = i;
		return *this;
	}

	void show() { cout << num << endl; }
};


int main()
{
	// A a = 5;和a1 = 1这两条语句具有完全不同的含义
	A a = 5;
	a.show();
	A a1;
	a1 = 1;
	a1.show();

	system("pause");
	return 0;
}