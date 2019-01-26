
// 对这个简单生产者消费者问题加大难度。将消费者改成2个，缓冲池改成拥有4个缓冲区的大缓冲池。
// 如何来思考了这个问题了？首先根据上面分析的二点，可以知道生产者和消费者由一个变成多个的影响不大，
// 唯一要注意的是缓冲池变大了，回顾一下《秒杀多线程第八篇 经典线程同步 信号量Semaphore》中的信号量，
// 不难得出用二个信号量就可以解决这种缓冲池有多个缓冲区的情况——用一个信号量A来记录为空的缓冲区个数，
// 另一个信号量B记录非空的缓冲区个数，然后生产者等待信号量A，消费者等待信号量B就可以了

// 1生产者 2消费者 4缓冲区
#include <stdio.h>
#include <process.h>
#include <Windows.h>

//设置控制台输出颜色  
BOOL SetConsoleColor(WORD wAttributes)  
{  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	if (hConsole == INVALID_HANDLE_VALUE)  
		return FALSE;  

	return SetConsoleTextAttribute(hConsole, wAttributes);  
}  

const int END_PRODUCT_NUMBER = 8;		// 生产产品个数
const int BUFFER_SIZE = 4;				// 缓冲区个数
int g_buffer[BUFFER_SIZE];				// 缓冲池
int g_i, g_j;

CRITICAL_SECTION g_cs;
HANDLE g_hSemaphoreBufferEmpty, g_hSemaphoreBufferFull;


// 生产者线程函数
unsigned int _stdcall ProducerThreadFun(PVOID pM)
{
	for (int i = 1; i <= END_PRODUCT_NUMBER; ++i)
	{
		// 等待有空缓冲区的出现
		WaitForSingleObject(g_hSemaphoreBufferEmpty, INFINITE);

		// 互斥访问缓冲区
		EnterCriticalSection(&g_cs);
		g_buffer[g_i] = i;
		printf("生产者在缓冲池第%d个缓冲区中投放数据%d\n", g_i, g_buffer[g_i]);
		g_i = (g_i + 1) % BUFFER_SIZE;
		LeaveCriticalSection(&g_cs);

		// 通知消费者有新数据了
		ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);
	}

	printf("生产者任务完成，线程结束运行\n");
	return 0;
}

// 消费者线程函数
unsigned int _stdcall ConsumerThreadFun(PVOID pM)
{
	while (true)
	{
		// 等待非空缓冲区的出现
		WaitForSingleObject(g_hSemaphoreBufferFull, INFINITE);

		// 互斥的访问缓冲区
		EnterCriticalSection(&g_cs);
		SetConsoleColor(FOREGROUND_GREEN);
		printf("编号为%d的消费者从缓冲池中第%d个缓冲区取出数据%d\n", 
			GetCurrentThreadId(), g_j, g_buffer[g_j]);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		if (g_buffer[g_j] == END_PRODUCT_NUMBER)	// 结束标志
		{
			LeaveCriticalSection(&g_cs);
			// 通知其他消费者有新数据了(结束标志)
			ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);
			break;
		}

		g_j = (g_j + 1) % BUFFER_SIZE;
		LeaveCriticalSection(&g_cs);

		Sleep(50);		// some other work to do
		ReleaseSemaphore(g_hSemaphoreBufferEmpty, 1, NULL);
	}

	SetConsoleColor(FOREGROUND_GREEN);
	printf("编号为%d的消费者受到通知，线程结束运行\n", GetCurrentThreadId());
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	return 0;
}


int main()
{
	printf("生产者消费者问题 1生产者 2消费者 4缓冲区\n");

	InitializeCriticalSection(&g_cs);
	// 初始化信号量，一个记录有产品的缓冲区个数，另一个记录空缓冲区的个数
	g_hSemaphoreBufferEmpty = CreateSemaphore(NULL, 4, 4, NULL);
	g_hSemaphoreBufferFull = CreateSemaphore(NULL, 0, 4, NULL);
	g_i = 0;
	g_j = 0;
	memset(g_buffer, 0, sizeof(g_buffer));

	const int THREADNUM = 3;
	HANDLE hThreads[THREADNUM];

	// 生产者线程
	hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, ProducerThreadFun, NULL, 0, NULL);
	// 消费者线程
	hThreads[1] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	hThreads[2] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);

	WaitForMultipleObjects(THREADNUM, hThreads, TRUE, INFINITE);
	for (int i = 0; i < THREADNUM; ++i)
		CloseHandle(hThreads[i]);
	
	CloseHandle(g_hSemaphoreBufferEmpty);
	CloseHandle(g_hSemaphoreBufferFull);
	DeleteCriticalSection(&g_cs);

	system("pause");
	return 0;
}