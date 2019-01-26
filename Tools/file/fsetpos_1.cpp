#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
#include"io.h"

int main() 
{
	FILE *fp;
	char str[]="This is a test for testing the function of fsetpos";
	fpos_t pos;
	char buffer[50];
	if((fp=fopen("test.txt","rb+")) == NULL)
		printf("Trouble opening file\n");
	else 
	{
		fwrite(str,strlen(str),1,fp);
		fflush(fp);
		pos=10;
		if(fsetpos(fp,&pos)!=0)
			perror("fsetpos error\n");
		else 
		{
			fread(buffer,sizeof(char),16,fp);
			buffer[16]='\0';
			printf("16 bytes at byte %d:%s\n",pos,buffer);
		}
	}
	
	fclose(fp);
	return 0;
}