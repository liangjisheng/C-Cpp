
/*
 name: variable_argument1.c
 func: 可变参数
*/

#include <stdio.h>
#include <stdarg.h>

int average(int nFirstNum, ...)
{
	int nSum = 0, c = 0;
	int *p = &nFirstNum;

	if (nFirstNum < 0)
		return 0;
	while (*p > 0)
	{
		nSum += *p;
		c++;
		(char *)p += _INTSIZEOF(int);
	}
	printf("_INTSIZEOF(int) = %d\n", _INTSIZEOF(int));

	return nSum / c;
}

int average1(int nFirstNum, ...)
{
	if (nFirstNum < 0)
		return 0;

	int nSum = nFirstNum, count = 1, p;
	va_list va;
	va_start(va, nFirstNum);

	while ((p = va_arg(va, int)) >= 0)
	{
		nSum += p;
		count++;
	}
	va_end(va);

	return nSum / count;
}

int average2(int nCounts, ...)
{
	if (nCounts <= 0)
		return 0;

	int nSum = 0;
	int i = 0;
	int *p = &nCounts;
	(char *)p += _INTSIZEOF(int);

	for (i = 0; i < nCounts; i++)
	{
		nSum += *p;
		(char *)p += _INTSIZEOF(int);
	}
	// printf("_INTSIZEOF(int) = %d\n", _INTSIZEOF(int));

	return nSum / nCounts;
}

int average3(int nCounts, ...)
{
	if (nCounts <= 0)
		return 0;

	va_list va;
	va_start(va, nCounts);
	int nSum = 0, i = 0;

	for (i = 0; i < nCounts; i++)
		nSum += va_arg(va, int);

	va_end(va);
	return nSum / nCounts;
}


int main()
{
	// -1作为结束标志，average和average1只能计算正数的均值
	printf("%d\n", average(1, 2, 3, 4, 5, -1));
	printf("%d\n", average1(1, 2, 3, 4, 5, -1));

	// average2和average3的第一个参数指定求均值的个数，并且可以有负数
	printf("%d\n", average2(5, 1, 2, 3, 4, 5));
	printf("%d\n", average3(5, 1, 2, 3, 4, 5));

	printf("%d\n", average2(6, 1, 2, 3, 4, 5, -6));
	printf("%d\n", average3(7, 1, 2, 3, 4, 5, 6, 7));

	getchar();
	return 0;
}

// 上面讲的内容与C语言的实现有关，而C语言的实现又依赖于cpu和操作系统
// 所以并不适用于所有的计算机，而且随机器的不同会由很大的区别
// 在<stdarg.h>内会看到大量的条件编译就是这个原因。其次，虽然函数定义
// 中使用可变参数列表提供了很大的灵活性，但是对可变部分的参数C语言编译器
// 不会进行类型检查，所以程序中要特别小心，确保参数的传递和接受是正确的
