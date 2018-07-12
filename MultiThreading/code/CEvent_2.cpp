#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);
CEvent event;
int a=0;

int main()
{
	event=CEvent(false,false,NULL,NULL);	// 自动重置的无信号事件
	event=::CreateEvent(NULL,false,false,NULL);
	event.SetEvent();	// 设置事件有信号
	HANDLE h1,h2;
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);
	printf("线程1正在运行\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);
	printf("线程2正在运行\n");
	::CloseHandle(h1);
	::CloseHandle(h2);
	::Sleep(10000);
	return 0;
}

DWORD WINAPI myfun1(LPVOID lpParameter)
{
	while(1) {
		::WaitForSingleObject(event.m_hObject,INFINITE);	// 请求事件对象
		event.ResetEvent();	// 设置事件无信号
		if(a<10000) {
			a++;
			printf("线程1: %d\n",a);
			event.SetEvent();
		}
		else {
			event.SetEvent();
			break;
		}
	}
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	while(1) {
		::WaitForSingleObject(event.m_hObject,INFINITE);	// 请求事件对象
		event.ResetEvent();	// 设置事件无信号
		if(a<10000) {
			a++;
			printf("线程2: %d\n",a);
			event.SetEvent();
		}
		else {
			event.SetEvent();
			break;
		}
	}
	return 0;
}