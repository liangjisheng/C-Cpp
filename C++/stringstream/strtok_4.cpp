
// 需要为strtok_r()提供一个指针来操作，而不是像strtok()使用静态指针
// char *strtok_r(char *s, const char *delim, char **ptrptr);

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

	char *outer_ptr = NULL;
	char *inner_ptr = NULL;

	// 使用strtok_s()可以正常的将字符串分割开
	while ((p[in] = strtok_s(buf, ",", &outer_ptr)) != NULL)
	{
		buf = p[in];
		while ((p[in] = strtok_s(buf, " ", &inner_ptr)) != NULL)
		{
			in++;
			buf = NULL;
		}

		p[in++] = "***";	// 表现分割
		buf = NULL;
	}

	printf("Here we have %d strings\n", in);
	int j;
	for (j = 0; j < in; ++j)
		printf(">%s<\n", p[j]);

	getchar();
	return 0;
}