
#include "stdafx.h"
#include "Thread.h"

void CThread::Run(void *ptr)
{
	HWND hWnd = (HWND)ptr;
	for(int i = 0; i < 100; i++)
	{
		::PostMessage(hWnd, WM_USER_MSG, WPARAM(i), LPARAM(0));
		Sleep(100);
	}
	AfxMessageBox(_T("完成"));
	::PostMessage(hWnd, WM_USER_MSG, WPARAM(0), LPARAM(0));
	_endthread();
}


CThread::CThread(void)
{

}


CThread::~CThread(void)
{

}