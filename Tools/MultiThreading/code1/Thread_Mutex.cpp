
// 在Windows系统下，进程有两部分组成：
// (1)操作系统用来管理进程的内核对象,这些对象用来存放进程统计信息
// 他们是操作系统内部分配的内存块，只能被内核访问使用，用用程序无
// 法找到该数据结构,并直接改变其内容。Windows提供了一些函数来对内
// 核对象进行操作
// (2)地址空间,它包含所有可执行的模块或DLL模块的代码和数据,也包含
// 动态分配的空间.例如线程的栈和堆

// 线程也由两部分组成：
// (1)线程的内核对象,操作系统用它来对线程进行管理，存放线程的统计信息
// (2)线程栈,它用于维护线程执行代码时所需要的所有函数和参数的局部变量

// 线程只有一个内核对象和一个栈，开销相对较少，因此在编程中经常采用
// 多线程来解决编程问题，而尽量避免创建新的进程
// 与线程相关的基本函数包括：
// CreateThread：创建线程
// CloseHandle：关闭线程句柄。注意，这只会使指定的线程句柄无效
// (减少该句柄的引用计数),启动句柄的检查操作，如果一个对象所关联的最后
// 一个句柄被关闭了，那么这个对象会从系统中被删除
// 关闭句柄不会终止相关的线程

// 线程是如何运行的呢？这又与你的CPU有关系了，如果你是一个单核CPU，那么
// 系统会采用时间片轮询的方式运行每个线程；如果你是多核CPU，那么线程之
// 间就有可能并发运行了。这样就会出现很多问题，比如两个线程同时访问一个
// 全局变量之类的。它们需要线程的同步来解决。所谓同步，并不是多个线程一
// 起同时执行，而是他们协同步调，按预定的先后次序执行。
// Windows下线程同步的基本方法有3种:互斥对象、事件对象、关键代码段(临界区)

// 互斥对象属于内核对象，包含3个成员：
// 1.使用数量：记录了有多少个线程在调用该对象
// 2.一个线程ID：记录互斥对象维护的线程的ID
// 3.一个计数器：前线程调用该对象的次数
// 与之相关的函数包括：
// 创建互斥对象：CreateMutex
// 判断能否获得互斥对象：WaitForSingleObject
// 对于WaitForSingleObject，如果互斥对象为有信号状态，则获取成功，函数将互斥
// 对象设置为无信号状态，程序将继续往下执行；如果互斥对象为无信号状态，
// 则获取失败，线程会停留在这里等待。等待的时间可以由参数控制
// 释放互斥对象：ReleaseMutex
// 当要保护的代码执行完毕后，通过它来释放互斥对象，使得互斥对象变为有信号
// 状态，以便于其他线程可以获取这个互斥对象。注意，只有当某个线程拥有互斥
// 对象时，才能够释放互斥对象，在其他线程调用这个函数不得达到释放的效果
// 这可以通过互斥对象的线程ID来判断


#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

DWORD WINAPI Thread1Proc(LPVOID lpParameter);
DWORD WINAPI Thread2Proc(LPVOID lpParameter);

int tickets = 100;
HANDLE hMutex;

int main()
{
	HANDLE hThread1 = NULL;
	HANDLE hThread2 = NULL;
	DWORD dwThread1 = 1;
	DWORD dwThread2 = 2;

	hMutex = CreateMutex(NULL,			// 默认安全级别
		FALSE,							// 创建它的线程不拥有互斥对象
		_T("myMutex"));					// 互斥量的名字,不是必须的
	if(!hMutex)
		return -1;

	hThread1 = CreateThread(NULL,		// 默认安全级别
		0,								// 默认栈大小
		Thread1Proc,					// 线程函数
		NULL,							// 函数参数
		0,								// 创建标志,0表示创建后直接运行
		&dwThread1);					// 线程id,不是必须的
	if(!hThread1)
		return -2;

	hThread2 = CreateThread(NULL, 0, Thread2Proc, NULL, 0, &dwThread2);
	if(!hThread2)
		return -3;

	Sleep(4000);
	Sleep(4000);

	// 关闭句柄只会使指定的线程句柄无效(减少该句柄的引用计数)
	// 关闭线程句柄并不会终止相关的线程
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	getchar();
	return 0;
}


DWORD WINAPI Thread1Proc(LPVOID lpParameter)
{
	while(true)
	{
		// 如果hMutex有信号，则获取成功,并将其设置成无信号状态
		WaitForSingleObject(hMutex, INFINITE);
		if(tickets > 0)
		{
			Sleep(10);
			printf("thread1 sell ticket:%d\n", tickets--);
			// 释放互斥量，将其设置成有信号状态，使得其他线程可以使用
			ReleaseMutex(hMutex);
		}
		else
		{
			ReleaseMutex(hMutex);
			break;
		}
	}

	return 0;
}


DWORD WINAPI Thread2Proc(LPVOID lpParameter)
{
	while(true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if(tickets > 0)
		{
			Sleep(10);
			printf("thread2 sell ticket:%d\n", tickets--);
			ReleaseMutex(hMutex);
		}
		else
		{
			ReleaseMutex(hMutex);
			break;
		}
	}

	return 0;
}

