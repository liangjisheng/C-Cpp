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
			// UTC�Ǹ�������ʱ�䣬Ҳ����ȫ���׼ʱ�䡣����ʱ����������UTC���Եģ�
			// �����й��������ڶ�8���������UTC�Ͷ���8��Сʱ��һ��ʹ�õ���ʱ�䶼��
			// ʹ�ñ���ʱ�䣬Ҳ���ǵ��ú���GetLocalTime
			SYSTEMTIME stUTC;
			::GetSystemTime(&stUTC);	// ��ȡϵͳ��UTCʱ��

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
