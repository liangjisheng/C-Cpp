#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	A(int num = 1) : mNum(num) {}
	int mNum;
};

int main()
{
	A a0;
	const A& a1 = a0;
	// 常量引用转为非常量引用
	A a2 = const_cast<A&>(a1);
	a2.mNum = 200;

	cout << a0.mNum << ' ' << a1.mNum << ' ' << a2.mNum << endl;

	// 常量对象不能转换为非常量对象
	const A ca;
	A a3 = const_cast<A>(ca); // error

	system("pause");
	return 0;
}