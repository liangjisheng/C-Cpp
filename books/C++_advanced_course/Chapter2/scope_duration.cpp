
// 作用域(scope)和生命期(duration)是两个不同的概念。作用域是一个静态概念
// 只在编译源程序的时候有用，一个标识符的作用域是指在源文件中该标识符能够
// 独立的合法出现的区域。而声明期是一个运行时概念，他是指一个变量在整个
// 程序从载入到结束运行的过程中，在哪一个时间区间内有效。

// 5中作用域:函数原型域、块域(局部域)、类域、名称空间域和文件域，这些区域
// 都是C++源文件的自然组织单位，任何一个标识符的作用域必然位于这5种范围之一

// 标识符的作用域不会超出其声明域的范围，作用域的范围可以是一个连续的代码
// 范围，如块域、文件域，也可以是分段定义的各段代码的集合，如命名空间和
// 类域。命名空间可以分段定义，但各段属于同一个作用域范围。类的成员函数
// 可以定义在类体外部，但它任然属于该类域的一部分。


#include <iostream>

using std::cout;
using std::endl;

int i = 8;

void test()
{
	int i = 5;
	{
		int i = 6;
		cout << i << endl;
	}
	cout << i << endl;
	cout << ::i << endl;
}


void func1()
{
	goto Lable2;
Lable1:
	cout << "hello" << endl;
Lable2:
	cout << "in func1" << endl;
}


void func2()
{
Lable1:
	cout << "in func2" << endl;
}


int main()
{
	test();

	func1();
	func2();

	system("pause");
	return 0;
}