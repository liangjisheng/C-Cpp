
#include <stdio.h>

int main()
{
	// 在32位计算机中,表达式在运行时将unsigned char类型的变量自动
	// 转换成unsigned int类型的变量,~b = 0xffffff00, a != ~b

	unsigned char a = 0;
	unsigned char b = 0xff;
	printf("%d hex = 0x%x\n", a, a);
	printf("%d hex = 0x%x\n", b, b);
	printf("%d hex = 0x%x\n", ~b, ~b);

	if(a == ~b)
		printf("a == ~b\n");
	else
		printf("a != ~b\n");

	getchar();
	return 0;
}