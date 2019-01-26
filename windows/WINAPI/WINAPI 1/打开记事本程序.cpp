/* HINSTANCE ShellExecute(
	HWND hwnd,		// 父窗口句柄
	LPCTSTR lpOperation,	// 将要进行的操作形式
	LPCTSTR lpFile,			// 目录文件名或文件路径
	LPCTSTR lpParammeters,	// 传递的参数
	LPCTSTR lpDirectory,	// 一般为NULL
	INT nShowCmd			// 显示方式
)
*/
#include"stdio.h"
#include"windows.h"

int main()
{
	int i=0;
	char ch;
	printf("确定打开记事本程序吗(y/n)?");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y') {
		printf("记事本程序正在打开,请稍候......\n");
		while(i<=100000000)
			i++;
		ShellExecute(NULL,NULL,"notepad",
			NULL,NULL,SW_SHOW);
		printf("记事本程序已经打开,请使用\n");
	}
	else 
		printf("谢谢使用\n");

	system("pause");
	return 0;
}