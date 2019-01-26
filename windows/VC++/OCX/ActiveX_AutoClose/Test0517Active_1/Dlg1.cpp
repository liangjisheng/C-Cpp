// Dlg1.cpp : implementation file
//

#include "stdafx.h"
#include "Test0517Active_1.h"
#include "Dlg1.h"
#include "afxdialogex.h"


// CDlg1 dialog

IMPLEMENT_DYNAMIC(CDlg1, CDialogEx)

CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg1::IDD, pParent)
{

}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialogEx)
	ON_MESSAGE(WM_CREATETIMER, OnCreateTimer)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg1 message handlers

LRESULT CDlg1::OnCreateTimer(WPARAM wParam, LPARAM lParam)
{
	SetTimer(0, 1000, NULL);
	return 0;
}

void CDlg1::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	HWND hWnd = ::FindWindow(NULL, _T("Test0517Active_1Dlg"));
	if(hWnd != NULL)
	{
		PostMessage(WM_CLOSE);
	}

	CDialogEx::OnTimer(nIDEvent);
}
