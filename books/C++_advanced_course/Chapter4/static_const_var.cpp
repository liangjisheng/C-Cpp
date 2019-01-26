
// 类的只读静态数据成员的初始化可以在类体内部进行，也可以在类体外部进行。
// 这是非常特殊的一种初始化方式，因为C++语法认为类体中的相关语句是对变量
// 的声明而不是定义，一般情况下，不允许在类体内部指明成员变量的初值
// 在类体内部给成员变量赋值，这种语法是强调类的静态常量数据成员是紧密与类
// 相关的属性

#include <iostream>

using std::cout;
using std::endl;


class A
{
public:
	static const int i;
	// 只能使用编译时常量给类的静态只读成员赋值，不能使用变量或者函数的返回值等
	static const int j = 5;			// ok
	// const int k = 6;				// error
};

const int A::i = 4;


int main()
{
	cout << A::i << endl;
	cout << A::j << endl;

	system("pause");
	return 0;
}
