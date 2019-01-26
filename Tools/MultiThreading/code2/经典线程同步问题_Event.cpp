
// 用事件Event来尝试解决这个线程同步问题
// HANDLE CreateEvent(
// LPSECURITY_ATTRIBUTES lpEventAttributes,
// BOOL bManualReset,
// BOOL bInitialState,
// LPCTSTR lpName);
// 第一个参数一般传NULL
// 第二个参数确定事件是手动置位还是自动置位，TRUE表示手动置位，FALSE表示自动置位
// 如果为自动置位，对该事件调用WaitForSingleObject()后会自动调用ResetEvent()使事件
// 变为未触发状态
// 第三个参数表示事件的初始化状态，TRUE表示已触发
// 第四个参数表示事件的名称，传入NULL表示匿名事件

// 根据名称获得一个事件句柄
// HANDLE OpenEvent(
// DWORD dwDesiredAccess,		// 表示访问权限，一般传入EVENT_ALL_ACCESS
// BOOL bInheritHandle,			// 表示事件句柄继承性，一般传入TRUE
// LPCTSTR lpName)				// 不同进程中的各线程可以通过名称来确保它们访问同一个事件

// BOOL SetEvent(HANDLE hEvent);	触发事件
// 每次触发后，必有一个或多个处于等待状态下的线程变成可调度状态

// 将事件设为末触发
// BOOL ResetEvent(HANDLE hEvent);

// 由于事件是内核对象，因此使用CloseHandle()就可以完成清理与销毁了

// 在经典多线程问题中设置一个事件和一个关键段。用事件处理主线程与子线程的同步，
// 用关键段来处理各子线程间的互斥

#include <stdio.h>  
#include <process.h>  
#include <windows.h>  

long g_nNum;  
unsigned int __stdcall Fun(void *pPM);  
const int THREAD_NUM = 10;

HANDLE g_hThreadEvent;
CRITICAL_SECTION g_csThreadCode;

int main()
{
	// 创建自动置位，初始无触发的匿名事件
	g_hThreadEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	InitializeCriticalSection(&g_csThreadCode);

	HANDLE hThreads[THREAD_NUM];
	g_nNum = 0;
	int i = 0;

	while(i < THREAD_NUM)
	{
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL);
		// 等待事件被触发，此时主线程并没有被挂起，将会继续往下执行
		WaitForSingleObject(g_hThreadEvent, INFINITE);
		i++;
	}
	printf("%d\n", __LINE__);
	// 等待所有的线程都结束
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);
	printf("%d\n", __LINE__);

	CloseHandle(g_hThreadEvent);
	DeleteCriticalSection(&g_csThreadCode);

	getchar();
	return 0;
}


unsigned int __stdcall Fun(void *pPM)
{
	int nThreadNum = *(int *)pPM;
	SetEvent(g_hThreadEvent);		// 触发事件

	Sleep(50);		// some work should to do 

	EnterCriticalSection(&g_csThreadCode);
	g_nNum++;
	Sleep(0);		// some work should to do 
	printf("线程编号为%-4d全局资源值%-4d\n", nThreadNum, g_nNum);
	LeaveCriticalSection(&g_csThreadCode);

	return 0;
}