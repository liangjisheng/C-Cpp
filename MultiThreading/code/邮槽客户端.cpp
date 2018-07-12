#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE mail2;
	char text[]="您好，this is a message";
	DWORD writetext;
	mail2=CreateFile("\\\\.\\mailslot\\my",GENERIC_WRITE,FILE_SHARE_READ,
		NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);	// 打开文件
	if(mail2==INVALID_HANDLE_VALUE)
		printf("打开邮槽失败\n");
	else {
		if(WriteFile(mail2,text,sizeof(text),&writetext,NULL)) {
			Sleep(1000);
			printf("数据写入成功\n");
		}
		else 
			printf("数据写入失败\n");
		CloseHandle(mail2);
	}
	Sleep(1000);
	system("pause");
	return 0;
}