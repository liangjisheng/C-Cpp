#include"windows.h"
#include"stdio.h"

int main()
{
	HANDLE read=NULL;
	char text[100]={0};
	DWORD readtext;
	read=GetStdHandle(STD_INPUT_HANDLE);	// 获取读取句柄
	if(ReadFile(read,text,100,&readtext,NULL))
		printf("从匿名管道中读取的数据是:%s\n",text);

	system("pause");
	return 0;
}