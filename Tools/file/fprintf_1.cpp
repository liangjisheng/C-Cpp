
#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int i = 10;	
	double fp = 1.5;	
	char s[]="this is a string!";	
	char c = '\n';	
	FILE * stream;
	
	stream = fopen("fprintf.out", "w");	
	fprintf(stream, "%s%c", s, c);	
	fprintf(stream, "%d\n", i);	
	fprintf(stream, "%f\n", fp);	
	fclose(stream);	
	//此函数是将fprintf.out文件中的内容显示在屏幕上
	system("type fprintf.out");	
	
	return 0;	
}