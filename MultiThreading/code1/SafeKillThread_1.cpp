
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

#define MY_MSG WM_USER + 100
const int MAX_INFO_SIZE = 20;

HANDLE hStartEvent;		// thread start event

// thread function
unsigned _stdcall fun(void* param)
{
	printf("thread fun start...\n");

	MSG msg;
	// PostThreadMessage有时会失败，报1444错误(Invalid thread identifier)
	// 其实这不一定是线程不存在的原因，也有可能是线程不存在消息队列(message queue)造成的。
	// 事实上，并不是每个thread都有message queue,那如何让thread具有呢？
	// 答案是，至少调用message相关的function一次，比如GetMessage,PeekMessage
	// 强制使得这个线程具有消息队列
	PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);

	if (!SetEvent(hStartEvent))		// set thread start event
	{
		printf("set start event failed, errno: %d\n", ::GetLastError());
		return 1;
	}

	BOOL bRun = TRUE;
	while (bRun)
	{
		// get msg from message queue
		if (::PeekMessage(&msg, NULL, 0, 0, 0))	// 不等待
		{
			switch(msg.message)
			{
			case MY_MSG:
				char* pInfo = (char*)msg.wParam;
				printf("recv %s\n", pInfo);
				delete [] pInfo;
				bRun = FALSE;		// 退出
				break;
			}
		}
	}

	return 0;
}


int main()
{
	HANDLE hThread;
	unsigned nThreadID;

	hStartEvent = ::CreateEvent(NULL, FALSE, FALSE, 0);
	if (0 == hStartEvent)
	{
		printf("create start event failed, errno: %d\n", ::GetLastError());
		return 1;
	}

	// start thread
	hThread = (HANDLE)_beginthreadex(NULL, 0, &fun, NULL, 0, &nThreadID);
	if (hThread == 0)
	{
		printf("start thread failed, errno: %d\n", ::GetLastError());
		CloseHandle(hStartEvent);
		return 1;
	}

	// wait thread start event to avoid PostThreadMessage return errno: 1444
	::WaitForSingleObject(hStartEvent, INFINITE);
	CloseHandle(hStartEvent);

	int count = 0;

	while (true)
	{
		char *pInfo = new char[MAX_INFO_SIZE];	// create dynamic msg
		sprintf(pInfo, "msg_%d", ++count);
		// post thread msg
		if (!PostThreadMessage(nThreadID, MY_MSG, (WPARAM)pInfo, 0))
		{
			printf("post message failed, errno: %d\n", ::GetLastError());
			delete [] pInfo;
			break;
		}
		::Sleep(1000);
	}

	CloseHandle(hThread);

	system("pause");
	return 0;
}
