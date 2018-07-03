
#include <stdio.h>

int main() 
{
	char buf[500];
	FILE *fp1,*fp2;
	if( ((fp1=fopen("test.txt","a"))!=NULL) && 
		((fp2=fopen("test2.txt","w"))!=NULL) )
	{
		// 应用setbuf函数给文件fp1指定缓冲区buf
		setbuf(fp1,buf);
		// 显示缓冲区地址
		printf("fp1 set to user-defined buffer at:%Fp\n",buf);
		// 文件流fp2不指定缓冲区
		setbuf(fp2,NULL);
		// 信息提示不分配缓冲区
		printf("fp2 buffering disbaled\n");
		fclose(fp1);
		fclose(fp2);
	}
	
	return 0;
}