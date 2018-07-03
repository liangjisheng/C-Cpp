
#include<stdio.h>

int main() 
{
	FILE *fp = NULL;
	char ch;
	fp = fopen("test.txt", "w");
	ch = fgetc(fp);
	if (ferror(fp))
		printf("This is a error reading!\n");
	
	fclose(fp);
	return 0;
}