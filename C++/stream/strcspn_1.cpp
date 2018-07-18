
// int strcspn(char *str, char *accept);
// 若返回值为n，则代表字符串str开头连续有n个字符都不包含在accept内
// 如果str中的字符都没有在accept找那个出现，那么将返回str的长度
// 检索字符时区分大小写

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 判读两个字符串是否有重复的
void test()
{
	char *s1 = "http://c.biancheng.net/cpp/xitong/";
	char *s2 = "z -+*";
	if (strlen(s1) == strcspn(s1, s2))
		printf("s1 is different from s2\n");
	else
		printf("There is at least one same character in s1 and s2\n");
}

int main()
{
	char *s1 = "http://c.biancheng.net/cpp/u/biaozhunku/";
	char *s2 = "c is good";
	int n = strcspn(s1, s2);
	printf("The first char both in s1 and s2 is: %c\n", s1[n]);
	printf("The position in s1 is: %d\n", n);

	test();

	system("pause");
	return 0;
}