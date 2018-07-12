
#include <stdio.h>

void test_1()
{
	int i, data[2] = {1, 2};
	int (*pData)[2] = &data;

	// data的类型是int[2],pData的类型为指向int[2]的指针
	// pData = data;		// error
	// 为了设计编译器的方便,定义数组时写成这样int data[2];
	// 其实应该这样写int[2] data;

	for(i = 0; i < 2; i++)
	{
		printf("第[%d]号元素: ", i);
		scanf("%d", *pData + i);		// *pData + i 为第i个元素的地址
	}

	// 当用指向数组的指针访问以为数组时,比使用普通指针变量要繁琐的多
	// 因此它常用语处理二维数组
	for(i = 0; i < 2; i++)
		printf("%d\t", *(*pData + i));
}

void test_2()
{
	int a[2][3] = {{1}, {2, 3}};
	printf("%d\n", a[1][0]);

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void test_3()
{
	int data[][2] = {{1, 2}, {3, 4}, {5, 6}};
	int n = sizeof(data) / sizeof(data[0][0]);
}

int main()
{
	

	getchar();
	getchar();
	return 0;
}