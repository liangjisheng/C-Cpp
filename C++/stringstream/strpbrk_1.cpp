
// 在源字符串s1中找出最先含有搜索字符串s2中任一字符的位置并返回，若找不到则返回空指针
// char *strpbrk(const char *s1, const char *s2);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *s1 = "Welcome To Beijing";
	char *s2 = "lco";
	char *p = NULL;
	system("cls");

	p = strpbrk(s1, s2);
	if (p)
		printf("%s\n", p);
	else
		printf("not found\n");

	p = strpbrk(s1, "Da");
	if (p)
		printf("%s\n", p);
	else
		printf("not found\n");

	system("pause");
	return 0;
}