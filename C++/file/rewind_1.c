
#include <stdio.h>

int main() 
{
	// rewind:重定位文件指针
	FILE *fp;
	int data1=1,data2=2;
	if((fp=fopen("test.txt","w+"))!=NULL) 
	{
		fprintf(fp,"%d,%d",data1,data2);
		printf("%d,%d\n",data1,data2);
		data1=0;data2=0;
		rewind(fp);
		fscanf(fp,"%d,%d",&data1,&data2);
		printf("%d,%d\n",data1,data2);
		fclose(fp);
	}
	
	return 0;
}
