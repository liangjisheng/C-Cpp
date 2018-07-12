
// 生成程序崩溃的dump文件,使用windbg调试
// 有时候程序在客户那里崩溃了，你程序也没有什么有效的log日志能记录到崩溃的细节，
// 那这实在是一件很麻烦的事情。
// 你得向客户反复了解操作内容并希望能在自己这里重现，这个过程想想都很痛苦吧。。
// 使用下面的方法，能在程序崩溃时生成一个自己的dump文件，记录了崩溃时的一些有用
// 的信息，一般能帮你容易地找到出错的地方
// windows下程序崩溃时会弹出一个对话框，但里面并没有显示有用的信息
// 有一个方法可以让我们设置程序崩溃时先执行的回调函数，这里面可以弹我们自己的对话框
// 比如让用户输入一些有用的内容然后发送给我们。

// 这个函数是SetUnhandledExceptionFilter
// WINAPI SetUnhandledExceptionFilter(
	// __in_opt LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
// 参数是要设置的回调函数PTOP_LEVEL_EXCEPTION_FILTER
// typedef LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(
	// __in struct _EXCEPTION_POINTERS *ExceptionInfo);
// typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;
// 系统调起你的回调函数时，会给你传一个代表异常信息的结构：EXCEPTION_POINTERS
// typedef struct _EXCEPTION_POINTERS {  
	// PEXCEPTION_RECORD ExceptionRecord;  
	// PCONTEXT ContextRecord;  
// } EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
// 我们现在要做的就是在回调函数里根据这个系统给我们的信息，记录到一个dump文件中去
// 供我们使用windbg分析。
//通过SetUnhandledExceptionFilter 函数的返回值我们可以选择在回调结束后不再弹
// 原来默认的对话框而直接结束程序、或者再弹那个默认的再结束程序、不弹对话框继续执行

#define EXCEPTION_EXECUTE_HANDLER       1       //在回调结束后不再弹原来默认的对话框而直接结束程序  
#define EXCEPTION_CONTINUE_SEARCH       0       //再弹那个默认的再结束程序  
#define EXCEPTION_CONTINUE_EXECUTION    -1      //继续执行

// 在回调函数中输出崩溃信息到dump文件
// 往dump文件写内容用到一个API：MiniDumpWriteDump
// 在DbgHelp.h头文件中，且需包含 DbgHelp.lib库

//BOOL WINAPI MiniDumpWriteDump(  
//	__in HANDLE hProcess,		// 进程句柄,使用GetCurrentProcess()获得
//	__in DWORD ProcessId,		// 进程ID，GetCurrentProcessId()
//	__in HANDLE hFile,			// 创建的dump文件句柄
//	__in MINIDUMP_TYPE DumpType,	// dump类型，一般填MiniDumpNormal
//
//	// 1.ThreadId: GetCurrentThreadId()
//	// 2.ExceptionPointers:回调函数的参数
//	// 3.ClientPointer: 一般填TRUE
//	__in_opt PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
//	__in_opt PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,		// 一般为NULL
//	__in_opt PMINIDUMP_CALLBACK_INFORMATION CallbackParam			// 一般为NULL
//	);  

#include <Windows.h>
#include <DbgHelp.h>
#include <tchar.h>
#include <iostream>
#pragma comment(lib, "dbghelp.lib")

// 我们的回调函数
LONG _stdcall ExceptCallBack(EXCEPTION_POINTERS *pExcPointer)
{
	MessageBox(NULL, _T("程序崩溃！相关信息记录在D:\\Test.dmp文件中"), _T("title"), MB_OK);

	HANDLE hFile = CreateFile(_T("D:\\Test.dmp"), GENERIC_WRITE, 0, NULL, 
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// 向文件写入当前程序崩溃的相关信息
	MINIDUMP_EXCEPTION_INFORMATION loExceptionInfo;
	loExceptionInfo.ExceptionPointers = pExcPointer;
	loExceptionInfo.ThreadId = GetCurrentThreadId();
	loExceptionInfo.ClientPointers = TRUE;
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile,
		MiniDumpNormal, &loExceptionInfo, NULL, NULL);
	CloseHandle(hFile);

	return EXCEPTION_EXECUTE_HANDLER;
}

void WrongFun()
{
	int *p = NULL;
	*p = 1;		// crash
}

int main()
{
	// 设置崩溃回调函数
	SetUnhandledExceptionFilter(ExceptCallBack);
	WrongFun();

	//system("pause");
	return 0;
}