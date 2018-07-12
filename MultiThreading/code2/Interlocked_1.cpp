
// 下面我们增加点用户来试试，现在模拟50个用户登录，为了便于观察结果，
// 在程序中将50个用户登录过程重复20次，代码如下

#include <stdio.h>
#include <Windows.h>

volatile long g_nLoginCount;			// 登录次数
unsigned int _stdcall Func(void *pPM);	// 线程函数
const DWORD THREAD_NUM = 50;			// 写成100后，是另外的一种结果，什么情况？

DWORD WINAPI ThreadFun(void *pPM)
{
	Sleep(100);
	// 执行++运算时有三条语句
	// 1.将g_nLoginCount的值从内存中读取到寄存器中eax中
	// 2.将寄存器eax中的值加1,计算结果任然存入寄存器eax中
	// 3.将寄存器eax中的值写会内存
	// 由于线程执行的并发性,很可能线程A执行到第二句是,线程B开始执行,线程B将
	// 原来的值又写入寄存器eax中,这样线程A所主要计算的值就被线程B修改了,这样
	// 执行下来的结果是不可预知的,可能小于50,也可能大于50

	// 此在多线程环境中对一个变量进行读写时，我们需要有一种方法能够保证对一个
	// 值的递增操作是原子操作——即不可打断性，一个线程在执行原子操作时，
	// 其它线程必须等待它完成之后才能开始执行该原子操作。这种涉及到硬件的
	// 操作会不会很复杂了，幸运的是，Windows系统为我们提供了一些以Interlocked
	// 开头的函数来完成这一任务(下文将这些函数称为Interlocked系列函数)
	// 下面列出一些常用的Interlocked系列函数：
	// 增减操作
	// 返回变量执行增减操作之后的值
	// LONG _cdecl InterlockedIncrement(LONG volatile* Addend);
	// LONG	_cdecl InterlockedDecrement(LONG volatile* Addend);

	// 返回运算后的值,注意: 加个负数就是减
	// LONG _cdecl InterlockedExchangeAdd(LONG volatile* Addend, LONG Value);
	
	// 赋值操作:
	// LONG _cdecl InterlockedExchange(LONG volatile* Target, LONG Value);

	// 下面这句话保证对一个值的递增操作是原子操作--即不可打断性
	// 现在就算是写成这样,还是会有问题,而且输出的结果和启动的线程数还有关系？
	InterlockedIncrement((LPLONG)&g_nLoginCount);
	// g_nLoginCount++;
	Sleep(50);
	return 0;
}


int main()
{
	// 重复20次观察多线程访问同一资源时导致的冲突
	int num = 20;
	while(num--)
	{
		g_nLoginCount = 0;
		HANDLE hThreads[THREAD_NUM];
		for (int i = 0; i < THREAD_NUM; ++i)
			hThreads[i] = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
		WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);
		printf("有%d个用户登录后记录结果是%d\n", THREAD_NUM, g_nLoginCount);
	}

	getchar();
	return 0;
}