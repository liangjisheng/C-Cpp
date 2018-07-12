#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);

int main()
{
	HANDLE h1,h2;
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);
	printf("线程1开始运行!\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);
	printf("线程2开始运行!\n");
	::CloseHandle(h1);
	::CloseHandle(h2);
	if(getchar()=='q') return 0;
	else ::Sleep(1000);
}

DWORD WINAPI myfun1(LPVOID lpParameter)
{
	printf("线程1正在运行\n");
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	printf("线程2正在运行\n");
	return 0;
}