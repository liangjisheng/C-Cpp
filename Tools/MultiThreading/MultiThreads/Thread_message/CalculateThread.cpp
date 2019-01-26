// CalculateThread.cpp : implementation file
//

#include "stdafx.h"
#include "Thread_message.h"
#include "CalculateThread.h"


// CCalculateThread

IMPLEMENT_DYNCREATE(CCalculateThread, CWinThread)

CCalculateThread::CCalculateThread()
{
}

CCalculateThread::~CCalculateThread()
{
}

BOOL CCalculateThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CCalculateThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CCalculateThread, CWinThread)
	ON_THREAD_MESSAGE(WM_CALCULATE, OnCalculate)
END_MESSAGE_MAP()


// CCalculateThread message handlers
void CCalculateThread::OnCalculate(WPARAM wParam, LPARAM lParam)
{
	int nTemp = 0;
	for(int i = 0; i < (int)wParam; i++)
		nTemp += i;
	Sleep(500);
	::PostMessage((HWND)(GetMainWnd()->GetSafeHwnd()), WM_DISPLAY, nTemp, NULL);
}