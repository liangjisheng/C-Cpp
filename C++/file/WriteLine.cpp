
// 在标准输出流，输出整行
#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	FILE * fp;	
	char string[80];	
	
	if( (fp=fopen("student.txt", "r"))==NULL )		
		exit(0);	
	
	while( fgets(string, 80, fp)!=NULL )		
	{		
		//printf("%s", string); //也可以用下面的方法将内容显示在屏幕上		
		fputs(string, stdout); //stdout函数是将内容显示到屏幕上		
	}

	getchar();
	return 0;
}