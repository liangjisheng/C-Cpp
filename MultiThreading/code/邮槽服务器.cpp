#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE mail;
	// 创建邮槽
	mail=CreateMailslot("\\\\.\\mailslot\\mysolt",0,MAILSLOT_WAIT_FOREVER,NULL);
	if(mail==INVALID_HANDLE_VALUE) {
		printf("创建邮槽失败\n");
		CloseHandle(mail);
	}
	else {
		printf("创建邮槽成功,正在读取数据......!\n");
		char text[200];
		DWORD readtext;
		// 读取邮槽中的数据和读取文件函数一样
		if(ReadFile(mail,text,200,&readtext,NULL))
			printf("%s\n",text);
		else 
			printf("数据读取失败\n");
	}
	CloseHandle(mail);
	Sleep(1000);

	return 0;
}