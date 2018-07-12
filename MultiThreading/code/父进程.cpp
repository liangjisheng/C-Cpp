#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE read=NULL,write=NULL;
	SECURITY_ATTRIBUTES ss;
	STARTUPINFO sa={0};
	PROCESS_INFORMATION pp={0};
	char text[]="匿名管道程序测试";
	DWORD writetext;
	ss.nLength=sizeof(ss);
	ss.lpSecurityDescriptor=NULL;
	ss.bInheritHandle=true;
	// 创建匿名管道
	if(CreatePipe(&read,&write,&ss,0)) {
		printf("创建匿名管道成功\n");
		sa.cb=sizeof(sa);
		sa.dwFlags=STARTF_USESHOWWINDOW;
		sa.hStdInput=read;
		sa.hStdOutput=write;
		sa.hStdError=GetStdHandle(STD_ERROR_HANDLE);
		if(::CreateProcess(NULL,"子进程.exe",NULL,NULL,
			true,0,NULL,NULL,&sa,&pp)) {
			printf("创建子进程成功\n");
			WriteFile(write,text,sizeof(text),&writetext,NULL);
			printf("通过匿名管道写入数据成功\n");
		}
		else
			printf("创建子进程失败\n");
	}
	system("pause");
	return 0;
}