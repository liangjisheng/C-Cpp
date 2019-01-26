
#include <stdio.h>
#include <Windows.h>

DWORD WINAPI ThreadProc1(LPVOID lpParameter);
DWORD WINAPI ThreadProc2(LPVOID lpParameter);

int ticket = 50;
HANDLE hMutex = NULL;


int main()
{
	// 第二个参数为TRUE,互斥对象的所有权为主线程所有,非空闲状态
	hMutex = CreateMutex(NULL, FALSE, NULL);

	HANDLE h1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	HANDLE h2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

	CloseHandle(h1);
	CloseHandle(h2);

	getchar();
	return 0;
}


DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	while(true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if(ticket > 0)
		{
			Sleep(1);
			printf("thread1 sale the ticket id is : %d\n", ticket--);
		}
		else
			break;
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	while(true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if(ticket > 0)
		{
			Sleep(1);
			printf("thread2 sale the ticket id is : %d\n", ticket--);
		}
		else
			break;
		ReleaseMutex(hMutex);
	}

	return 0;
}