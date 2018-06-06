
// 不允许为基本数据类型定义其他的操作，对操作符进行重载，其操作数中至少要有
// 一个用户自定义的类类型或枚举类型，

#include <iostream>

using std::cout;
using std::endl;

enum Week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saterday };

Week operator+(Week day, int i)
{
	int n = (int)day;
	n += i;
	n %= 7;
	return (Week)n;
}


// 计算某一天的若干天之后是星期几
void PrintDay(Week day)
{
	switch(day)
	{
	case Sunday: cout << "Sunday" << endl; break;
	case Monday: cout << "Monday" << endl; break;
	case Tuesday: cout << "Tuesday" << endl; break;
	case Wednesday: cout << "Wednesday" << endl; break;
	case Thursday: cout << "Thursday" << endl; break;
	case Friday: cout << "Friday" << endl; break;
	case Saterday: cout << "Saterday" << endl; break;
	default: break;
	}
}


class A
{
	int m;
public:
	A(int i) { m = i; }
	void show() { cout << m << endl; }
};


class B
{
	int n;
public:
	operator A() { return A(n); }
	B(int i) { n = i; }
};


int main()
{
	cout << Sunday << endl;
	cout << Monday << endl;
	cout << Tuesday << endl;
	cout << Wednesday << endl;
	cout << Thursday << endl;
	cout << Friday << endl;
	cout << Saterday << endl;

	PrintDay(Monday + 1234);

	B b(5);
	A a = b;
	a.show();

	system("pause");
	return 0;
}