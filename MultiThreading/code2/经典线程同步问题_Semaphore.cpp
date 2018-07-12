
// HANDLE CreateSemaphore(
// LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,		// 一般传NULL
// LONG lInitialCount,		// 表示初始资源数量
// LONG lMaximumCount,		// 表示最大并发数量
// LPCTSTR lpName);			// 信号量的名称，NULL表示匿名信号量

// HANDLE OpenSemaphore(
//  DWORD dwDesiredAccess,	// 访问权限一般传SEMAPHORE_ALL_ACCESS
//  BOOL bInheritHandle,	// 表示信号量的句柄继承性，一般传TRUE
//  LPCTSTR lpName);		// 不同进程中的各线程可以通过名称来确保它们访问同一个信号量

// 递增信号量的当前资源计数
// BOOL ReleaseSemaphore(
//  HANDLE hSemaphore,			// 信号量句柄
//  LONG lReleaseCount,			// 表示增加个数，必须大于0且不能超过最大资源数量
//  LPLONG lpPreviousCount);	// 可以用来传出先前的资源计数，设为NULL表示不需要传出

// 注意：当前资源数量大于0，表示信号量处于触发，等于0表示资源已经耗尽故信号量
// 处于末触发。在对信号量调用等待函数时，等待函数会检查信号量的当前资源计数，
// 如果大于0(即信号量处于触发状态)，减1后返回让调用线程继续执行。一个线程可以
// 多次调用等待函数来减小信号量

// 使用CloseHandle()就可以完成清理与销毁了

#include <stdio.h>  
#include <process.h>  
#include <windows.h>

long g_nNum;  
unsigned int __stdcall Fun(void *pPM);  
const int THREAD_NUM = 10;

//信号量与关键段  
HANDLE            g_hThreadParameter;  
CRITICAL_SECTION  g_csThreadCode; 


int main()
{
	// 当前0个资源，最大允许1个同时访问
	g_hThreadParameter = CreateSemaphore(NULL, 0, 1, NULL);
	InitializeCriticalSection(&g_csThreadCode);

	HANDLE hThreads[THREAD_NUM];
	g_nNum = 0;
	int i = 0;
	while (i < THREAD_NUM)
	{
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL);
		printf("%d\n", __LINE__);
		WaitForSingleObject(g_hThreadParameter, INFINITE);	// 等待信号量大于0
		printf("%d\n", __LINE__);
		i++;
	}
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);

	DeleteCriticalSection(&g_csThreadCode);
	CloseHandle(g_hThreadParameter);
	for (i = 0; i < THREAD_NUM; ++i)
		CloseHandle(hThreads[i]);

	getchar();
	return 0;
}

unsigned int __stdcall Fun(void *pPM)
{
	int nThreadNum = *(int *)pPM;
	// 信号量++
	ReleaseSemaphore(g_hThreadParameter, 1, NULL);

	Sleep(50);		// some work should to do 
	EnterCriticalSection(&g_csThreadCode);
	++g_nNum;
	Sleep(0);		// some work should to do 
	printf("线程编号%-4d全局资源%-4d\n", nThreadNum, g_nNum);
	LeaveCriticalSection(&g_csThreadCode);

	return 0;
}

