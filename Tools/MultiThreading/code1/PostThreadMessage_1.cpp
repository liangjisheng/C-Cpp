
// PostThreadMessage可以用于线程之间的异步通讯，因为它不用等待调用者返回，
// 这也许是线程通讯中最简单的一种方法了
// PostThreadMessage有时会失败，报1444错误(Invalid thread identifier. )
// 其实这不一定是线程不存在的原因，也有可能是线程不存在消息队列(message queue)造成的。
// 事实上，并不是每个thread都有message queue,那如何让thread具有呢？
// 答案是，至少调用message相关的function一次，比如GetMessage,PeekMessage

// 如果是post动态分配的memory给另外一个thread,要注意内存的正确释放
// PostThreadMessage不能够post WM_COPYDATE之类的同步消息，否则会报错
// 最好不要使用PostThreadMessage post message给一个窗口,使用PostMessage替代

// PostMessage通过指定目标窗口句柄来确定目标线程，通常情况下由窗口过程来处理消息
// PostThreadMessage直接指定线程ID来确定目标线程，没有目标窗口，只能在消息循环
// 中直接根据消息类型做相应的处理。在程序设计的选择方面，如果是UI线程
// 则应使用PostMessage;如果是工作线程，则应使用PostThreadMessage
// 不要为了接收消息而创建窗口。

#include <Windows.h>
#include <cstdio>
#include <process.h>

#define MY_MSG WM_USER + 100
const int MAX_INFO_SZIE = 20;

HANDLE hStartEvent;

// 消息队列由系统产生，消息循环由线程产生
// thread function
unsigned int __stdcall fun(void *param)
{
	printf("thread fun start...\n");
	MSG msg;
	PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);
	
	// 使事件变为有信号
	if(!SetEvent(hStartEvent))
	{
		printf("set start event failed,errno:%d\n", ::GetLastError());
		return 1;
	}

	while(true)
	{
		// Get msg from message queue
		if(GetMessage(&msg, 0, 0, 0))
		{
			switch(msg.message)
			{
			case WM_USER + 100:
				char *pInfo = (char*)msg.wParam;
				printf("recv %s\n", pInfo);
				delete []pInfo;
				break;
			}
		}
	}

	return 0;
}

int main()
{
	HANDLE hThread;
	unsigned int nThreadID;

	hStartEvent = ::CreateEventA(0, FALSE, FALSE, 0);
	if(0 == hStartEvent)
	{
		printf("create start event failed,errno:%d\n", ::GetLastError());
		return 1;
	}

	// start thread
	hThread = (HANDLE)_beginthreadex(NULL, 0, &fun, NULL, 0, &nThreadID);
	if(0 == hThread)
	{
		printf("start thread failed,errno:%d\n", ::GetLastError());
		CloseHandle(hStartEvent);
		return 1;
	}
	
	// wait thread start event to avoid PostThreadMessage return errno:1444
	::WaitForSingleObject(hStartEvent, INFINITE);
	CloseHandle(hStartEvent);

	int nCount = 0;
	while(true)
	{
		// create dynamic msg
		char *pInfo = new char[MAX_INFO_SZIE];
		sprintf(pInfo, "msg_%d", ++nCount);
		if(!PostThreadMessage(nThreadID, WM_USER + 100, (WPARAM)pInfo, 0))
		{
			printf("post thread message failed,errno:%d\n", ::GetLastError());
			delete [] pInfo;
		}
		// 每隔1000毫秒发一个线程消息
		::Sleep(1000);
	}

	system("pause");
	return 0;
}

