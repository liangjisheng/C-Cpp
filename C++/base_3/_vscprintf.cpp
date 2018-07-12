
// _vscprintf(ANSI) 、 _vscwprintf(WCHAR)获取格式化输出字符串长度
// (注意此长度不包含结束符号)

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>		// for memset

void test(char *format, ...)
{
	va_list args;
	int len = 0;
	char *buffer = NULL;

	va_start(args, format);
	// _vscprintf doesn't count terminating '\0'
	len = _vscprintf(format, args) + 1;
	buffer = (char*)malloc(len * sizeof(char));
	memset(buffer, 0, len);
	vsprintf(buffer, format, args);
	puts(buffer);

	free(buffer);
}


int main()
{
	test("%d %c %d", 123, '<', 456);
	test("%s", "This is a string");

	system("pause");
	return 0;
}

