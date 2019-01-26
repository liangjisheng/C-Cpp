
// 互斥量是一个内核对象，用来确保一个线程独占一个资源的访问，互斥量可以用于不行
// 进程中的线程互斥访问资源
// HANDLE CreateMutex(
// LPSECURITY_ATTRIBUTES lpMutexAttributes,
// BOOL bInitialOwner,
// LPCTSTR lpName);
// 第一个参数一般直接传NULL
// 第二个参数用来确定互斥量的初始拥有者。如果传入TRUE表示互斥量对象内部会
// 记录创建它的线程的线程ID号并将递归计数设置为1，由于该线程ID非零，所以
// 互斥量处于未触发状态。如果传入FALSE，那么互斥量对象内部的线程ID号将设置
// 为NULL，递归计数设置为0，这意味互斥量不为任何线程占用，处于触发状态
// 第三个参数用来设置互斥量的名称，在多个进程中的线程就是通过名称来确保它们
// 访问的是同一个互斥量
// 成功返回一个表示互斥量的句柄，失败返回NULL

// HANDLE OpenMutex(
//  DWORD dwDesiredAccess,
//  BOOL bInheritHandle,
//  LPCTSTR lpName);
// 第一个参数表示访问权限，对互斥量一般传入MUTEX_ALL_ACCESS
// 第二个参数表示互斥量句柄继承性，一般传入TRUE即可
// 第三个参数表示名称。某一个进程中的线程创建互斥量后，其它进程中的线程就
// 可以通过这个函数来找到这个互斥量
// 成功返回一个表示互斥量的句柄，失败返回NULL

// 访问互斥资源前应该要调用等待函数，结束访问时就要调用ReleaseMutex()来表示
// 自己已经结束访问，其它线程可以开始访问了
// BOOL ReleaseMutex (HANDLE hMutex)

// 使用CloseHandle()就可以（这一点所有内核对象都一样）

// 接下来我们就在经典多线程问题用互斥量来保证主线程与子线程之间的同步

#include <stdio.h>  
#include <process.h>  
#include <windows.h>

long g_nNum;  
unsigned int __stdcall Fun(void *pPM);  
const int THREAD_NUM = 10;

HANDLE  g_hThreadParameter;  
CRITICAL_SECTION g_csThreadCode;

// 与关键区相似，互斥量是不能解决线程间的同步问题，关键段与互斥量都会记录线程ID
// 即他们都是有线程拥有权概念的，拥有互斥量的线程可以多次调用WaitForSingleObject
// 等待一个互斥量，但其他线程调用WaitForSingleObject则会被设为等待状态

// 另外由于互斥量常用于多进程之间的线程互斥，所以它比关键段还多一个很有用的特性
// ——“遗弃”情况的处理。比如有一个占用互斥量的线程在调用ReleaseMutex()触发
// 互斥量前就意外终止了（相当于该互斥量被“遗弃”了），那么所有等待这个互斥量的
// 线程是否会由于该互斥量无法被触发而陷入一个无穷的等待过程中了？这显然不合理。
// 因为占用某个互斥量的线程既然终止了那足以证明它不再使用被该互斥量保护的资源，
// 所以这些资源完全并且应当被其它线程来使用。因此在这种“遗弃”情况下，系统自动
// 把该互斥量内部的线程ID设置为0，并将它的递归计数器复置为0，表示这个互斥量被触发了
// 然后系统将“公平地”选定一个等待线程来完成调度（被选中的线程的
// WaitForSingleObject()会返回WAIT_ABANDONED_0）


int main()
{
	// 第二个参数为TRUE表示互斥量为创建的线程所有
	g_hThreadParameter = CreateMutex(NULL, FALSE, NULL);
	InitializeCriticalSection(&g_csThreadCode);

	HANDLE hThreads[THREAD_NUM];
	g_nNum = 0;
	int i = 0;
	while(i < THREAD_NUM)
	{
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL);
		printf("%d\n", __LINE__);
		WaitForSingleObject(g_hThreadParameter, INFINITE);
		printf("%d\n", __LINE__);
		i++;
	}
	printf("%d\n", __LINE__);
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);
	printf("%d\n", __LINE__);

	CloseHandle(g_hThreadParameter);
	DeleteCriticalSection(&g_csThreadCode);

	for (i = 0; i < THREAD_NUM; ++i)
		CloseHandle(hThreads[i]);

	getchar();
	return 0;
}


unsigned int __stdcall Fun(void *pPM)
{
	int nThreadNum = *(int *)pPM;
	ReleaseMutex(g_hThreadParameter);	// 触发互斥量

	Sleep(50);		// some work should to do

	EnterCriticalSection(&g_csThreadCode);
	g_nNum++;
	Sleep(0);		// some work should to do
	printf("线程编号为%-4d全局资源值%-4d\n", nThreadNum, g_nNum);
	LeaveCriticalSection(&g_csThreadCode);

	return 0;
}


// 最后总结下互斥量Mutex：
// 1.互斥量是内核对象，它与关键段都有“线程所有权”所以不能用于线程的同步。
// 2.互斥量能够用于多个进程之间线程互斥问题，并且能完美的解决某进程意外终
//   止所造成的“遗弃”问题