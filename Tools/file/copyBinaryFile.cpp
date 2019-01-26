
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in, *out;
	char infile[10];
	char outfile[10];
	char c;
	printf("enter the infile name:\n");
	scanf("%s", infile);
	printf("enter the outfile name:\n");
	scanf("%s", outfile);
	
	if( (in=fopen(infile, "rb")) == NULL ) //     “rb”    只读打开一个二进制文件，只允许读数据
		exit(0);
	if( (out=fopen(outfile, "wb")) == NULL ) //      “wb”    只写打开或建立一个二进制文件，只允许写数据
		exit(0);
	
	c=fgetc(in); //fgetc(), getc() 从指定文件取得一个字符
	while(!feof(in)) //文件状态 feof() 若到文件末尾，函数值为真
	{
		fputc(c, out); //fputc(), putc() 把字符输出到指定文件
		c=fgetc(in);
	}
	
	fclose(in);	
	fclose(out);
	
	getchar();
	return 0;	
}