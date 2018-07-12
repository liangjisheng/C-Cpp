
// 这个案例是一个线程向队列中的队列头部读取数据，一个线程向队列中的队列尾部写入数据。
// 看起来很像读者写者问题,但如果将队列看成缓冲区，这个案例明显是个生产者，消费者问题
// 1.当队列为空时，读取数据线程必须等待写入数据线程向队列中写入数据，也就是说，当队列
// 为空时，读取数据线程要等待队列中有数据
// 2.当队列满时，写入数据线程必须等待读取数据线程向队列中读取数据，也就是说当队列满时
// 写入数据线程要等待队列中有空位
// 在访问队列时，两个线程是否需要互斥访问，将依赖于队列的数据结构实现，如果使用STL中
// 的vector，由于vector会动态增长，因此需要做互斥保护。如果使用循环队列，那么读取数据
// 线程拥有读取指针，写入数据线程拥有写入指针，各自将访问队列中不同位置上的数据，因此
// 不用进行互斥防护。
// 使用两个信号量，一个来记录循环队列中空位的个数，一个来记录循环队列中产品的个数(非空位个数)
// http://blog.csdn.net/morewindows/article/details/8646902

#include <stdio.h>
#include <process.h>
#include <Windows.h>
#include <time.h>

const int QUEUE_LEN = 5;
int g_arrDataQueue[QUEUE_LEN];
int g_i, g_j, g_nDataNum;

// 关键段，用于保证互斥的在屏幕上输出
CRITICAL_SECTION g_cs;
// 信号量，g_hEmpty表示队列中空位，g_hFull表示队列中非空位
HANDLE g_hEmpty, g_hFull;

// 设置控制台颜色
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;
	return SetConsoleTextAttribute(hConsole, wAttributes);
}

// 读数据线程函数
unsigned int _stdcall ReaderThreadFun(PVOID pM)
{
	int nData = 0;
	while (nData < 20)
	{
		WaitForSingleObject(g_hFull, INFINITE);
		nData = g_arrDataQueue[g_i];
		g_i = (g_i + 1) % QUEUE_LEN;
		EnterCriticalSection(&g_cs);
		printf("从队列中读数据: %d\n", nData);
		LeaveCriticalSection(&g_cs);
		Sleep(rand() % 300);
		ReleaseSemaphore(g_hEmpty, 1, NULL);
	}
	return 0;
}

// 写入数据线程函数
unsigned int _stdcall WriteThreadFun(PVOID pM)
{
	int nData = 0;
	while (nData < 20)
	{
		WaitForSingleObject(g_hEmpty, INFINITE);
		g_arrDataQueue[g_j] = ++nData;
		g_j = (g_j + 1) % QUEUE_LEN;
		EnterCriticalSection(&g_cs);
		SetConsoleColor(FOREGROUND_GREEN);
		printf("	将数据%d写入队列\n", nData);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		LeaveCriticalSection(&g_cs);
		Sleep(rand() % 300);
		ReleaseSemaphore(g_hFull, 1, NULL);
	}
	return 0;
}

int main()
{
	InitializeCriticalSection(&g_cs);
	g_hEmpty = CreateSemaphore(NULL, QUEUE_LEN, QUEUE_LEN, NULL);
	g_hFull = CreateSemaphore(NULL, 0, QUEUE_LEN, NULL);

	srand(time(NULL));
	g_i = g_j = 0;
	HANDLE hThreads[2];
	hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	hThreads[1] = (HANDLE)_beginthreadex(NULL, 0, WriteThreadFun, NULL, 0, NULL);

	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);

	for (int i = 0; i < 2; ++i)
		CloseHandle(hThreads[i]);
	CloseHandle((g_hEmpty));
	CloseHandle(g_hFull);
	DeleteCriticalSection(&g_cs);

	getchar();
	return 0;
}
