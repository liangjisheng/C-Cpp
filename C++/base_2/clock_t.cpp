
// clock_t clock(void)	// 返回从开启这个程序进程到程序中调用clock()
// 时之间的CPU时钟计时单元(1毫秒)
// typedef long clock_t
// 常量CLOCKS_PER_SEC用来表示一秒有多少个时钟计时单元(vs2010测试为1000)
// 钟计时单元的长度为1毫秒，那么计时的精度也为1毫秒

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 输出一个进程自身运行的时间
void elapsed_time()
{
	printf("Elapsed time: %lf secs\n", clock() / (double)CLOCKS_PER_SEC);
}

int main()
{
	long i = 1000000000L;
	clock_t start, finish;
	double duration;
	// 测量一个事件持续的时间
	printf("Time to do %ld empty loops is ", i);
	start = clock();
	while(i--);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf seconds\n", duration);

	elapsed_time();

	int b = clock() / (double)CLOCKS_PER_SEC;
	for (int i = 0; i < 100;)
	{
		i = clock() / (double)CLOCKS_PER_SEC;
		printf("%d\n", i);
		i = i - b;
		elapsed_time();
	}

	elapsed_time();

	getchar();
	return 0;
}