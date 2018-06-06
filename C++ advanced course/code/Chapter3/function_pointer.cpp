
// 有一种函数叫回调函数(callbakc function).回调函数是一个定义了函数的原型
// 函数体则交由第三方来实现的一种动态应用模式。在实现调用时，先将回调函数
// 的地址作为参数之一传递给主调函数，在主调函数内部通过函数指针调用回调
// 函数。回调函数的机制打破了主调函数与被调函数静态绑定的限制，为用户提供
// 了一种充分利用操作系统功能的方便手段

#include <iostream>

using std::cout;
using std::endl;

class DoubleValue
{
public:
	double GetValue() { return 3.7; }
	static int RetInt() { return 5; }
};

typedef int(*pInt)();

double operator+(DoubleValue &d, pInt pfunc)
{
	return d.GetValue() + pfunc();
}


int f() { return 1; }

// 显示声明函数指针
void invoke1(int (*func)()) { cout << (*func)() << endl; }

// 隐式声明函数指针
void invoke2(int func()) { cout << func() << endl; }


int main()
{
	DoubleValue obj;
	// 因为RetInt是静态的所以可以直接赋值，类的静态成员只是限定了作用域的
	// 外部成员
	pInt p1 = obj.RetInt;
	// endl其实是一个函数模板，也就是说操作符operator<<接受一个函数指针
	// 作为它的参数
	cout << obj + p1 << endl;

	invoke1(f);
	invoke2(f);

	system("pause");
	return 0;
}