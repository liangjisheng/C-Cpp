
// 输出代码所在的文件、行数及函数名称

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <Windows.h>
#include <tchar.h>

#ifndef _DEBUG
#define LOGFUNC(...) ((void)0)
#else
#define LOGFUNC(...) (printf(__VA_ARGS__))
#endif

// 在宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余
// 的","去掉的作用
#define DEBUG_INFO(format, ...) printf("File:%s, Line:%d, Function:%s, %s", \
	__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);

void show_debug_info() 
{
	// DEBUG_INFO("%d", 3); 
	DEBUG_INFO("%s", "hello world"); 
	// DEBUG_INFO("\n"); 
}

// __VA_ARGS__是一个可变参数的宏，总体来说就是将左边宏中...的内容原样抄写在
// 右边的__VA_ARGS__ 所在的位置
// __FILE__宏在预编译时会替换成当前的源文件名
// __LINE__宏在预编译时会替换成当前的行号
// __FUNCTION__宏在预编译时会替换成当前的函数名称


#ifdef _DEBUG
#define OUTPUT_DEBUGW(fmt, ...) PrintDebugStringW(_T(__FILE__), __LINE__, fmt, __VA_ARGS__)
#else
#define OUTPUT_DEBUGW ((void)0)
#endif

void PrintfDebugStringW(const wchar_t *file, int lineno, const wchar_t *pszFmt, ...)
{
	va_list arg_list = NULL;
	va_start(arg_list, pszFmt);
	size_t nLen = _vscwprintf(pszFmt, arg_list) + 1;
	wchar_t *strBuffer = new wchar_t[nLen];
	_vsnwprintf_s(strBuffer, nLen, nLen, pszFmt, arg_list);
	va_end(arg_list);

	wchar_t buf[4096] = {0};
	swprintf_s(buf, 4096, L"\n%s<%d>: tid[%d]:%s\n", 
		file, lineno, GetCurrentThreadId(), strBuffer);
	OutputDebugStringW(buf);
	delete [] strBuffer;
}


int main()
{
	// 如果_DEBUG定义了，LOGFUNC就相当于printf(),如果没有定义LOGFUNC就
	// 相当于((void)0)
	// LOGFUNC("%s, %d\n", "this is test", 3);

	// show_debug_info();
	// printf("\n");

	PrintfDebugStringW(_T(__FILE__), __LINE__, L"%s\n", L"this is a test");

	system("pause");
	// getchar();
	return 0;
}

