
/***********************************************************
 * @name: main_params_2.c
 * @brief: 主函数参数
 * @author: Jisheng Liang
 * @date: 2018/6/7 16:40:34
 * @version: 1.0
 **********************************************************/

#include <stdio.h> 
#include <stdlib.h> 

void main(int argc, char *argv[], char *env[])
{
	int i;
	printf("These are the %d command-line arguments passed to main:\n\n", argc);
	for (i = 0; i < argc; ++i)
		printf("argv[%d]:%s\n", i, argv[i]);
	printf("\nThe environment string(s)on this system are: \\n\n");
	for (i = 0; env[i] != NULL; ++i)
		printf(" env[%d]:%s\n", i, env[i]);
}
