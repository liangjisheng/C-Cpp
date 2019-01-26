
// 生产者消费者问题是一个著名的线程同步问题，该问题描述如下：有一个生产者在生产产品，
// 这些产品将提供给若干个消费者去消费，为了使生产者和消费者能并发执行，在两者之间设
// 置一个具有多个缓冲区的缓冲池，生产者将它生产的产品放入一个缓冲区中，消费者可以从
// 缓冲区中取走产品进行消费，显然生产者和消费者之间必须保持同步，即不允许消费者到一
// 个空的缓冲区中取产品，也不允许生产者向一个已经放入产品的缓冲区中再次投放产品。

// 首先来简化问题，先假设生产者和消费者都只有一个，且缓冲区也只有一个。这样情况就简便多了。
// 第一．从缓冲区取出产品和向缓冲区投放产品必须是互斥进行的。可以用关键段和互斥量来完成。
// 第二．生产者要等待缓冲区为空，这样才可以投放产品，消费者要等待缓冲区不为空，这样才可以
// 取出产品进行消费。并且由于有二个等待过程，所以要用二个事件或信号量来控制。
// 考虑这二点后，代码很容易写出来。另外为了美观起见，将消费者的输出颜色设置为彩色

// 1生产者 1消费者 1缓冲区
// 使用两个事件，一个表示缓冲区空，另一个表示缓冲区满
// 在使用一个关键段来控制缓冲区的访问

#include <stdio.h>
#include <Windows.h>
#include <process.h>

//设置控制台输出颜色  
BOOL SetConsoleColor(WORD wAttributes)  
{  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	if (hConsole == INVALID_HANDLE_VALUE)  
		return FALSE;     
	return SetConsoleTextAttribute(hConsole, wAttributes);  
}

const int END_PRODUCT_NUMBER = 10;		// 生产产品个数
int g_buffer;							// 缓冲区

CRITICAL_SECTION g_cs;
HANDLE g_hEventBufferEmpty, g_hEventBufferFull;


// 生产者线程函数
unsigned int _stdcall ProducerThreadFun(PVOID pM)
{
	for (int i = 1; i <= END_PRODUCT_NUMBER; ++i)
	{
		// 等待缓冲区为空
		WaitForSingleObject(g_hEventBufferEmpty, INFINITE);

		// 互斥访问缓冲区
		EnterCriticalSection(&g_cs);
		g_buffer = i;
		printf("生产者将数据%d放入缓冲区\n", i);
		LeaveCriticalSection(&g_cs);

		// 通知缓冲区有新数据了
		SetEvent(g_hEventBufferFull);
	}

	return 0;
}

// 消费者线程函数
unsigned int _stdcall ConsumerThreadFun(PVOID pM)
{
	volatile bool flag = true;
	while(flag)
	{
		// 等待缓冲区中有数据
		WaitForSingleObject(g_hEventBufferFull, INFINITE);

		// 互斥的访问缓冲区
		EnterCriticalSection(&g_cs);
		SetConsoleColor(FOREGROUND_GREEN);
		printf("消费者从缓冲区中取数据%d\n", g_buffer);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		if(g_buffer == END_PRODUCT_NUMBER)
			flag = false;
		LeaveCriticalSection(&g_cs);

		// 通知缓冲区已为空
		SetEvent(g_hEventBufferEmpty);

		Sleep(10);	// some other work should to do 
	}

	return 0;
}


int main()
{
	printf("生产者消费者问题 1生产者 1消费者 1缓冲区\n");

	InitializeCriticalSection(&g_cs);
	// 创建两个自动复位事件，一个表示缓冲区是否为空，另一个表示缓冲区是否已经处理
	g_hEventBufferEmpty = CreateEvent(NULL, FALSE, TRUE, NULL);
	g_hEventBufferFull = CreateEvent(NULL, FALSE, FALSE, NULL);

	const int THREADNUM = 2;
	HANDLE hThreads[THREADNUM];

	hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, ProducerThreadFun, NULL, 0, NULL);
	hThreads[1] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);

	WaitForMultipleObjects(THREADNUM, hThreads, TRUE, INFINITE);

	CloseHandle(hThreads[0]);
	CloseHandle(hThreads[1]);

	CloseHandle(g_hEventBufferEmpty);
	CloseHandle(g_hEventBufferFull);
	DeleteCriticalSection(&g_cs);

	getchar();
	return 0;
}