#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);
static int a=0;
CRITICAL_SECTION Section;	// 临界区对象

int main()
{
	HANDLE h1,h2;
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);
	printf("线程1开始运行\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);
	printf("线程2开始运行\n");
	::CloseHandle(h1);
	::CloseHandle(h2);
	InitializeCriticalSection(&Section);	// 初始化临界区
	::Sleep(1000);
	printf("正常退出程序请按'q'\n");
	if(getchar()=='q') DeleteCriticalSection(&Section);	// 删除临界区对象
	else return 0;
}

DWORD WINAPI myfun1(LPVOID lpParameter)
{
	while(1) {
		EnterCriticalSection(&Section);	// 进入临界区
		a++;
		if(a<10000) {
			::Sleep(1000);
			printf("线程1正在计数%d\n",a);
			LeaveCriticalSection(&Section);	// 离开临界区
		}
		else {
			LeaveCriticalSection(&Section);
			break;
		}
	}
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	while(1) {
		EnterCriticalSection(&Section);
		a++;
		if(a<10000) {
			::Sleep(1000);
			printf("线程2正在计数%d\n",a);
			LeaveCriticalSection(&Section);
		}
		else {
			LeaveCriticalSection(&Section);
			break;
		}
	}
	return 0;
}