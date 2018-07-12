
// 在C语言中，字符能像整数一样计算，而不需要特别的转换
// 可以给一个字符加上一个整数，表示其后面的第n个字符
// 也可以两个字符相减，表示两个字符之间的距离

#include <stdio.h>

// 判断ch是否是数字
bool my_isDigit(char ch)
{
	if(ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}

// 转换成小写字符
char my_tolower(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
		return ch + ('a' - 'A');
	else
		return ch;
}

// 缓冲分为两类:完全缓冲I/O和行缓冲I/O,完全缓冲输入指的是当缓冲区
// 被填满时才刷新缓冲区，内容被发送到目的地，通常出现在文件输入中
// 缓冲区的大小取决于系统，常见的大小为512和4096字节
// 行缓冲区I/O指的是在出现换行符时刷新缓冲区，键盘输入通常是行缓冲
// 区输入，所以在按下Enter键后刷新缓冲区

void input_copy_output()
{
	int ch;
	printf("input a character: ");
	while((ch = getchar()) != EOF)
	{
		putchar(ch);
		getchar();		// 处理换行符
		printf("\ninput a character: ");
	}
}

// 将0-15转换为等价的16进制字符
char digit_to_hexchar(int digit)
{
	return "0123456789ABCDEF"[digit];
}


int main()
{
	// input_copy_output();
	printf("%d\n", sizeof(char));	// 1
	printf("%d\n", sizeof('a'));	// 1

	// cStr是常量，pStr是变量
	char cStr[4] = "ok!";			// 编译时分配内存
	char *pStr = "ok!";				// 编译时完全没有分配内存，仅在运行时分配空间
	// cStr = "tet";	// 不能修改常量指针

	// 字符串的本质就是数组
	printf("%d\n", sizeof("test!"));	// 6
	printf("test占用的空间%d\n", sizeof("test"));
	printf("test的地址0x%x\n", "test");
	printf("%c\n", *("test"));
	printf("%c\n", *("test" + 1));
	printf("%c\n", "test"[2]);
	printf("%c\n", "test"[3]);

	printf("%d\n", *("test"));
	printf("%d\n", *("test" + 1));
	printf("%d\n", "test"[2]);
	printf("%d\n", "test"[3]);

	printf("\n");
	for(int i = 0; i < 16; i++)
		printf("%c ", digit_to_hexchar(i));
	printf("\n");

	getchar();
	return 0;
}

