
/***********************************************************
 * @name: test_ctype.c
 * @brief: ctype.h
 * @author: Jisheng Liang
 * @date: 2018/6/29 15:05:41
 * @version: 1.0
 **********************************************************/

#include <stdio.h>
#include <ctype.h>

// 判断一个字符是否是字符类的数字或字母
void test_isalnum()
{
	if (isalnum('a'))
		printf("a is true\n");
	if (isalnum(4))
		printf("It's true\n");
	if (isalnum('4'))
		printf("It's true\n");
}

// isblank()测试一个字符是否是空白字符(空格和水平制表符Tab),isspace()与isblank()
// 类似，但还包括换行符\n, 换页符\f, 回车符\r, 垂直制表符\v, 水平制表符\t
void test_isblank_isspace()
{
	if (isblank(' '))
		printf("1 true\n");
	if (isblank('\t'))
		printf("2 true\n");
	if (isblank('\n'))
		printf("3 true\n");
	if (isblank('\r'))
		printf("4 true\n");

	if (isspace(' '))
		printf("5 true\n");
	if (isspace('\t'))
		printf("6 true\n");
	if (isspace('\n'))
		printf("7 true\n");
	if (isspace('\r'))
		printf("8 true\n");
}

// 判断一个字符是否是控制字符,ASCII码0-31之间的字符
void test_iscntrl()
{
	if (iscntrl(' '))
		printf("1 true\n");
	if (iscntrl('\t'))
		printf("2 true\n");
	if (iscntrl('\n'))
		printf("3 true\n");
	if (iscntrl('\r'))
		printf("4 true\n");
}

// 判断一个字符是否是字符类的数字
void test_isdigit()
{
	if (isdigit('4'))
		printf("1 true\n");
	if (isdigit(4))
		printf("2 true\n");
	if (isdigit('a'))
		printf("3 true\n");
}

// isprint()判断一个字符是否是可打印字符(ASCII码33-126之间的字符)
// isgraph()函数功能类似，但包括空格在内(ASCII码32-126之间的字符)
void test_isgraph()
{
	if (isgraph('a'))
		printf("1 true\n");
	if (isgraph('.'))
		printf("2 true\n");
	if (isgraph(' '))
		printf("3 true\n");

	if (isprint('a'))
		printf("4 true\n");
	if (isprint('.'))
		printf("5 true\n");
	if (isprint(' '))
		printf("6 true\n");
}

// 判断一个字符是否是除空格，字母，数字外的标点符号
void test_ispunct()
{
	if (ispunct('a'))
		printf("1 true\n");
	if (ispunct('.'))
		printf("2 true\n");
	if (ispunct('<'))
		printf("3 true\n");
}

// 判断一个字符是否是一个十六进制数字
void test_isxdigit()
{
	if (isxdigit('4'))
		printf("1 true\n");
	if (isxdigit('E'))
		printf("2 true\n");
	if (isxdigit('F'))
		printf("3 true\n");
}

int main(void)
{
	//test_isalnum();
	//test_isblank_isspace();
	//test_iscntrl();
	//test_isdigit();
	//test_isgraph();
	//test_ispunct();
	test_isxdigit();

	getchar();
	return 0;
}
