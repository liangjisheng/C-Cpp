
// size_t strspn(const char *str, const char *accept);
// 若返回n，则代表str开头连续有n个字符都是属于字符串accept内的字符
// 如果str所包含的字符都属于accept,那么返回str的长度，如果str的第一个字符
// 不属于accept，那么返回0
// 检索字符时区分大小写

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	char str[] = "129th";
	char accept[] = "1234567890";
	i = strspn(str, accept);
	printf("%s前%d个字符都属于%s\n", str, i, accept);

	system("pause");
	return 0;
}