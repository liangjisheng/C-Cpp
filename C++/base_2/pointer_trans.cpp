
#include <stdio.h>

void test_1()
{
	unsigned int a = 5, b = 0;
	printf("&a = 0x%x\n&b = 0x%x\n", &a, &b);
	b = (unsigned int)&a;		// 将a的地址保存在b中
	printf("(unsigned int*)&b = 0x%x\n", (unsigned int *)&b);	// 输出b的地址
	printf("(unsigned int*)b = 0x%x\n", (unsigned int *)b);		// 输出b的值,及a的地址
	// 将b强制转换为指针,再取得a的值
	printf("*(unsigned int *)b = 0x%x\n", *(unsigned int *)b);
}

void test_2()
{
	int iNum = 0x64;
	int *ptr = &iNum;
	int **pPtr = &ptr;

	printf("&iNum = 0x%x, iNum = 0x%x\n", &iNum, iNum);
	printf("&ptr = 0x%x, ptr = 0x%x, *ptr = 0x%x\n", &ptr, ptr, *ptr);
	printf("&pPtr = 0x%x, pPtr = 0x%x, *pPtr = 0x%x, **pPtr = 0x%x\n", 
		&pPtr, pPtr, *pPtr, **pPtr);
}

int main()
{
	test_2();

	getchar();
	return 0;
}