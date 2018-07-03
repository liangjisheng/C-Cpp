
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fp;
	char ch, filename[20];
	printf("Please input the filename you want to write:");
	scanf("%s", filename);
	getchar();		// 丢弃换行符
	//  文件的打开（fopen函数）;  “wt+” 读写打开或建立一个文本文件，允许读写
	if(!(fp = fopen(filename, "wt+"))) 
	{
		printf("Cannot open the file!\n");
		exit(0);//终止程序
	}
	printf("Please input the sentences you want to write:\n");
	ch = getchar(); 
	while( ch != '\n')
	{
		fputc(ch, fp);
		ch = getchar();
	}
	if('\n' == ch)
		printf("write success\n");

	getchar();
	fclose(fp);
}