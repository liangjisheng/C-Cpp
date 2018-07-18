
#include <stdio.h>
#include <string.h>

int main()
{
	char test1[] = "feng,ke,wei";
	char *test2 = "feng,ke,wei";

	char *p = strtok(test1, ",");
	while (p)
	{
		printf("%s\n", p);
		p = strtok(NULL, ",");
	}

	// strtok()要改变传入的第一个参数，而test2是存储在常量区的，
	// 不允许被改变，所以这里会报错
	p = strtok(test2, ",");
	while (p)
	{
		printf("%s\n", p);
		p = strtok(NULL, ",");
	}

	getchar();
	return 0;
}