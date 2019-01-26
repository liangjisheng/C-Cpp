
#include<stdio.h>

int main() 
{
	char ch;
	// printf("Please input an character:");
	// 上一行代码与下一行代码等价，都是向显示器输出提示
	fprintf(stdout,"Please input an character:");
	if(fscanf(stdin,"%c",&ch))
		printf("The character was:%c\n",ch);
	else 
	{
		fprintf(stderr,"Erroe reading an character from stdin!\n");
		exit(1);
	}
	
	return 0;
}