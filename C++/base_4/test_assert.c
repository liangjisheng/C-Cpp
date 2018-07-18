
/***********************************************************
 * @name: test_assert.c
 * @brief: 测试断言
 * @author: Jisheng Liang
 * @date: 2018/6/29 14:47:27
 * @version: 1.0
 **********************************************************/

#include <stdio.h>
#include <assert.h>

void main()
{
	float a, b;
	printf("input two number: ");
	scanf("%f %f", &a, &b);
	// 条件为假，程序退出
	assert(b != 0);
	printf("first number / second number = %f\n", a / b);

	getchar();
}
