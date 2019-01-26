
#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include "thread_lock.h"

const int aSize = 10;
char szArr[aSize + 1] = {0};

CThreadLock threadLock;			// 全局变量

unsigned _stdcall threadFunc1(void *)
{
	// 声明一个CThreadLockHandle类型的变量，其生存周期结束后自动解锁
	CThreadLockHandle lockHandle(&threadLock);

	for (int s = 0; s < aSize; ++s)
	{
		szArr[s] = 'a';
		Sleep(1);
	}

	return 0;
}

unsigned _stdcall threadFunc2(void*)
{
	// 声明一个CThreadLockHandle类型的变量，其生存周期结束后自动解锁
	CThreadLockHandle lockhandle(&threadLock);
	for (int s = 0; s < aSize; ++s)
	{
		szArr[aSize - 1 - s] = 'b';
		Sleep(1);
	}

	return 0;
}


int main()
{
	HANDLE handle1 = (HANDLE)_beginthreadex(NULL, 0, threadFunc1, NULL, 0, 0);
	HANDLE handle2 = (HANDLE)_beginthreadex(NULL, 0, threadFunc2, NULL, 0, 0);

	WaitForSingleObject(handle1, INFINITE);
	WaitForSingleObject(handle2, INFINITE);

	printf("%s\n", szArr);
	CloseHandle(handle1);
	CloseHandle(handle2);

	getchar();
	return 0;
}