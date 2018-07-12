
// 将事件触发后立即将事件设为未触发，相当于触发一个事件脉冲
// BOOL PulseEvent(HANDLE hEvent);
// 这是一个不常用的事件函数，此函数相当于SetEvent()后立即调用ResetEvent();
// 此时情况可以分为两种：
// 1.对于手动置位事件，所有正处于等待状态下线程都变成可调度状态。
// 2.对于自动置位事件，所有正处于等待状态下线程只有一个变成可调度状态。
// 此后事件是末触发的。该函数不稳定，因为无法预知在调用PulseEvent()时哪些线程正处于等待状态

// 下面对这个触发一个事件脉冲PulseEvent ()写一个例子，主线程启动7个子线程，
// 其中有5个线程Sleep(10)后对一事件调用等待函数（称为快线程），另有2个线程
// Sleep(100)后也对该事件调用等待函数（称为慢线程）。主线程启动所有子线程
// 后再Sleep(50)保证有5个快线程都正处于等待状态中。此时若主线程触发一个事件
// 脉冲，那么对于手动置位事件，这5个线程都将顺利执行下去。对于自动置位事件，
// 这5个线程中会有中一个顺利执行下去。而不论手动置位事件还是自动置位事件，那
// 2个慢线程由于Sleep(100)所以会错过事件脉冲，因此慢线程都会进入等待状态而
// 无法顺利执行下去

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <Windows.h>

HANDLE g_hThreadEvent;

// 快线程
unsigned int _stdcall FastThreadFun(void *pPM)
{
	Sleep(10);	// 用这个来保证各线程调用等待函数的次序有一定的随机性
	printf("%s 启动\n", (PSTR)pPM);
	WaitForSingleObject(g_hThreadEvent, INFINITE);
	printf("%s 等到事件被触发,顺利结束\n", (PSTR)pPM);
	return 0;
}

// 慢线程
unsigned int _stdcall SlowThreadFun(void *pPM)
{
	Sleep(100);
	printf("%s 启动\n", (PSTR)pPM);
	WaitForSingleObject(g_hThreadEvent, INFINITE);
	printf("%s 等到事件被触发,顺利结束\n", (PSTR)pPM);
	return 0;
}


int main()
{
	BOOL bManualReset = TRUE;
	// 创建事件 第二个参数手动置位TRUE,自动置位FALSE
	g_hThreadEvent = CreateEvent(NULL, bManualReset, FALSE, NULL);
	if(bManualReset)
		printf("当前使用手动置位事件\n");
	else
		printf("当前使用自动置位事件\n");

	char szFastThreadName[5][30] = { "FastThread1000", "FastThread1001", "FastThread1002", "FastThread1003", "FastThread1004" };
	char szSlowThreadName[2][30] = { "SlowThread196", "SlowThread197" };

	int i;
	for (i = 0; i < 5; ++i)
		_beginthreadex(NULL, 0, FastThreadFun, szFastThreadName[i], 0, NULL);
	for (i = 0; i < 2; ++i)
		_beginthreadex(NULL, 0, SlowThreadFun, szSlowThreadName[i], 0, NULL);

	Sleep(50);		// 保证快线程全部启动
	printf("现在主线程触发一个事件脉冲- PulseEvent()\n");
	PulseEvent(g_hThreadEvent);
	// 调用PulseEvent(g_hThreadEvent);相当于同时调用下面两句
	// SetEvent(g_hThreadEvent);
	// ResetEvent(g_hThreadEvent);

	Sleep(3000);
	printf("时间到，主线程结束运行\n");
	CloseHandle(g_hThreadEvent);

	getchar();
	return 0;
}

// 事件总结
// 1.事件是内核对象，事件分为手动置位事件和自动置位事件。事件Event内部它包含一个使用计数（所有内核对象都有），一个布尔值表示是手动置位事件还是自动置位事件，另一个布尔值用来表示事件有无触发。
// 2.事件可以由SetEvent()来触发，由ResetEvent()来设成未触发。还可以由PulseEvent()来发出一个事件脉冲。
// 3.事件可以解决线程间同步问题，因此也能解决互斥问题。