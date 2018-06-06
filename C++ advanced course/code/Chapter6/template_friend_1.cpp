
// 严格的说，函数模板(或类模板)是不能作为一个类的友元的，就像类模板之间不能发生
// 继承关系一样。只有当函数模板(或类模板)被实例化之后生成模板函数(或模板类)，该
// 函数(或类)才能作为其他的类的友元。为了叙述方便，我们也称一个函数模板(或类模板)
// 是一个类或类模板的友元，其真实的含义是函数模板(或类模板)被实例化后生成的模板
// 函数(或模板类)作为类(或模板类)的友元。

// 函数模板作为类模板的友元，在声明友元的时候有两种不同的写法，含义不一样

#include <iostream>

using std::cout;
using std::endl;

// 编译没有错误，链接会出现错误，在类模板A<T>被实例化为A<int>时，模板类A<int>
// 中的友元声明变为friend void show(const A<int>&);这种形式的友元声明假定函数
// show()是一个已经存在的函数，即一个使用了类模板的普通函数，而不是一个函数模板
// 当发生函数调用show(a)时，编译器会认为这个调用与已经存在函数
// void show(const A<int>&)想匹配，从而不启动函数模板的实例化，这就是函数声明
// 对函数模板的实例化的屏蔽作用

template<typename T>
class A
{
	int i;
	// 这样写表明这个友元函数是一个使用了模板类的普通函数，而没有表明这是一个
	// 函数模板
	friend void show(const A<T> &a);
public:
	A() { i = 5; }
};


template<typename T>
void show(const A<T> &a) { cout << a.i << endl; }


int main()
{
	A<int> a;
	show(a);

	system("pause");
	return 0;
}

