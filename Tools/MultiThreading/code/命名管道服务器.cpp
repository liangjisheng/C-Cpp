#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE hpip;	// 命名管道句柄
	OVERLAPPED ovi={0};	 // 结构体变量
	char buf[200];
	DWORD readbuf;
	// 创建命名管道
	hpip=CreateNamedPipe("\\\\.\\pipe\\pipename",PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE,PIPE_UNLIMITED_INSTANCES,1024,1024,0,NULL);
	printf("创建管道成功，正在等待客户端连接!\n");
	if(::ConnectNamedPipe(hpip,&ovi)) {
		printf("客户端连接成功\n");
		printf("正在读取数据\n");
		// 读取管道数据
		if(ReadFile(hpip,buf,200,&readbuf,NULL)) {
			printf("数据读取成功\n");
			printf("读取的数据是:%s\n",buf);
		}
		else
			printf("读取数据失败\n");
	}
	
	system("pause");
	return 0;
}