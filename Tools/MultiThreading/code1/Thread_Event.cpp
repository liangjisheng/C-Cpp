
// 事件对象，也属于内核对象，包含3个成员
// 1引用计数
// 2用于指明该事件是自动重置事件还是人工重置事件
// 3用于指明该事件处于以通知状态还是未通知状态
// 自动重置和人工重置的事件对象有一个重要的区别：当人工重置的事件对象得到通知
// 时，等待该事件对象的所有线程均变为可调度线程；而当一个自动重置的事件对象
// 得到通知时，等待该事件对象的线程中只有一个线程变为可调度线程


#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

DWORD WINAPI Thread1Proc(LPVOID lpParameter);
DWORD WINAPI Thread2Proc(LPVOID lpParameter);

int tickets = 100;
HANDLE g_hEvent;

int main()
{
	HANDLE hThread1;
	HANDLE hThread2;

	// 如果刚开始无信号，则两个线程都不会卖票，因为WaitForSingleObject
	// 要获取事件对象，这个事件对象必须是有信号的，可以将第三个参数设置为
	// TURE,或者创建后使用SetEvent(g_hEvent),将事件对象变为有信号状态
	//g_hEvent = CreateEvent(NULL,		// 默认安全级别
	//	TRUE,							// 人工重置
	//	FALSE,							// 初始为无信号
	//	_T("myEvent"));					// 事件对象名

	g_hEvent = CreateEvent(NULL,		// 默认安全级别
			FALSE,						// 自动重置
			FALSE,						// 初始为无信号
			_T("myEvent"));				// 事件对象名

	if(!g_hEvent)
	{
		printf("g_hEvent error\n");
		return -1;
	}

	// 将g_hEvent变为有信号状态
	SetEvent(g_hEvent);

	hThread1 = CreateThread(NULL, 0, Thread1Proc, NULL, 0, NULL);
	if(!hThread1)
	{
		printf("hThread1 error\n");
		return -2;
	}
	hThread2 = CreateThread(NULL, 0, Thread2Proc, NULL, 0, NULL);
	if(!hThread2)
	{
		printf("hThread2 error\n");
		return -3;
	}

	Sleep(4000);

	CloseHandle(hThread1);
	CloseHandle(hThread2);

	CloseHandle(g_hEvent);

	getchar();
	return 0;
}


DWORD WINAPI Thread1Proc(LPVOID lpParameter)
{
	while(true)
	{
		// 若事件对象有信号，则获取事件对象，将其变成无信号状态，否则一直等待
		WaitForSingleObject(g_hEvent, INFINITE);
		// 获取事件后(即事件得到通知)，等待该事件的线程中只有一个变为可调度
		// 线程，这里线程1变为可调度线程，当访问完对保护的代码段后，立即调用
		// SetEvent将其设为有信号状态，允许其它等待该对象的线程变为可调度状态
		if(tickets > 0)
		{
			Sleep(10);
			printf("thread1 sell ticket:%d\n", tickets--);
			SetEvent(g_hEvent);
		}
		else
		{
			SetEvent(g_hEvent);
			break;
		}
	}

	return 0;
}

DWORD WINAPI Thread2Proc(LPVOID lpParameter)
{
	while(true)
	{
		WaitForSingleObject(g_hEvent, INFINITE);
		if(tickets > 0)
		{
			Sleep(10);
			printf("thread2 sell ticket:%d\n", tickets--);
			SetEvent(g_hEvent);
		}
		else
		{
			SetEvent(g_hEvent);
			break;
		}
	}

	return 0;
}

