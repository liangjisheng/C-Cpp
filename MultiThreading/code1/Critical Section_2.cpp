
#include <Windows.h>
#include <iostream>

using namespace std;

int index = 0;
CRITICAL_SECTION g_cs;


void add1() { cout << index++ << endl; }

void add2() { cout << index++ << endl; }

void add3() { cout << index++ << endl; }


DWORD WINAPI ThreadFunc1(LPVOID lpParam)
{
	EnterCriticalSection(&g_cs);
	add1();
	add2();
	add3();
	LeaveCriticalSection(&g_cs);
	return 0;
}


DWORD WINAPI ThreadFunc2(LPVOID lpParam)
{
	EnterCriticalSection(&g_cs);
	add1();
	add2();
	add3();
	LeaveCriticalSection(&g_cs);
	return 0;
}


int main()
{
	InitializeCriticalSection(&g_cs);
	HANDLE hThread1, hThread2;
	hThread1 = CreateThread(NULL, 0, ThreadFunc1, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, ThreadFunc2, NULL, 0, NULL);
	/*cout << "input a number:";
	int k;
	cin >> k;1
	cout << "hello World." << endl;*/

	system("pause");
	return 0;
}

