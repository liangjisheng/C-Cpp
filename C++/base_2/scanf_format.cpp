
#include <stdio.h>

int main()
{
	// 用键盘输入一些值到程序中时，会键入一串字符，这串字符就构成了
	// 输入流，scanf()函数的格式对应于输入流字符的解释方式
	// %d 解释为10进制整数
	// %x 解释为16进制整数
	printf("input 10Base integer: ");
	int a = 0;
	scanf("%d", &a);
	printf("input 16Base integer: ");
	int b = 0;
	scanf("%x", &b);

	printf("\n");
	printf("%d dec = %d\n", a, a);
	printf("%d hex = 0x%x\n", a, a);
	printf("%d dec = %d\n", b, b);
	printf("%d hex = 0x%x\n", b, b);

	getchar();
	getchar();
	return 0;
}