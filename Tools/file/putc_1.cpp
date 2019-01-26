
#include <stdio.h>

int main() 
{
	FILE *fp;
	int i=0;
	char str[]="This is a test!";
	fp=fopen("test.txt","w");
	while(str[i]) putc(str[i],fp),i++,putc(str[i],stdout);
	putc('\n',stdout);
	
	fclose(fp);
	return 0;
}