
// fgetc(),fputc(),只能处理文本文件的单个字符
#include <stdio.h>
#include <stdlib.h> 

void main()
{
	FILE * fp;
	char ch, filename[20];
	printf("Please input the filename you want to write:");
	scanf("%s", filename);
	if(!(fp = fopen(filename, "r")))
	{
		printf("Cannot open the file!\n");
		exit(0);//终止程序
	}
	while( ch != EOF) //EOF为文件结束 EOF 也就等价于 -1 表示读到文件末尾了 或者说 是 文件的结束符
	{
		ch = fgetc(fp);
		putchar(ch); //putchar();用于把ch显示在屏幕上
	}

	getchar();
	fclose(fp);
}