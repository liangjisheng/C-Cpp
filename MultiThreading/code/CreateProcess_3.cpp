
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

int main()
{
	STARTUPINFO si;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;
	PROCESS_INFORMATION pi;

	BOOL bRet = CreateProcess(
		TEXT("C:\\Windows\\System32\\notepad.exe"),
		NULL, 
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);

	if (bRet)
		cout << "success" << endl;
	else
		cout << "failed" << endl;

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	system("pause");
	return 0;
}