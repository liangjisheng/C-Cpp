
// 程序描述：
// 主线程启动10个子线程并将表示子线程序号的变量地址作为参数传递给子线程
// 子线程接收参数 -> Sleep(50) -> 全局变量++ ->Sleep(0) -> 输出参数和全局变量
// 要求:
// 1.子线程输出的线程序号不能重复
// 2.全局变量的输出必须递增

// 这问题的主要考察点有2个:
// 1.主线程创建子线程并传入一个指向变量地址的指针作参数，由于线程启动须要
//   花费一定的时间，所以在子线程根据这个指针访问并保存数据前，主线程应等
//   待子线程保存完毕后才能改动该参数并启动下一个线程。这涉及到主线程与子
//   线程之间的同步
// 2.子线程之间会互斥的改动和输出全局变量。要求全局变量的输出必须递增。这
//   涉及到各子线程间的互斥


#include <stdio.h>
#include <process.h>
#include <Windows.h>

long g_nNum;							// 全局资源
unsigned int _stdcall Fun(void* pPM);	// 线程函数
const int THREAD_NUM = 10;				// 子线程个数

int main()
{
	g_nNum = 0;
	HANDLE hThreads[THREAD_NUM];

	int i = 0;
	while(i < THREAD_NUM)
	{
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL);
		// 线程启动需要时间,等子线程接收到参数时,主线程可能改变了这个i的值
		i++;
	}

	// 等待所有子线程全部运行结束
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);

	getchar();
	return 0;
}


unsigned int _stdcall Fun(void* pPM)
{
	// 由于创建线程是要一定开销的，所以新线程并不能第一时间执行到这里来
	int nThreadnNum = *(int*)pPM;
	Sleep(50);
	g_nNum++;
	Sleep(0);
	printf("线程编号为%d 全局资源值为%d\n", nThreadnNum, g_nNum);
	return 0;
}
