
#include <stdio.h>
#include <process.h>
#include <Windows.h>

int g_nCount;

unsigned int __stdcall ThreadFun(PVOID pM)
{
	g_nCount++;
	printf("线程ID号为%8d的子线程报数: %d\n", GetCurrentThreadId(), g_nCount);
	return 0;
}


int main()
{
	printf("...子线程报数\n");

	const int THREAD_NUM = 10;
	HANDLE hThreads[THREAD_NUM];

	g_nCount = 0;
	for (int i = 0; i < THREAD_NUM; ++i)
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);

	getchar();
	return 0;
}