
// 多线程访问全局变量导致崩溃问题
#include <Windows.h>
#include <vector>

using std::vector;

#define INTPTR int*
typedef std::vector<INTPTR> VecINTPTR;
typedef VecINTPTR::iterator VecINTPTRIter;
typedef VecINTPTR::const_iterator VecINTPTRCIter;

VecINTPTR g_VecInt;

static DWORD WINAPI ReadRoutine(LPVOID)
{
	// 读取线程
	for (VecINTPTRIter it = g_VecInt.begin(); it != g_VecInt.end(); it++)
	{
		// 故意将读取时间设置长，这样更大概率导致崩溃
		Sleep(10);
		printf("%d\n", **it);
	}
	return 0;
}

static DWORD WINAPI WriteRoutine(LPVOID)
{
	// 写入线程
	for (VecINTPTRIter it = g_VecInt.begin(); it != g_VecInt.end(); )
	{
		// 故意将修改时间设置短，这样更大概率导致奔溃
		delete *it;
		*it = NULL;
	}

	return 0;
}

int main()
{
	for (int n = 0; n < 128; n++)
	{
		int *p = new int();
		*p = n;
		g_VecInt.push_back(p);
	}
	system("pause");

	HANDLE hRead = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadRoutine, NULL, 0, NULL);
	HANDLE hWrite = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WriteRoutine, NULL, 0, NULL);
	HANDLE hArray[] = { hRead, hWrite };
	WaitForMultipleObjects(ARRAYSIZE(hArray), hArray, TRUE, INFINITE);
	printf("Success");

	return 0;
}