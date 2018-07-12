
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

const int num = 2;
int count;
unsigned __stdcall ThreadFun(void *par);

int main()
{
	count = 0;
	HANDLE handles[num];
	for(int i = 0; i < num; i++)
		handles[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, 0);

	for(int i = 0; i < num; i++)
		CloseHandle(handles[i]);

	system("pause");
	return 0;
}

unsigned __stdcall ThreadFun(void *par)
{
	Sleep(100);
	for(int i = 0; i < 10; i++)
		cout << "cout:" << ++count << endl;
	count = 0;
	return 0;
}

