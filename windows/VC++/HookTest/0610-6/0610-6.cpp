// 0610-6.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "0610-6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString cskey[3] = { _T("BACKSPACE"), _T("TAB"), _T("F12") };
int nkey[3] = { 0x08, 0x09, 0x7b };

HHOOK g_hTestHook = NULL;		// 安装的键盘钩子句柄
HMODULE g_hInstance = NULL;		// dll实例句柄


LRESULT WINAPI KeyboradProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < 3; i++)
	{
		if (nkey[i] == (int)wParam)
		{
			int nKeyStatus = lParam & 0x80000000;
			switch (nKeyStatus)
			{
			case 0:			// WM_KEYUP
			{
				TCHAR* pszFileName = _T("keyboradfile.txt");
				CStdioFile myFile;
				CFileException fileException;
				if (myFile.Open(pszFileName, 
					CFile::typeText | CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite), 
					&fileException)
				{
					myFile.SeekToEnd();
					myFile.WriteString(cskey[i]);
					myFile.WriteString(_T("\n"));
				}
				else
					TRACE(_T("Can't open file %s,error = %u\n"), pszFileName, fileException.m_cause);
				
			}
			default:
				break;
			}
		}
	}

	// 讲键盘消息继续接着往下传
	return CallNextHookEx(g_hTestHook, nCode, wParam, lParam);
}


CHookTest::CHookTest()
{

}

CHookTest::~CHookTest()
{

}


BOOL CHookTest::StartHook()
{
	/*
	HHOOK SetWindowsHookEx(int idHook,HOOKPROC lpfn,INSTANCE hMod,DWORD dwThreadId)
	idHook:钩子类型，它是和钩子函数类型一一对应的，例如，WH_KEYBOARD表示安装的是键盘钩子，
	WH_MOUSE表示的是鼠标钩子等。
	lpfn：钩子函数的地址
	hMod:钩子函数所在的实例的句柄，对于线程钩子，该参数为NULL；对于系统钩子，该参数为钩子函数的DLL句柄
	dwThreadId:指定钩子所监视的线程的线程号，对于全局钩子，该参数为NULL.
	SetWindowsHookEx返回所安装的钩子句柄。
	调用StartHook函数后，所有键盘的消息都会转移到KeyboradProc函数中，
	通过数组nkey的值与wParam参数相比较，可以知道用户按下的是哪个键，
	通过对IParam值的判断，可以知道是按下键还是释放键，然后播放键对应的声音文件即可。
	*/

	g_hTestHook = SetWindowsHookEx(WH_KEYBOARD, KeyboradProc, g_hInstance, 0);
	if (g_hTestHook != NULL)
		return TRUE;
	else
		return FALSE;
}


BOOL CHookTest::StopHook()
{
	BOOL bRes = FALSE;
	if (g_hTestHook)
	{
		bRes = UnhookWindowsHookEx(g_hTestHook);
		if (bRes)
			g_hTestHook = NULL;
	}
	return bRes;
}


