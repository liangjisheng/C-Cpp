
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
HANDLE ThreadEvent;
unsigned __stdcall ThreadFun(void *par);

int main()
{
	count = 0;
	HANDLE handles[num];
	// 自动重置，为激活的事件内核对象
	ThreadEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	for(int i = 0; i < num; i++)
	{
		// 创建执行线程，顺利创建第一个线程，然后程序会在WaitForSingleObject
		// 处等待，直到第一个线程将事件状态设置为激活状态，才能继续
		handles[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, 0);

		// 主线程内等待事件被激活，会自动调用ResetEvent()将时间设置为未激活
		WaitForSingleObject(ThreadEvent, INFINITE);
	}

	// 等待所有线程执行完毕
	WaitForMultipleObjects(num, handles, TRUE, INFINITE);

	// 关闭进程或线程句柄锁对应的进程或线程并没有立即结束
	for(int i = 0; i < num; i++)
		CloseHandle(handles[i]);
	CloseHandle(ThreadEvent);

	system("pause");
	return 0;
}

unsigned __stdcall ThreadFun(void *par)
{
	for(int i = 0; i < 10; i++)
		cout << "cout:" << ++count << endl;
	count = 0;

	// 设置事件为激活状态, 这里是执行线程
	cout << "SetEvent:" << SetEvent(ThreadEvent) << endl;	

	return 0;
}

