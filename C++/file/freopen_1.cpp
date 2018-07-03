
#include<stdio.h>

int main() 
{
	// FILE *freopen(char *filename,char *type,FILE *fp)
	// 关闭fp所指向的文件，并将该文件中的数据流替换到
	// filename所指向的文件中去
	FILE *Nfp;
	if((Nfp=freopen("test.txt","w",stdout))==NULL)
		fprintf(stderr,"error redirecting stdout\n");
	
	// 标准输出文件上的数据流将会被替换到新文件中
	printf("This will go into a file.");
	
	fclose(stdout);
	fclose(Nfp);
	return 0;
}