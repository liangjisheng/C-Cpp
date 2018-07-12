
// C中引用C++函数

#include <stdio.h>
// 直接包含会有错误，因为C语言中没有extern "C"这样的声明
// #include "test.h"
int add(int, int);		// 直接声明一个外部链接函数

int main()
{
	int nSum = add(2, 3);
	printf("%d\n", nSum);

	getchar();
	return 0;
}