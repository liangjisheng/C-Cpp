
#include <Windows.h>
#include <process.h>
#include <iostream>
#include <tchar.h>

using std::cout;
using std::endl;


// 启动一个进程
BOOL WakeupProc(const WCHAR *strFilePath)
{
	STARTUPINFO StartInfo;
	PROCESS_INFORMATION procStruct;
	memset(&StartInfo, 0, sizeof(STARTUPINFO));

	BOOL bSuc = ::CreateProcess(strFilePath, NULL, NULL, NULL,
		FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &StartInfo, &procStruct);
	if(!bSuc)
	{
		LPVOID lpMsgBuf = NULL;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
			(LPTSTR)lpMsgBuf, 0, NULL);
	}
	return bSuc;
}


int main()
{
	TCHAR szExePath[MAX_PATH] = {0};
	GetModuleFileName(NULL, szExePath, MAX_PATH);
	_tcsrchr(szExePath, _T('\\'))[1] = _T('\0');
	TCHAR szPath[MAX_PATH] = {0};
	_tcscpy(szPath, szExePath);
	_tcscat(szPath, _T("0921-1.exe"));

	WakeupProc(szPath);

	system("pause");
	return 0;
}