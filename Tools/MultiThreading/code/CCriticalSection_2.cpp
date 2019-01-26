#include"windows.h"
#include"stdio.h"
DWORD WINAPI myfun1(LPVOID lpParameter);
DWORD WINAPI myfun2(LPVOID lpParameter);
;CCriticalSection m_Sec;
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
	::Sleep(1000);
	return 0;
}

DWORD WINAPI myfun1(LPVOID lpParameter)
{
	m_Sec.Lock();	// 锁定临界区
	a++;
	printf("%d\n",a);
	m_Sec.Unlock();	// 对临界区进行解锁
	return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
	m_Sec.Lock();
	a++;
	printf("%d\n",a);
	m_Sec.Unlock();
	return 0;
}