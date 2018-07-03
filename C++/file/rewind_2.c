#include"stdio.h"
void main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("string","wt+"))==NULL)
	{printf("Cannot open file strike any key exit!");}
	printf("input a string:\n");
	ch=getchar();
	while(ch!='\n')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	rewind(fp);
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	printf("\n");
	fclose(fp);
}