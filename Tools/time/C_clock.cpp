
// clock_t clock()得到的是CPU时间，精确到1 / CLOCKS_PER_SEC秒
// clock()返回从启动这个程序进程到程序中调用clock()函数时之间的
// CPU时钟计时单元
// CLOCKS_PER_SEC常量表示一秒钟会有多少个时钟计时单元

#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
	printf("1秒钟有%d个时钟计时单元\n", CLOCKS_PER_SEC);
	
	long i = 10000000L;
	clock_t start = 0, finish = 0;
	long lTime = 0;
	printf("做%ld次循环需要的时间为: ", i);
	start = clock();
	while (i--)
		double x = sin(0.001) + cos(4556.443);
	finish = clock();
	lTime = finish - start;
	printf("%ld毫秒\n", lTime);

	getchar();
	return 0;
}