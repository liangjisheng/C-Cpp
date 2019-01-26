
// ����������ڵ��ļ�����������������

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

// �ں�ǰ�����##���������ڣ����ɱ�����ĸ���Ϊ0ʱ�������##�𵽰�ǰ�����
// ��","ȥ��������
#define DEBUG_INFO(format, ...) printf("File:%s, Line:%d, Function:%s, %s", \
	__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);

void show_debug_info() 
{
	// DEBUG_INFO("%d", 3); 
	DEBUG_INFO("%s", "hello world"); 
	// DEBUG_INFO("\n"); 
}

// __VA_ARGS__��һ���ɱ�����ĺ꣬������˵���ǽ���ߺ���...������ԭ����д��
// �ұߵ�__VA_ARGS__ ���ڵ�λ��
// __FILE__����Ԥ����ʱ���滻�ɵ�ǰ��Դ�ļ���
// __LINE__����Ԥ����ʱ���滻�ɵ�ǰ���к�
// __FUNCTION__����Ԥ����ʱ���滻�ɵ�ǰ�ĺ�������


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
	// ���_DEBUG�����ˣ�LOGFUNC���൱��printf(),���û�ж���LOGFUNC��
	// �൱��((void)0)
	// LOGFUNC("%s, %d\n", "this is test", 3);

	// show_debug_info();
	// printf("\n");

	PrintfDebugStringW(_T(__FILE__), __LINE__, L"%s\n", L"this is a test");

	system("pause");
	// getchar();
	return 0;
}

