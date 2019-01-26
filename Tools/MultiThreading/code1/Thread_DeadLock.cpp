
// 多线程中经常会出现死锁情况：举个例子：线程1拥有临界区资源A，正在等待
// 临界区资源B，而线程2拥有临界区资源B，正在等待临界区资源A.他两各不相让
// 结果谁也执行不了，看下面代码

#include <Windows.h>  
#include <stdio.h>  

DWORD WINAPI Thread1Proc(LPVOID lpParameter);
DWORD WINAPI Thread2Proc(LPVOID lpParameter);

int tickets = 100;  
CRITICAL_SECTION g_csA;  
CRITICAL_SECTION g_csB;  


int main()  
{  
	HANDLE hThread1 = NULL;
	HANDLE hThread2 = NULL;
	InitializeCriticalSection(&g_csA);  
	InitializeCriticalSection(&g_csB);

	hThread1 = CreateThread(NULL, 0, Thread1Proc, NULL, 0, NULL);
	if(!hThread1)
		return -1;
	hThread2 = CreateThread(NULL, 0, Thread2Proc, NULL, 0, NULL);
	if(!hThread2)
		return -2;

	//当不再引用这个句柄时，立即将其关闭，减少其引用计数  
	CloseHandle(hThread1);  
	CloseHandle(hThread2);  

	Sleep(4000);  

	DeleteCriticalSection(&g_csA);  
	DeleteCriticalSection(&g_csB);
	return 0;  
}  


// 在程序中，创建了两个临界区对象g_csA和g_csB。线程1中先尝试获取g_csA，
// 获取成功后休眠，线程2尝试获取g_csB，成功后休眠，切换回线程1，然后
// 线程1试图获取g_csB，因为g_csB已经被线程2获取，所以它线程1的获取不会成功
// 一直等待，直到自己的时间片结束后，转到线程2，线程2获取g_csB后
// 试图获取g_csA，当然也不会成功，转回线程1……这样交替等待
// 直到主线程睡醒，执行完毕，程序结束

DWORD WINAPI Thread1Proc(  LPVOID lpParameter)  
{  
	while(TRUE)  
	{  
		EnterCriticalSection(&g_csA);  
		Sleep(1);  
		EnterCriticalSection(&g_csB);  
		if(tickets > 0)  
		{  
			Sleep(1);  
			printf("thread1 sell ticket : %d\n",tickets--);  
			LeaveCriticalSection(&g_csB);  
			LeaveCriticalSection(&g_csA);  
			Sleep(1);  
		}  
		else  
		{  
			LeaveCriticalSection(&g_csB);  
			LeaveCriticalSection(&g_csA);  
			break;  
		}  
	}  

	return 0;  
}  


DWORD WINAPI Thread2Proc(  LPVOID lpParameter)  
{  
	while(TRUE)  
	{  
		EnterCriticalSection(&g_csB);  
		Sleep(1);  
		EnterCriticalSection(&g_csA);  
		if(tickets > 0)  
		{  
			Sleep(1);  
			printf("thread2 sell ticket : %d\n",tickets--);  
			LeaveCriticalSection(&g_csA);  
			LeaveCriticalSection(&g_csB);  
			Sleep(1);  
		}  
		else  
		{  
			LeaveCriticalSection(&g_csA);  
			LeaveCriticalSection(&g_csB);  
			break;  
		}  
	}  

	return 0;  
}

