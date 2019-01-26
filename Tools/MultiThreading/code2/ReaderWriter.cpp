
// 读者写者也是一个非常著名的同步问题。读者写者问题描述非常简单，有一个写者很多读者，
// 多个读者可以同时读文件，但写者在写文件时不允许有读者在读文件，同样有读者在读文件时
// 写者也不能写文件
// 首先来找找那些是属于"等待"(同步)情况：
// 1.写者要等到没有读者时才能去写文件
// 2.所有读者要等待写者完成写文件后才能去读文件

// 在看看有没有需要互斥访问的资源
// 由于只有一个写者而读者是可以共享的读文件，所以这里并没有需要互斥访问的资源
// 在这里对写者写文件加入颜色控制，因为写者输出是加入了颜色控制，所以这里
// 对控制台要加个互斥访问，不然很有可能在写者线程将控制台颜色还原之前读者线程就
// 已经有输出了，对输出语句做个互斥访问

#include <stdio.h>  
#include <process.h>  
#include <windows.h> 

// 设置控制台输出颜色
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == hConsole)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}

const int READER_NUM = 5;		// 读者个数

// 关键段和事件
// g_cs用来对输出语句对控制台访问的互斥
// g_cs_reader_count用来互斥对读者个数g_nReaderCount的访问
CRITICAL_SECTION g_cs, g_cs_reader_count;
HANDLE g_hEventWriter, g_hEventNoReader;
int g_nReaderCount;

// 读者线程输出函数
void ReaderPrintf(char *pszFormat, ...)
{
	va_list pArgList;
	va_start(pArgList, pszFormat);
	EnterCriticalSection(&g_cs);
	vfprintf(stdout, pszFormat, pArgList);
	LeaveCriticalSection(&g_cs);
	va_end(pArgList);
}

// 读者线程函数
unsigned int _stdcall ReaderThreadFun(PVOID pM)
{
	ReaderPrintf("编号为%d的读者进入等待中...\n", GetCurrentThreadId());
	// 等待写者完成
	WaitForSingleObject(g_hEventWriter, INFINITE);

	// 读者个数增加
	EnterCriticalSection(&g_cs_reader_count);
	g_nReaderCount++;
	if (1 == g_nReaderCount)
		ResetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_reader_count);

	// 读取文件
	ReaderPrintf("编号为%d的读者开始读取文件...\n", GetCurrentThreadId());

	Sleep(rand() % 100);

	// 结束阅读，读者个数减小，空位增加
	ReaderPrintf("编号为%d的读者结束读取文件\n", GetCurrentThreadId());

	// 读者个数减少
	EnterCriticalSection(&g_cs_reader_count);
	g_nReaderCount--;
	if (0 == g_nReaderCount)
		SetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_reader_count);

	return 0;
}

// 写者线程输出函数
void WriterPrintf(char *pszStr)
{
	EnterCriticalSection(&g_cs);
	SetConsoleColor(FOREGROUND_GREEN);
	printf("%s\n", pszStr);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	LeaveCriticalSection(&g_cs);
}

// 写者线程函数
unsigned int _stdcall WriterThreadFun(PVOID pM)
{
	WriterPrintf("写者线程进入等待中...");
	// 等待读文件的读者为0
	WaitForSingleObject(g_hEventNoReader, INFINITE);

	// 标记写者正在写文件
	ResetEvent(g_hEventWriter);

	// 写文件
	WriterPrintf("写者开始写文件......");
	Sleep(rand() % 100);
	WriterPrintf("写者结束写文件");

	// 标记写者结束写文件
	SetEvent(g_hEventWriter);

	return 0;
}


int main()
{
	printf("读者写者问题\n");

	InitializeCriticalSection(&g_cs);
	InitializeCriticalSection(&g_cs_reader_count);

	// 手动置位，初始以触发
	g_hEventWriter = CreateEvent(NULL, TRUE, TRUE, NULL);
	g_hEventNoReader = CreateEvent(NULL, FALSE, TRUE, NULL);
	g_nReaderCount = 0;

	int i;
	HANDLE hThreads[READER_NUM + 1];
	// 先启动两个读者线程
	for (i = 1; i <= 2; i++)
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	// 启动写者线程
	hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, WriterThreadFun, NULL, 0, NULL);
	Sleep(50);
	// 最后启动其它的读者线程
	for (; i <= READER_NUM; ++i)
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	Sleep(50);

	WaitForMultipleObjects(READER_NUM + 1, hThreads, TRUE, INFINITE);
	for (i = 0; i < READER_NUM + 1; ++i)
		CloseHandle(hThreads[i]);

	// 销毁事件和关键段
	CloseHandle(g_hEventWriter);
	CloseHandle(g_hEventNoReader);
	DeleteCriticalSection(&g_cs);
	DeleteCriticalSection(&g_cs_reader_count);

	getchar();
	return 0;
}