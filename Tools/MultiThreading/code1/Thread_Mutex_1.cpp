
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 互斥量包含计数，线程ID，递归计数
// 互斥量的WaitForSingleObject-->ReleaseMute，关键段的
// EnterCriticalSection-->LeaveCriticalSection，都是必须在同一个线程
// 内执行，线程A拥有了资源的所有权，那么释放所有权也必须由线程A来执行

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
		handles[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, 0);

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
	ReleaseMutex(ThreadMutex);

	return 0;
}

