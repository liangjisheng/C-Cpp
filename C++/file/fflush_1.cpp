
#include<stdio.h>

int main() 
{
	FILE *stream1,*stream2;
	char test[20]="This is a test";
	char res[20];
	stream1=fopen("test.txt","w");
	fwrite(test,15,1,stream1);
	// 此行必须有,用来刷新缓冲区,使缓冲区中的内容输入到文件中
	fflush(stream1);
	stream2=fopen("test.txt","r");
	if(fread(res,15,1,stream2))
		printf("%s\n",res);
	else 
		printf("Read error!\n");
	
	fclose(stream1);
	fclose(stream2);
	getchar();

	return 0;
}