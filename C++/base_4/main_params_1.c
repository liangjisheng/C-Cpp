
/***********************************************************
 * @name: main_params_1.c
 * @brief: 主函数参数
 * @author: Jisheng Liang
 * @date: 2018/6/7 16:37:40
 * @version: 1.0
 **********************************************************/

#include"stdio.h"
#include"stdlib.h"					// for atoi()


// argc记录命令行参数的个数，包括文件名，argv[]为指针数组，指向命令行参数
// 在命令行输入参数的时候，不管输入的是什么，都以字符串的形式存储到内存中
// 所以有时需要进行类型转换
int main(int argc, char *argv[])
{
	int sum = 0, i = 0, temp = 0;
	printf("共有%d个命令行参数\n", argc);
	printf("%d:%s\n", 0, argv[0]);

	for (i = 1; i < argc; i++) 
	{
		temp = atoi(argv[i]);			//atoi()函数将字符串类型转换成整型
		sum += temp;
	}
	printf("sum=%d\n", sum);

	return 1000;
}
