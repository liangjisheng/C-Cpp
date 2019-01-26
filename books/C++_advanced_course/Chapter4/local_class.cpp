
// 局部类的成员函数都必须定义在类体内，局部类中不能定义静态数据成员，主要
// 是这样数据成员的初始化工作无法完成

#include <iostream>

using std::cout;
using std::endl;

void func()
{
	static int s;
	class A
	{
	public:
		int num;
		void init(int i) { s = i; }
	};
	A a;
	a.init(8);
	cout << s << endl;
}


int main()
{
	func();

	system("pause");
	return 0;
}

