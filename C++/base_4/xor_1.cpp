
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

int foo(int x) { return x&-x; }

int main()
{
	printf("%x\n", 2 ^ 31);				// ^是异或运算，而不是幂次方
	printf("%x\n", 2 ^ 31 - 3);			// 减号的优先级大于异或运算符
	printf("%x\n", (2 ^ 31) - 3);
	printf("%x\n", -(2 ^ 31 - 3));		// 负数以补码形式表示，正数的反码加1
	printf("\n");

	cout << foo(2^32-3) << endl;		// 2
	printf("%x\n", -2);

	system("pause");
	return 0;
}