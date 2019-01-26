
/***********************************************************
 * @name: FriendThreadFunc.cpp
 * @brief: 友元线程函数
 * @author: 梁基圣
 * @date: 2018/7/20 20:29:04
 * @version: 1.0
 **********************************************************/

// 把线程函数设置成类的友元函数，这样线程函数可以访问类中的成员变量

// ExitThread  VS _endthreadex
// 在编写C\C++程序时，要调用_endthreadex来结束线程。基于如下两个理由：
// 1.ExitThread为非C++函数，线程创建的C++对象不会被析构
// 2.如果线程中分配的线程私有内存，ExitThread不会释放内存，造成内存泄露

// CreateThread VS _beginthreadex
// CreateThread有可能照成内存泄露,（如果使用了线程私有内存，而CreateThread并不会在内部自动调用释放
// 内存函数，但若链接的是C/C++运行库的dll版本，则其会在线程退出的DLL_THREAD_DETCH通知中释放内存）

// 不应该再使用_beginthread和_endthread
// 对于_beginthread函数，可以看出其函数参数是较少的，例如其中不包括安全属性，
// 让我们对线程的控制力没有其增强版本多
// 同时，由于在_beginthread内部会调用_endthread函数，而该函数多此一举的会调用一次
// CloseHandle，来帮我们关闭线程句柄

// HANDLE hThread = _beginthread(...);
// WaitForSingleObject(hThread, INFINITE);
// CloseHandle(hThread);
// 上面三行代码在真正调用WaitForSingleObject之前，_beginthread函数里的线程可能已经执行完毕，
// 同时，_endthread会释放handle句柄。那么再调用WaitForSingleObject时，可能这时的hThread已经
// 是一个无效句柄，导致函数调用失败，同理，对CloseHandle也是一样
// 所以在windows下调用_beginthread创建子线程并获得子线程id，然后主线程调用WaitForSingleObject
// 等待子线程结束,有可能造成主线程卡死

#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>

using namespace std;

uintptr_t subThreadid;
uintptr_t subThreadid_2;
CRITICAL_SECTION g_cs;

class ExampleTask 
{
public:
	ExampleTask(int v = 0) { value = v; }
	friend unsigned int __stdcall taskmain(LPVOID param);
	friend unsigned int __stdcall taskmain_2(LPVOID param);
	void StartTask();
	void StartTask_2();

private:
	int value;
};

unsigned int __stdcall taskmain(LPVOID param)
{
	// 通过类指针使用类中的成员变量
	ExampleTask *pTaskMain = (ExampleTask *)param;

	// 对控制台输出资源进行互斥
	EnterCriticalSection(&g_cs);
	cout << "run in subThread" << endl;
	LeaveCriticalSection(&g_cs);

	// 因为线程中日志写入的文件名并不一样，所以不需要加互斥
	// 若写入同一个文件，则需要加互斥
	ofstream ofs("thread.txt");	
	ofs << "run in subThread" << endl;
	ofs << pTaskMain->value << endl;
	ofs.close();

	Sleep(2000);
	return 0;
}

unsigned int __stdcall taskmain_2(LPVOID param)
{
	// 通过类指针使用类中的成员变量
	ExampleTask *pTaskMain = (ExampleTask *)param;

	// 对控制台输出资源进行互斥
	EnterCriticalSection(&g_cs);
	cout << "run in subThread 2" << endl;
	LeaveCriticalSection(&g_cs);

	ofstream ofs("thread2.txt");
	ofs << "run in subThread 2" << endl;
	ofs << pTaskMain->value << endl;
	ofs.close();

	Sleep(2000);
	return 0;
}

void ExampleTask::StartTask()
{
	// _beginthreadex,在函数开始出，在C/C++运行库堆上分配并初始化每个线程的私有内存
	// 线程函数与参数被存储到私有内存中，_beginthreadex最终调用CreateThread()（毕竟windows系统只认识其API）
	// _endthreadex与_beginthreadex对应，_endthreadex是C/C++运行库终止线程运行的函数
	// _endthreadex销毁了在_beginthreadex分配的堆内存（保证了没有内存泄露）
	// _endthreadex调用了系统API ExitThread退出线程
	subThreadid = _beginthreadex(NULL, 0, taskmain, this, 0, NULL);
}

void ExampleTask::StartTask_2()
{
	subThreadid_2 = _beginthreadex(NULL, 0, taskmain_2, this, 0, NULL);
}

int main()
{
	InitializeCriticalSection(&g_cs);
	cout << "run in main thread" << endl;
	ExampleTask realTimeTask(3);
	// 两个线程输出到控制台时，会争夺控制台，需要加上互斥
	realTimeTask.StartTask();
	realTimeTask.StartTask_2();

	WaitForSingleObject((HANDLE)subThreadid, INFINITE);
	WaitForSingleObject((HANDLE)subThreadid_2, INFINITE);

	cout << "main thread go on" << endl;

	CloseHandle((HANDLE)subThreadid);
	CloseHandle((HANDLE)subThreadid_2);
	DeleteCriticalSection(&g_cs);

	return 0;
}
