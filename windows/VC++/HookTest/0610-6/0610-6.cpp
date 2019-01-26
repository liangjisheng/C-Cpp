// 0610-6.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "0610-6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString cskey[3] = { _T("BACKSPACE"), _T("TAB"), _T("F12") };
int nkey[3] = { 0x08, 0x09, 0x7b };

HHOOK g_hTestHook = NULL;		// ��װ�ļ��̹��Ӿ��
HMODULE g_hInstance = NULL;		// dllʵ�����


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

	// ��������Ϣ�����������´�
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
	idHook:�������ͣ����Ǻ͹��Ӻ�������һһ��Ӧ�ģ����磬WH_KEYBOARD��ʾ��װ���Ǽ��̹��ӣ�
	WH_MOUSE��ʾ������깳�ӵȡ�
	lpfn�����Ӻ����ĵ�ַ
	hMod:���Ӻ������ڵ�ʵ���ľ���������̹߳��ӣ��ò���ΪNULL������ϵͳ���ӣ��ò���Ϊ���Ӻ�����DLL���
	dwThreadId:ָ�����������ӵ��̵߳��̺߳ţ�����ȫ�ֹ��ӣ��ò���ΪNULL.
	SetWindowsHookEx��������װ�Ĺ��Ӿ����
	����StartHook���������м��̵���Ϣ����ת�Ƶ�KeyboradProc�����У�
	ͨ������nkey��ֵ��wParam������Ƚϣ�����֪���û����µ����ĸ�����
	ͨ����IParamֵ���жϣ�����֪���ǰ��¼������ͷż���Ȼ�󲥷ż���Ӧ�������ļ����ɡ�
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


