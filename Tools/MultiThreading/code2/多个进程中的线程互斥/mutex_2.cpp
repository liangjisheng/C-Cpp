
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

const TCHAR MUTEX_NAME[] = _T("Mutex_MoreWindows");


int main()
{
	HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, TRUE, MUTEX_NAME);
	if(NULL == hMutex)
	{
		printf("打开互斥量失败\n");
		return 0;
	}

	printf("等待互斥量触发......\n");
	// 等待互斥量被触发，若5秒内互斥量未被触发，则继续往下执行
	DWORD dwResult = WaitForSingleObject(hMutex, 5 * 1000);

	switch(dwResult)
	{
	case WAIT_ABANDONED:
		printf("拥有互斥量的进程意外终止\n");
		break;
	case WAIT_OBJECT_0:
		printf("已经收到信号\n");
		break;
	case WAIT_TIMEOUT:
		printf("信号在未规定的时间内送到\n");
		break;
	}

	CloseHandle(hMutex);

	getchar();
	return 0;
}