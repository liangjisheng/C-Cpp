
/***********************************************************
 * @name: StaticThreadFunc.cpp
 * @brief: 静态函数作为回调函数
 * @author: 梁基圣
 * @date: 2018/7/22 11:04:18
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <windows.h>

using namespace std;

class myThread 
{
public:
	myThread(int n, int m) : Num(n), Test(m), hThread(NULL) {}
	int Test;
	int Num;
	HANDLE hThread;
	const static int tmp = 10;

	int ThreadNew();
	static DWORD WINAPI TestFun(LPVOID lpParam);
};

DWORD WINAPI myThread::TestFun(LPVOID lpParam)
{
	myThread *pThread = (myThread *)lpParam;
	cout << pThread->Num << " " << pThread->Test << endl;
	return 0;
}

int myThread::ThreadNew()
{
	hThread = CreateThread(NULL, 0, TestFun, this, 0, NULL);
	return 0;
}


int main()
{
	myThread TestData(2, 2);
	TestData.ThreadNew();

	WaitForSingleObject(TestData.hThread, INFINITE);
	CloseHandle(TestData.hThread);

	return 0;
}
