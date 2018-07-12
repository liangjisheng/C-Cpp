
// 这是VC下面的函数，在Linux下是snprintf(),VC下不会自动在最后加\0
// 而Linux会自动加\0,
#include <stdio.h>

int main()
{
	char a[16] = {0};
	size_t i = 0;
	printf("sizeof(size_t) = %d\n", sizeof(size_t));
	// 返回欲写入的字符串的长度
	i = _snprintf(a, 13, "%012d", 12345);	// 第 1 种情况
	printf("i = %lu, a = %s\n", i, a);		// 输出：i = 12, a = 000000012345

	i = _snprintf(a, 5, "%012d", 12345);	// 第 2 种情况
	printf("i = %lu, a = %s\n", i, a);		// 输出：i = 12, a = 00000001

	printf("\n");
	char str[10] = {0};
	printf("sizeof(str) = %d\n", sizeof(str));
	int nLen = _snprintf(str, sizeof(str) - 1, "0123456789012345678");
	printf("str = %s\n", str);
	printf("nLen = %d\n", nLen);			// -1

	getchar();
	return 0;
}