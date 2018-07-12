
// http://www.cnblogs.com/hoys/archive/2011/09/19/2180999.html

#include <stdio.h>
#include <string.h>

#define INFO_MAX_SZ 255

int main()
{
	int in = 0;
	// 将这个字符串先用,分隔，在用空格分隔，将对应的指针存储到p中，输出
	char buffer[INFO_MAX_SZ] = "Fred male 25,John male 62,Anna female 16";
	char *p[20] = { NULL };
	char *buf = buffer;

	while ((p[in] = strtok(buf, ",")) != NULL)
	{
		buf = p[in];
		while ((p[in] = strtok(buf, " ")) != NULL)
		{
			in++;
			buf = NULL;
		}

		p[in++] = "***";	// 表现分割
		buf = NULL;
	}

	// 因为strtok()使用了一个静态指针来操作数据，内层循环和外层循环共用这一个指针
	// 就会导致外层循环只循环一次，因为内层循环将指针所指的值设置为\0
	// 这种情况下应该使用strtok_r()来解决仅用一个静态指针的问题
	printf("Here we have %d strings\n", in);
	int j;
	for (j = 0; j < in; ++j)
		printf(">%s<\n", p[j]);

	getchar();
	return 0;
}