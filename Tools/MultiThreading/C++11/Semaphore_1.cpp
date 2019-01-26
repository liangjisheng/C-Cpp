
/***********************************************************
 * @name: Semaphore_1.cpp
 * @brief: Semaphore
 * @author: 梁基圣
 * @date: 2018/7/22 14:51:21
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <windows.h>

using namespace std;

int tickets = 100;
HANDLE hSemaphore;
CRITICAL_SECTION g_cs;

DWORD WINAPI Thread1Proc(LPVOID lpParam);
DWORD WINAPI Thread2Proc(LPVOID lpParam);

int main()
{
	HANDLE hThread1, hThread2;
	hThread1 = CreateThread(NULL, 0, Thread1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Thread2Proc, NULL, 0, NULL);

	// 创建信号量，初始为1，最大为1
	hSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
	InitializeCriticalSection(&g_cs);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hSemaphore);

	while (true)
	{
		WaitForSingleObject(hSemaphore, INFINITE);
		if (tickets > 0)
		{
			EnterCriticalSection(&g_cs);
			cout << "主线程卖出第" << tickets-- << "张票" << endl;
			LeaveCriticalSection(&g_cs);
			Sleep(50);
			ReleaseSemaphore(hSemaphore, 1, NULL);
		}
		else
		{
			ReleaseSemaphore(hSemaphore, 1, NULL);
			break;
		}
	}

	DeleteCriticalSection(&g_cs);

	return 0;
}

DWORD WINAPI Thread1Proc(LPVOID lpParam)
{
	while (true)
	{
		WaitForSingleObject(hSemaphore, INFINITE);
		if (tickets > 0)
		{
			EnterCriticalSection(&g_cs);
			cout << "线程1卖掉第" << tickets-- << "张票" << endl;
			LeaveCriticalSection(&g_cs);
			Sleep(50);
			ReleaseSemaphore(hSemaphore, 1, NULL);
		}
		else
		{
			ReleaseSemaphore(hSemaphore, 1, NULL);
			break;
		}
	}

	return 0;
}

DWORD WINAPI Thread2Proc(LPVOID lpParam)
{
	while (true)
	{
		WaitForSingleObject(hSemaphore, INFINITE);
		if (tickets > 0)
		{
			EnterCriticalSection(&g_cs);
			cout << "线程2卖掉第" << tickets-- << "张票" << endl;
			LeaveCriticalSection(&g_cs);
			Sleep(50);
			ReleaseSemaphore(hSemaphore, 1, NULL);
		}
		else
		{
			ReleaseSemaphore(hSemaphore, 1, NULL);
			break;
		}
	}

	return 0;
}
