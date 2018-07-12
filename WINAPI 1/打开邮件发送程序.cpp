#include"stdio.h"
#include"windows.h"

int main()
{
	int i=0;
	char ch;
	printf("确定打开邮件收发程序!(y/n)?");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y') {
		printf("邮件收发程序正在打开,请稍候......\n");
		while(i<=100000000)
			i++;
		ShellExecute(NULL,NULL,"mailto:1294851990@qq.com",
			NULL,NULL,SW_SHOW);
		printf("邮件收发程序已经打开,请使用\n");
	}
	else 
		printf("谢谢使用\n");

	system("pause");
	return 0;
}