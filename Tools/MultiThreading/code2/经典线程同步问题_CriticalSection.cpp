
// 使用关键段CRITICAL_SECTION来尝试解决线程同步问题
// void InitializeCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
// void DeleteCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
// void EnterCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
// void LeaveCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);

// 然后在经典多线程问题中设置二个关键区域。一个是主线程在递增子线程序号时，
// 另一个是各子线程互斥的访问输出全局资源时。详见代码：

#include <stdio.h>  
#include <process.h>  
#include <windows.h>  

long g_nNum;  
unsigned int __stdcall Fun(void *pPM);  
const int THREAD_NUM = 10;  

//关键段变量声明
CRITICAL_SECTION  g_csThreadParameter, g_csThreadCode;
// 该关键段会记录拥有该关键段的线程句柄即关键段是有"线程所有权"概念的，拥有该
// 关键段的线程可以多次进入该关键段，其它线程则会被切换到等待状态，一旦拥有线程
// 所有权的线程调用LeaveCriticalSection使其进入的次数为0时，系统会自动更新关键
// 段并将等待中的线程换回可调度状态

// 另外，由于将线程切换到等待状态的开销较大，因此为了提高关键段的性能，Microsoft
// 将旋转锁合并到关键段中，这样EnterCriticalSection()会先用一个旋转锁不断循环，
// 尝试一段时间才会将线程切换到等待状态。下面是配合了旋转锁的关键段初始化函数
//	函数功能：初始化关键段并设置旋转次数
//	函数原型：
//	BOOLInitializeCriticalSectionAndSpinCount(
//	LPCRITICAL_SECTIONlpCriticalSection,
//	DWORDdwSpinCount);
//函数说明：旋转次数一般设置为4000。

//	函数功能：修改关键段的旋转次数
//	函数原型：
//	DWORDSetCriticalSectionSpinCount(
//	LPCRITICAL_SECTIONlpCriticalSection,
//	DWORDdwSpinCount);


int main()
{
	InitializeCriticalSection(&g_csThreadParameter);
	InitializeCriticalSection(&g_csThreadCode);

	HANDLE hThreads[THREAD_NUM];
	g_nNum = 0;
	int i = 0;
	while (i < THREAD_NUM)
	{
		// 进入子线程序号关键区域
		EnterCriticalSection(&g_csThreadParameter);
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL);
		// 由于主线程拥有关键段g_csThreadParameter，所以它可以重复进入关键代码区域
		// 从而导致子线程在接收参数之前主线程就已经修改了这个参数i
		// 关键段可以用于线程之间的互斥，但不可用于同步
		++i;
	}

	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);

	DeleteCriticalSection(&g_csThreadParameter);
	DeleteCriticalSection(&g_csThreadCode);

	getchar();
	return 0;
}


unsigned int __stdcall Fun(void *pPM)
{
	int nThreadNum = *(int*)pPM;
	// 离开子线程序号关键区域
	LeaveCriticalSection(&g_csThreadParameter);

	Sleep(50);	// some work should to do

	// 进入各子线程互斥区域
	EnterCriticalSection(&g_csThreadCode);
	g_nNum++;
	Sleep(0);	// some work should to do 
	printf("线程编号%d	全局资源值%d\n", nThreadNum, g_nNum);
	LeaveCriticalSection(&g_csThreadCode);

	return 0;
}