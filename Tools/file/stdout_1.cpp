
#include<stdio.h>

int main()
{
	char str[]="This is a test";
	int i=0;
	while(str[i++])
		fputc(str[i], stdout);
	printf("\n");
	
	return 0;
}