
/***********************************************************
 * @name: _CRT_SECURE_NO_WARNINGS.cpp
 * @brief: _CRT_SECURE_NO_WARNINGS
 * @author: 梁基圣
 * @date: 2018/7/20 18:58:27
 * @version: 1.0
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char str[256] = { 0 };
	// 高版的VS默认不让使用scanf,fopen等函数,说是scanf,fopen等函数不安全,
	// 而代替其函数的是scanf_s,fopen_s等函数,后边有个"_s"的形式想要使用,
	// 可以在源文件开头加个: #define _CRT_SECURE_NO_WARNINGS
	// 或者右击工程 - 属性 - 配置属性 - C/C++  - 命令行
	// 命令行增加: / D_CRT_SECURE_NO_WARNINGS
	// 效果都一样,就是预编时处理一下,加个宏而已,让其忽略安全检测
	scanf("%255s", str);
	printf("Hello World\n");
	printf("%s\n", str);

	getchar();
	return 0;
}
