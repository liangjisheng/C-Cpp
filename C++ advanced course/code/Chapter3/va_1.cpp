
// 在intel+windows的机器上，函数栈的方向是向下的，栈顶指针的内存地址低于
// 栈底指针，所以先进栈的数据是存放在内存的高地址处
// 在VC等绝大多数C编译器中，默认情况下，参数进栈的顺序是从右向左的，因此
// 参数进栈以后，最后一个固定参数的地址位于第一个可变参数之下，并且是连续
// 存储的

#include <iostream>
// C编译器为了统一在不同的硬件平台上的实现，增加代码的可移植性，提供了
// 一系列的宏来屏蔽硬件环境不同带来的差异
#include <stdarg.h>

using std::cout;
using std::endl;

void PrintAll(int n1, ...)
{
	int *ptr = &n1;
	while(*ptr)
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;

	ptr = &n1;
	while(*ptr)
		cout << *ptr++ << " ";
	cout << endl;

	ptr = &n1;
	while(*ptr++)
		cout << *ptr << " ";
	cout << endl;
}


int SqSum1(int n1, ...)
{
	va_list arg_ptr;
	int nSqSum = 0, n = n1;
	va_start(arg_ptr, n1);
	while(n > 0)
	{
		nSqSum += (n * n);
		n = va_arg(arg_ptr, int);
	}
	va_end(arg_ptr);
	return nSqSum;
}


int SqSum2(int n1, ...)
{
	va_list arg_ptr;
	int nSqSum = 0, n;
	va_start(arg_ptr, n1);
	while(n1 > 0)
	{
		n = va_arg(arg_ptr, int);
		nSqSum += (n * n);
		n1--;
	}
	va_end(arg_ptr);
	return nSqSum;
}


int main()
{
	// PrintAll(3, 4, 5);

	int nSqSum = SqSum1(1, 1, 1, 1);
	cout << nSqSum << endl;
	nSqSum = SqSum1(1, 1, 1, 1, 0);
	cout << nSqSum << endl;
	nSqSum = SqSum2(4, 1, 1, 1, 1);
	cout << nSqSum << endl;

	system("pause");
	return 0;
}