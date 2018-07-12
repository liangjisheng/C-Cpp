#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE hpip;
	OVERLAPPED ovi={0};
	char buf[]={"命名管道测试程序"};
	DWORD readbuf;
	printf("正在连接命名管道\n");
	// 判断命名管道是否可用，连接命名管道
	if(WaitNamedPipe("\\\\.\\pipe\\pipename",NMPWAIT_WAIT_FOREVER)) {
		// 打开指定的命名管道
		hpip=CreateFile("\\\\.\\pipe\\pipename",GENERIC_READ | GENERIC_WRITE,0,
			NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
		if(hpip==INVALID_HANDLE_VALUE)
			printf("打开命名管道失败\n");
		
		else {
			if(WriteFile(hpip,buf,sizeof(buf),&readbuf,NULL))
				printf("数据写入成功\n");
			else 
				printf("数据写入失败\n");
		}
	}
	else
		printf("连接命名管道失败\n");
	system("pause");
	return 0;
}