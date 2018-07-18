
/*
 name: variable_argument.c
 func: 函数变长参数
*/

#include <stdio.h>
#include <stdarg.h>

// va_list ap;				// 定义一个可变参数列表ap
// va_start(ap, arg);		// 初始化ap指向参数arg的下一个参数
// 获取当前参数内容并将ap指向下一个参数, 不断的进行这个操作可以取出变长参数中的所有参数
// va_arg(ap, type);		
// va_end(ap);				// 最后使用va_end清空这个变长参数列表

// sum of some integers
int f(int nCounts, ...)
{
	va_list va;
	va_start(va, nCounts);
	int nSum = 0;
	int i = 0;
	for (i = 0; i < nCounts; i++)
		nSum += va_arg(va, int);
	va_end(va);

	return nSum;
}


int main()
{
	printf("%d\n", f(1, 1));
	printf("%d\n", f(2, 1, 2));
	printf("%d\n", f(3, 1, 2, 3));
	printf("%d\n", f(4, 1, 2, 3, 4));
	printf("%d\n", f(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

	getchar();
	return 0;
}
