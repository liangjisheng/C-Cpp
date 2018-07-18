
// char *strtok(char s[], const char *delim);
// strtok是一个线程不安全的函数，因为它使用了静态分配的空间来存储被分割的字符串位置
// 分界字符串为一组字符串，s为要分界的字符串，delim为分割字符串
// 当strtok()在参数s的字符串中发现参数delim中包含的分割字符时,则会将该字符改为\0 字符。
// 在第一次调用时，strtok()必需给予参数s字符串，往后的调用则将参数s设置成NULL。
// 每次调用成功则返回指向被分割出片段的指针

// 返回值:
// 从s开头开始的一个个被分割的串。当s中的字符查找到末尾时，返回NULL。
// 如果查找不到delim中的字符时，返回当前strtok的字符串的指针。
// 所有delim中包含的字符都会被滤掉，并将被滤掉的地方设为一处分割的节点

#include <stdio.h>
#include <string.h>

void print_hex(const char *buffer, const int nLen)
{
	int i;
	for (i = 0; i < nLen; ++i)
		printf("0x%2x ", buffer[i]);
	printf("\n");
}

int main()
{
	char input[16] = "abc,d";
	print_hex(input, 16);
	char *p = NULL;

	// strtok places a NULL terminator in front of the token, if found
	p = strtok(input, ",");
	while (p)
	{
		printf("%s\n", p);
		// A second call to strtok using a NULL as the first parameter return a pointer
		// to the character following the token
		p = strtok(NULL, ",");
	}
	print_hex(input, 16);
	printf("\n\n");

	char sentence[] = "This is a sentence with 7 tokens";
	printf("The string to be tokenized is: %s\n", sentence);
	print_hex(sentence, sizeof(sentence) / sizeof(char));
	printf("\nThe tokens are:\n");

	char *tokenPtr = strtok(sentence, " ");
	while (tokenPtr)
	{
		printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
	print_hex(sentence, sizeof(sentence) / sizeof(char));
	printf("\n\n");

	// 只会截取4次，中间的多个.会被当做一个
	char ip[] = "192..168.0...8...";
	print_hex(ip, sizeof(ip) / sizeof(char));
	tokenPtr = strtok(ip, ".");
	while (tokenPtr)
	{
		printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, ".");
	}
	print_hex(ip, sizeof(ip) / sizeof(char));
	
	getchar();
	return 0;
}