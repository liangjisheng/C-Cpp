
#include <stdio.h>

void test_1()
{
	float f = 1000001.111111;
	printf("f = %f\n", f);			// 1000001.125.000
	// float型变量仅能接受浮点数常量的7位有效数字，在有效数字
	// 后面输出的数字都是不准确的
}

void test_2()
{
	float f1 = 123.456001;
	float f2 = 123.456002;
	if(f1 == f2)
		printf("equal\n");
	else
		printf("no equal\n");
}

void test_3()
{
	unsigned int a = 9;
	int a1 = 9;
	printf("hex %d = 0x%x\n", a, a);	// 0x9
	printf("hex %d = 0x%x\n", a1, a1);	// 0x9
	int b = -4, c;
	printf("hex %d = 0x%x\n", b, b);	// 0xfffffffc
	unsigned int ub = b;
	printf("hex %d = 0x%x\n", ub, ub);	// 0xfffffffc
	c = a / b;
	printf("%d\n", c);

	printf("\n");
	unsigned int ui = 0xfffffffc;
	printf("%d hex = 0x%x\n", ui, ui);
	int i = 0xfffffffc;
	printf("%d hex = 0x%x\n", i, i);
}


int main()
{
	// test_1();
	// test_2();
	test_3();

	getchar();
	return 0;
}