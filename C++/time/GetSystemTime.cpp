// 1208-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "1208-3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// UTC是格林威治时间，也就是全球标准时间。本地时间就是相对于UTC而言的，
			// 比如中国北京是在东8区，相对于UTC就多了8个小时。一般使用到的时间都是
			// 使用本地时间，也就是调用函数GetLocalTime
			SYSTEMTIME stUTC;
			::GetSystemTime(&stUTC);	// 获取系统的UTC时间

			const int nBufSize = 256;
			TCHAR chBuf[nBufSize] = {0};
			wsprintf(chBuf, _T("UTC: %u/%u/%u %u:%u:%u:%u %d\r\n"),
				stUTC.wYear, stUTC.wMonth, stUTC.wDay,
				stUTC.wHour, stUTC.wMinute, stUTC.wSecond,
				stUTC.wMilliseconds, stUTC.wDayOfWeek);
			wcout << chBuf;
			OutputDebugString(chBuf);

			SYSTEMTIME stLocal;
			::GetLocalTime(&stLocal);
			memset(chBuf, 0, sizeof(TCHAR) * nBufSize);
			wsprintf(chBuf, _T("Local: %u/%u/%u %u:%u:%u:%u %d\r\n"),
				stLocal.wYear, stLocal.wMonth, stLocal.wDay,
				stLocal.wHour, stLocal.wMinute, stLocal.wSecond,
				stLocal.wMilliseconds, stLocal.wDayOfWeek);
			wcout << chBuf;
			OutputDebugString(chBuf);

			system("pause");
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
