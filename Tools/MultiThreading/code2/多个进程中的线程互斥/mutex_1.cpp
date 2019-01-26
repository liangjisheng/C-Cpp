
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <Windows.h>

const TCHAR MUTEX_NAME[] = _T("Mutex_MoreWindows");


int main()
{
	HANDLE hMutex = CreateMutex(NULL, TRUE, MUTEX_NAME);
	printf("互斥量已经创建，现在按任意键触发互斥量\n");
	getch();
	// 若将下面这句话取消注释，则互斥量一被触发程序就退出了，别的程序中
	// 如果使用这个名称的互斥量在等待触发，将会受到WAIT_ABANDONED，表示
	// 拥有互斥量的进程意外终止
	// exit(0);
	ReleaseMutex(hMutex);
	printf("互斥量已经触发\n");
	CloseHandle(hMutex);

	getchar();
	return 0;
}