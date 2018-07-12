
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 互斥量包含计数，线程ID，递归计数

const int num = 2;
int count;
HANDLE ThreadMutex;
unsigned __stdcall ThreadFun(void *par);

int main()
{
	count = 0;
	HANDLE handles[num];
	// 互斥量对象的线程ID和递归计数初始化为0，互斥量现在不为任何线程占用
	ThreadMutex = CreateMutex(NULL, FALSE, NULL);

	for(int i = 0; i < num; i++)
	{
		// 下面这句话，主线程获得了互斥量，导致主线程挂起，等待某个线程释放
		// 互斥量，但此时没有任何一个线程拥有互斥量，造成死锁
		WaitForSingleObject(ThreadMutex, INFINITE);
		handles[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, 0);
	}

	// 等待所有线程执行完毕
	WaitForMultipleObjects(num, handles, TRUE, INFINITE);

	// 关闭进程或线程句柄锁对应的进程或线程并没有立即结束
	for(int i = 0; i < num; i++)
		CloseHandle(handles[i]);
	CloseHandle(ThreadMutex);

	system("pause");
	return 0;
}

unsigned __stdcall ThreadFun(void *par)
{
	// 等待互斥量对象(内部检查互斥量对象的线程ID是否为0，0为触发状态)
	// 如果线程ID不为0，那么调用线程将进入等待状态
	WaitForSingleObject(ThreadMutex, INFINITE);
	// Sleep(100);
	for(int i = 0; i < 10; i++)
		cout << "cout:" << ++count << endl;
	count = 0;

	// 释放对资源的所有权，将互斥量对象的线程ID设置为0
	cout << "ReleaseMutex:" << ReleaseMutex(ThreadMutex);

	return 0;
}

