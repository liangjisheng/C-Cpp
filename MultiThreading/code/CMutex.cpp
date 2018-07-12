#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);
CMutex hmutex(NULL,false,NULL);  // 无信号的互斥对象
int a=0;

int main()
{
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
		hmutex.Lock(INFINITE);	// 锁定互斥对象
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程1: %d\n",a);
			hmutex.Unlock();	// 释放互斥对象，使之处于有信号状态
		}
		else{
			hmutex.Unlock();
			break;
		}
	}
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	while(1) {
		hmutex.Lock();	// 请求互斥对象
		if(a<10000) {
			a++;
			::Sleep(1000);
			printf("线程2: %d\n",a);
			hmutex.Unlock();
		}
		else{
			hmutex.Unlock();
			break;
		}
	}
	return 0;
}