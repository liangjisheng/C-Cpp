
// 求任意两个集合的笛卡尔积
#include <stdio.h>

#define m 3
#define n 2

int main()
{
	int i, j;
	char a[m], b[n];

	printf("input set of a ,b: \n");
	for (i = 0; i < m; ++i) scanf("%c", &a[i]);
	getchar();	// 吃掉\n
	for (j = 0; j < n; ++j) scanf("%c", &b[j]);

	printf("集合a: \n");
	for (i = 0; i < m; ++i) printf("%c\t", a[i]);
	printf("\n集合b: \n");
	for (j = 0; j < n; ++j) printf("%c\t", b[j]);
	printf("\n");

	printf("集合a和集合b的笛卡尔积:\n");
	printf("\n{");
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			printf("<%c, %c>", a[i], b[j]);
	printf("}\n");

	getchar();
	getchar();
	return 0;
}