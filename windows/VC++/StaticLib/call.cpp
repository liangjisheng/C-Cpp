
#include <stdio.h>
#include "..\0610-1\lib.h"
#pragma comment(lib, "..\\Debug\\0610-1.lib")	// 指定与静态库一起链接

int main()
{
	printf("2 + 3 = %d\n", add(2, 3));
	getchar();
}