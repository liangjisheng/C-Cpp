#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);
DWORD WINAPI myfun3(LPVOID lpParameter);
HANDLE hevent;	// 事件句柄
int a=0;

int main()
{
	HANDLE h1,h2,h3;
	hevent=::CreateEvent(NULL,FALSE,false,NULL); // 自动重置的无信号事件
	::SetEvent(hevent);	// 设置事件状态为有信号
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);
	printf("线程1开始运行\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);
	printf("线程2开始运行\n");
	h2=::CreateThread(NULL,0,myfun3,NULL,0,NULL);
	printf("线程3开始运行\n");
	::CloseHandle(h1);
	::CloseHandle(h2);
	::CloseHandle(h3);
	::Sleep(50000);
	return 0;
}

DWORD WINAPI myfun1(LPVOID lpParameter)
{
	while(1) {
		// 第二个参数表示该函数在事件对象上的等待时间，INFINITE表示该函数将永远等待
		::WaitForSingleObject(hevent,INFINITE);	// 请求事件对象
		::ResetEvent(hevent);		// 设置事件对象为无信号状态
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程1 %d\n",a);
			::SetEvent(hevent);		// 设置事件对象为有信号状态
		}
		else {
			::SetEvent(hevent);
			break;
		}
	}
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	while(1) {
		// 第二个参数表示该函数在事件对象上的等待时间，INFINITE表示该函数将永远等待
		::WaitForSingleObject(hevent,INFINITE);	// 请求事件对象
		::ResetEvent(hevent);		// 设置事件对象为无信号状态
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程2 %d\n",a);
			::SetEvent(hevent);		// 设置事件对象为有信号状态
		}
		else {
			::SetEvent(hevent);
			break;
		}
	}
	return 0;
}

DWORD WINAPI myfun3(LPVOID lpParameter)
{
	while(1) {
		// 第二个参数表示该函数在事件对象上的等待时间，INFINITE表示该函数将永远等待
		::WaitForSingleObject(hevent,INFINITE);	// 请求事件对象
		::ResetEvent(hevent);		// 设置事件对象为无信号状态
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程3 %d\n",a);
			::SetEvent(hevent);		// 设置事件对象为有信号状态
		}
		else {
			::SetEvent(hevent);
			break;
		}
	}
	return 0;
}