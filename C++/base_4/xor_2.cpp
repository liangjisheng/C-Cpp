
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

union
{
	int i;
	char x[2];
}a;

int main()
{
	unsigned char ui = 0x80;
	printf("0x%x\n", ui);
	printf("0x%x\n", ~ui);
	printf("0x%x\n", ~ui >> 3);
	// 下面两句的输出结果不一样，说明+运算符的优先级高于>>
	printf("0x%x\n", (~ui >> 3) + 1);
	printf("0x%x\n", ~ui >> 3 + 1);

	printf("\n");
	char i = 0x80;
	printf("0x%x\n", i);
	printf("0x%x\n", ~i);
	printf("0x%x\n", ~i >> 3);
	printf("0x%x\n", (~i >> 3) + 1);
	printf("0x%x\n", ~i >> 3 + 1);

	printf("\n");
	a.x[0] = 10;
	a.x[1] = 1;
	// 注意union的存放顺序是所有成员地址都是从低地址开始存放，union的大小为
	// 其内部所有变量的最大值，并且按照类型最大值的整数倍进行内存对齐
	printf("0x%x\n", a.i);			// 0x10a
	printf("%d\n", a.i);			// 266

	system("pause");
	return 0;
}