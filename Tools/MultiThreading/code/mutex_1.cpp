#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);
HANDLE hmutex;
int a=0;

int main()
{
	hmutex=::CreateMutex(NULL,false,NULL); // 无信号的互斥对象
	HANDLE h1,h2;
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);
	printf("线程1开始运行\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);
	printf("线程2开始运行\n");
	::CloseHandle(h1);
	::CloseHandle(h2);
	::Sleep(10000);
	return 0;
}

DWORD WINAPI myfun1(LPVOID lpParameter)
{
	while(1) {
		::WaitForSingleObject(hmutex,INFINITE);	// 请求互斥对象
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程1: %d\n",a);
			::ReleaseMutex(hmutex);	// 释放互斥对象，使之处于有信号状态
		}
		else{
			::ReleaseMutex(hmutex);
			break;
		}
	}
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	while(1) {
		::WaitForSingleObject(hmutex,INFINITE);	// 请求互斥对象
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程2: %d\n",a);
			::ReleaseMutex(hmutex);
		}
		else{
			::ReleaseMutex(hmutex);
			break;
		}
	}
	return 0;
}