
/***********************************************************
 * @name: invSqrt.c
 * @brief: 求x倒数的平方根,系国外高手所写
 * @author: Jisheng Liang
 * @date: 2018/6/6 15:06:59
 * @version: 1.0
 **********************************************************/

#include <stdio.h>

// 结果并不精确相等,只是近似相等
float invSqrt(float x)
{
	int i = *(int *)&x;
	int i2 = i >> 1;
	int nRes = 1597463007 - i2;
	x = *(float *)&nRes;
	return x;
}

int main()
{
	printf("%f\n", invSqrt(4.0));
	printf("%f\n", invSqrt(9.0));
	printf("%f\n", invSqrt(16.0));

	getchar();
	return 0;
}
