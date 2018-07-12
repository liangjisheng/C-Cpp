
#include <stdio.h>
#include <stdlib.h>		// for malloc
#include <string.h>

void GetMemory(char **p, int num)
{
	*p = (char*)malloc(num);
	// *运算符的优先级比[]高，如果去掉()则会内存访问出错
	for(int i = 0; i < num; i++)
		(*p)[i] = '\0';
}


void Test(void)
{
	char *str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
	printf("\n");
}


int main()
{
	Test();

	getchar();
	return 0;
}