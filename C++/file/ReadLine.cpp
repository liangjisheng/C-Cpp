
// 从标准输入流中读入整行
#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	FILE * fp;	
	char student[50];	
	int i;	
	// 当输入 1001 tom 92.3  时 只能把1001存入文件中 因为在遇到空格时 
	// scanf就把它当成了结束的标记 所以要用下面的  gets(student); 来进行输入
	//scanf("%s", student); 
	
	if( (fp=fopen("student.txt", "w"))==NULL )		
		exit(0);
	
	for(i=0; i<3; i++)		
	{		
		gets(student);		
		fputs(student, fp); //整行的存入文件中		
		fputs("\n", fp); //换行		
	}
	
	getchar();
	return 0;	
}