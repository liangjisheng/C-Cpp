
// fgets(),读取文本文件字符串
#include <stdio.h>
#include <stdlib.h>

#define LEN 11;

void main()
{	
	FILE * fp;	
	char buffer[11];	
	if( !(fp = fopen("qintangtao.txt", "rt")) ) //是否能够打开文件		
	{		
		printf("\nCannot open file strike any key exit!");		
		exit(1);		
	}	
	
	fgets(buffer, 11, fp); //从fp中读出11个字节存放在buffer中	
	printf("%s\n", buffer);
	
	fclose(fp);	
	system("pause");	
}