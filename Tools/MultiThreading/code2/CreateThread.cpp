
#include <stdio.h>
#include <Windows.h>

DWORD WINAPI ThreadFun(LPVOID pM)
{
	printf("子线程的线程ID为: %d\n子线程输出hello,world\n", GetCurrentThreadId());
	return 0;
}


int main()
{
	printf("	简单的创建多线程实例: ");
	// 线程的句柄在运行时是未触发的,线程结束运行,句柄出于触发设备
	HANDLE hThread = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
	// 在指定的时间内对象被触发,函数返回WAIT_OBJECT_0，超过时间则返回
	// WAIT_TIMEOUT,传入的参数错误返回WAIT_FAILED
	WaitForSingleObject(hThread, INFINITE);

	getchar();
}
