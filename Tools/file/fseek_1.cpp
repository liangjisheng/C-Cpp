
#include<stdio.h>

int main() 
{
	FILE *fp;
	char str[]="This is a test";
	char string[20];
	fp=fopen("test.txt","w+");
	fwrite(str,strlen(str),1,fp);
	fseek(fp,0,SEEK_SET);
	fgets(string,strlen(str)+1,fp);
	puts(string);
	
	fclose(fp);
	return 0;
}