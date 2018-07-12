
// 注意: 编译读写锁程序需要VS2008，运行读写锁程序要在Vista或Windows Server2008系统
// (比这两个更高级的系统也可以),在XP系统下运行会报错

// 在前面的读者写着问题中使用事件和一个记录读者写者个数的变量来解决读者写者问题。
// 问题虽然得到解决，但代码有点复杂。这里介绍一种新方法--读写锁SRWLock来解决这一问题
// 读写锁在对资源进行保护的同时，还能区分想要读取资源值的线程(读取者线程)和想要更新
// 资源的线程(写入者线程)。对于读取者线程，读写锁会允许他们并发执行。当有写入者线程
// 占有资源时，读写锁会让其他写入者线程和读取者线程等待。因此用读写锁来解决读者写者
// 问题会使得代码非常清晰和简洁

// 初始化读写锁
// VOID InitializeSRWLock(PSRWLOCK SRWLock);
// 初始化（没有删除或销毁SRWLOCK的函数，系统会自动清理）

// 写入者线程申请写资源
// VOID AcquireSRWLockExclusive(PSRWLOCK SRWLock);

// 写入者线程写资源完毕，释放对资源的占用
// VOID ReleaseSRWLockExclusive(PSRWLOCK SRWLock);

// 读取者线程申请读资源
// VOID AcquireSRWLockShared(PSRWLOCK SRWLock);

// 读取者线程结束读取资源，释放对资源的占用
// VOID ReleaseSRWLockShared(PSRWLOCK SRWLock);


#include <stdio.h>
#include <Windows.h>
#include <process.h>

// 设置控制台输出颜色
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}

const int READER_NUM = 5;	// 读者个数

CRITICAL_SECTION g_cs;
SRWLOCK g_srwLock;			// 读写锁

// 读者线程输出函数(变参函数的实现)
void ReaderPrintf(char *pszFormat, ...)
{
	va_list pArglist;
	va_start(pArglist, pszFormat);
	EnterCriticalSection(&g_cs);
	vfprintf(stdout, pszFormat, pArglist);
	LeaveCriticalSection(&g_cs);
	va_end(pArglist);
}

// 读者线程函数
unsigned int _stdcall ReaderThreadFun(PVOID pM)
{
	ReaderPrintf("编号为%d的读者进入等待中......\n", GetCurrentThreadId());
	// 读者申请读文件
	AcquireSRWLockShared(&g_srwLock);

	// 读取文件
	ReaderPrintf("编号为%d的读者开始读取文件...\n", GetCurrentThreadId());
	Sleep(rand() % 100);
	ReaderPrintf("编号为%d的读者结束读取文件...\n", GetCurrentThreadId());

	// 读者结束读取文件
	ReleaseSRWLockShared(&g_srwLock);
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
	// 写者申请写文件
	AcquireSRWLockExclusive(&g_srwLock);

	// 写文件
	WriterPrintf("写者开始写文件.....");
	Sleep(rand() % 100);
	WriterPrintf("写者结束写文件");

	// 标记写者结束写文件
	ReleaseSRWLockExclusive(&g_srwLock);

	return 0;
}

int main()
{
	printf("读者写者问题 读写锁SRWLock\n");

	InitializeCriticalSection(&g_cs);
	// 读写锁声明后要初始化，但不用销毁，系统会自动清理读写锁
	InitializeSRWLock(&g_srwLock);

	HANDLE hThread[READER_NUM + 1];
	int i;
	// 先启动两个读者线程
	for (i = 1; i <= 2; ++i)
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	// 启动读者线程
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, WriterThreadFun, NULL, 0, NULL);
	Sleep(50);

	// 最后启动其他读者线程
	for (; i <= READER_NUM; ++i)
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);

	WaitForMultipleObjects(READER_NUM + 1, hThread, TRUE, INFINITE);

	for (i = 0; i < READER_NUM + 1; ++i)
		CloseHandle(hThread[i]);

	DeleteCriticalSection(&g_cs);

	getchar();
	return 0;
}
