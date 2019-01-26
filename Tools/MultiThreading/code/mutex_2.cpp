// Mutex 用于进程间的同步
#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE hmutex;
	hmutex=::CreateMutex(NULL,true,"VC网络编程");
	if(hmutex) {
		if(ERROR_ALREADY_EXISTS==GetLastError())	// 获取错误
			printf("只允许有一个实例程序运行\n");
	}
	else 
		printf("实例程序运行成功\n");
	::ReleaseMutex(hmutex);
	::Sleep(10000);

	return 0;
}