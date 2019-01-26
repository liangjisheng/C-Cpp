
// 多线程资源访问冲突，创建两个线程，按照计数递增的顺序输出计数
#include "windows.h"
#include "stdio.h"

int number = 1;
HANDLE hSemaphore;

unsigned long __stdcall ThreadProc1(void* lpParameter)
{
	long count = 0;
	while(number < 100)
	{
		WaitForSingleObject(hSemaphore,INFINITE);		// 等待信号量为有信号状态
		printf("线程1当前计数:%d\n",number);
		number++;
		Sleep(100);		// 为了演示数字是输出效果，加上延时
		// ReleaseSemaphore(HANDLE hSemaphore,LONG lReleaseCount,LPLONG lpPreviousCount);
		// lReleaseCount : 信号量的递增数量
		// lpPreviousCount : 返回之前的信号量的使用计数
		ReleaseSemaphore(hSemaphore,1,&count);		// 使信号量有信号
	}
	return 0;
}

unsigned long __stdcall ThreadProc2(void* lpParameter)
{
	long count = 0;
	while(number < 100)
	{
		WaitForSingleObject(hSemaphore,INFINITE);
		printf("线程2当前计数:%d\n",number);
		number++;
		Sleep(100);
		ReleaseSemaphore(hSemaphore,1,&count);
	}
	return 0;
}

int main(int argc,char* argv[])
{
	HANDLE hThread1 = CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
	HANDLE hThread2 = CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

	// HANDLE CreateSemaphore(LPSECURITY_ATTRIBUTES lpSemaphoreAttribute,LONG lInitialCount,
	// LONG lMaximumCount,LPCTSTR lpName);
	// lInitialCount : 信号量的初始计数
	// lMaximumCount : 信号量的最大计数
	// lpName : 信号量的名称
	hSemaphore = CreateSemaphore(NULL,1,100,"Sem");		// 创建信号量对象
	CloseHandle(hThread1);		// 关闭线程句柄
	CloseHandle(hThread2);

//	while(true)					// 定义一个循环，防止程序退出
//	{;}

	getchar();
	return 0;
}