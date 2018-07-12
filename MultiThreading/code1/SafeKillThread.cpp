
#include <Windows.h>
#include <stdio.h>
#include <process.h>

#define MY_MSG WM_USER + 100
const int MAX_INFO_SIZE = 20;

HANDLE hStartEvent;		// thread start event

// thread function
unsigned _stdcall fun(void* param)
{
	printf("thread fun start...\n");

	MSG msg;
	PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);

	if (!SetEvent(hStartEvent))		// set thread start event
	{
		printf("set start event failed, erron: %d\n", ::GetLastError());
		return 1;
	}

	// 线程会一直执行，没有什么条件使得线程退出
	while (true)
	{
		// get msg from message queue
		if (GetMessage(&msg, 0, 0, 0))
		{
			switch(msg.message)
			{
			case MY_MSG:
				char* pInfo = (char*)msg.wParam;
				printf("recv %s\n", pInfo);
				delete [] pInfo;
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
		}
		::Sleep(1000);
	}

	CloseHandle(hThread);
	return 0;
}
