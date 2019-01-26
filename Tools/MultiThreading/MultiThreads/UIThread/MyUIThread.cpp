// MyUIThread.cpp : implementation file
//

#include "stdafx.h"
#include "UIThread.h"
#include "MyUIThread.h"


// CMyUIThread

IMPLEMENT_DYNCREATE(CMyUIThread, CWinThread)

CMyUIThread::CMyUIThread()
{
}

CMyUIThread::~CMyUIThread()
{
	int a = 0;
}

BOOL CMyUIThread::InitInstance()
{
	m_dlg.Create(IDD_DIALOG1);
	m_dlg.ShowWindow(SW_SHOW);
	m_pMainWnd = &m_dlg;

	return TRUE;
}

int CMyUIThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	m_dlg.DestroyWindow();
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyUIThread, CWinThread)
END_MESSAGE_MAP()


// CMyUIThread message handlers
