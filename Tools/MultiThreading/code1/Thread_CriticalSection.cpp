
#include <Windows.h>
#include <stdio.h>

DWORD WINAPI Thread1Proc(LPVOID lpParameter);
DWORD WINAPI Thread2Proc(LPVOID lpParameter);

int tickets = 100;
CRITICAL_SECTION g_cs;

int main()  
{
	HANDLE hThread1 = NULL;
	HANDLE hThread2 = NULL;
	InitializeCriticalSection(&g_cs);

	hThread1 = CreateThread(NULL, 0, Thread1Proc, NULL, 0, NULL);
	if(!hThread1)
		return -1;
	hThread2 = CreateThread(NULL, 0, Thread2Proc, NULL,	0, NULL);
	if(!hThread2)
		return -2;
  
	Sleep(4000);  

	CloseHandle(hThread1);
	CloseHandle(hThread2);

	DeleteCriticalSection(&g_cs); 

	getchar();
	return 0;  
}  


DWORD WINAPI Thread1Proc(LPVOID lpParameter)
{
	while(TRUE)
	{
		EnterCriticalSection(&g_cs);  
		Sleep(1);
		if(tickets > 0)  
		{  
			Sleep(1);  
			printf("thread1 sell ticket : %d\n",tickets--);  
			LeaveCriticalSection(&g_cs);  
			Sleep(1);
		}  
		else  
		{
			LeaveCriticalSection(&g_cs);
			break;  
		}  
	}  

	return 0;  
}  

DWORD WINAPI Thread2Proc(  LPVOID lpParameter)  
{  
	while(TRUE)  
	{  
		EnterCriticalSection(&g_cs);  
		Sleep(1);  
		if(tickets > 0)  
		{  
			Sleep(1);  
			printf("thread2 sell ticket : %d\n",tickets--);  
			LeaveCriticalSection(&g_cs);  
			Sleep(1);  
		}  
		else  
		{  
			LeaveCriticalSection(&g_cs);  
			break;  
		}  
	}  

	return 0;  
} 

