
// C标准定义了5个预处理符号
// __FILE__
// __LINE__
// __DATE__
// __TIME__
// __STDC__	// 如果编译器遵循ANSI C,值为1，否则未定义

#include <stdio.h>
#include <stdlib.h>

#define LOG fprintf(pf, " %s\n %d\n %s\n %s\n\n",\
	__FILE__, __LINE__, __DATE__, __TIME__)//, __STDC__)

// #a -> "a"
#define PRINT(x, Format) printf("the value of "#x" is "#Format"\n", x)

int main()
{
	int i = 0;
	FILE *pf = fopen("log.txt", "w");
	if (NULL == pf)
	{
		printf("open failure\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 5; ++i)
		LOG;

	fclose(pf);

	PRINT(i, %d);
	PRINT(i, "%d");

	getchar();
	return 0;
}
