
// 统计一个网站每天有多少用户登录，每个用户登录用一个线程模拟，线程运行时
// 会将一个表示计数的变量递增。程序在最后输出计数的值表示有今天多少个用户登录
// 如果这个值不等于我们启动的线程个数，那显然说明这个程序是有问题的

#include <stdio.h>
#include <process.h>
#include <Windows.h>

volatile long g_nLoginCount;			// 登录次数
unsigned int _stdcall Fun(void *pPM);	// 线程函数
const int THREAD_NUM = 10;				// 启动线程数

unsigned int _stdcall Fun(void *pPM)
{
	Sleep(100);
	g_nLoginCount++;
	Sleep(50);
	return 0;
}


int main()
{
	g_nLoginCount = 0;

	HANDLE hThreads[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; ++i)
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, NULL, 0, NULL);
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);
	printf("有%d个用户登录后记录结果是%d\n", THREAD_NUM, g_nLoginCount);

	getchar();
	return 0;
}