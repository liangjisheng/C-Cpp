// if_else_statement.cpp
#include <stdio.h>

int main() 
{
	int x = 0;
	if (x == 0)
	{
		printf_s("x is 0!\n");
		printf_s("lishuyu\n");
	}
	else
	{
		printf_s("x is not 0!\n"); // this statement will not be executed
	}

	x = 1;
	if (x == 0)
	{
		printf_s("x is 0!\n"); // this statement will not be executed
	}
	else
	{
		printf_s("x is not 0!\n");
	}

	getchar();
	return 0;
}