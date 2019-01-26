
#include <stdio.h>
#include <time.h>
// 全速执行的时候，两次的实际都为0，只有在调试的时候才执行for
// 循环里面的东西,从输出的数据可以看出，使用寄存器变量时的运行
// 时间比使用普通变量的时间要快，但并不是每次都快，因为register
// 只是暗示编译器将此变量作为一个寄存器变量，并不是每次都可以
// 成为寄存器变量的
// 由于register变量使用的是硬件CPU中的寄存器，寄存器变量无地址，
// 所以不能使用取地址运算符"&"求寄存器变量的地址。

// register 说明：
// (1)只有局部自动变量和形式参数可以作为寄存器变量，其他（如全局变量）不行。
// (2)一个计算机系统中的寄存器数目是有限的，不能定义任意多个寄存器变量。
// (3)局部静态变量不能定义为寄存器变量。
// (4)这个变量已经过时，因为现在的计算机处理速度够快，所以很少使用

int main()
{
	clock_t start, end;
	int test = 0;
	start = clock();
	register int temp, i;
	for(i = 0; i <= 500; i++)
		for(temp = 0; temp <= 100; temp++)
		{
			test = i + temp;
			// printf("%d\n", i + temp);
		}
	end = clock();
	printf("register val time %d\n", end - start);

	int k1, k2;
	start = clock();
	for(k1 = 0; k1 <= 500; k1++)
		for(k2 = 0; k2 <= 100; k2++)
		{
			test = k1 + k2;
			// printf("%d\n", k1 + k2);
		}
	end = clock();
	printf("normal val time %d\n", end - start);

	getchar();
	return 0;
}