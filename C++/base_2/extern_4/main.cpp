
// C++中引用C函数
#include <stdio.h>

// 必须加上extern "C"使得test.h中的声明的变量或函数以C语言方式
// 编译和链接
extern "C"
{
	#include "test.h"
};


int main()
{
	int nSum = add(3, 4);
	printf("sum = %d\n", nSum);

	getchar();
	return 0;
}