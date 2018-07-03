
#include<stdio.h>

int main() 
{
	FILE *fp;
	char str[]="This is a test";
	fpos_t pos;
	fp=fopen("test.txt","w+");
	fwrite(str,strlen(str),1,fp);
	fgetpos(fp,&pos);
	printf("The file pointer is at byte %ld\n",pos);
	fseek(fp,3,0);
	fgetpos(fp,&pos);
	printf("The file pointer is at byte %ld\n",pos);
	
	fclose(fp);
	return 0;
}
