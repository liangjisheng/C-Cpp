
// 处理文本文件字符串的写入
#include <stdio.h>
#include <stdlib.h>

#define LEN 11;

void main()
{	
	FILE * fp;	
	char buffer[30], ch;	
	
	//   “at+” 读写打开一个文本文件，允许读，或在文件末追加数据 文件指针指向了文件的结尾处
	if( !(fp = fopen("qintangtao.txt", "at+")) ) 		
	{		
		printf("\nCannot open file strike any key exit!");		
		exit(1);		
	}	
	
	printf("Please input a string:\n");	
	// scanf("%s", buffer);  // 用scanf()；接收时 当遇到 空格、换行 就认为结束了	
	fgets(buffer, 30, stdin); //为什么不用scanf()? stdin又是什么？	
	fputs(buffer, fp);	
	rewind(fp); //重新定义文件内部指针指向文件的开头处	

	ch = fgetc(fp);	
	while( ch != EOF )		
	{		
		putchar(ch); //输出到屏幕上		
		ch = fgetc(fp);		
	}	
	
	printf("\n");	
	fclose(fp);	
	system("pause");	
}
