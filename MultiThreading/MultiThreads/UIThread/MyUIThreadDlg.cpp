// MyUIThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UIThread.h"
#include "MyUIThreadDlg.h"
#include "afxdialogex.h"


// CMyUIThreadDlg dialog

IMPLEMENT_DYNAMIC(CMyUIThreadDlg, CDialogEx)

CMyUIThreadDlg::CMyUIThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyUIThreadDlg::IDD, pParent)
{

}

CMyUIThreadDlg::~CMyUIThreadDlg()
{
	int a = 0;
}

void CMyUIThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyUIThreadDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMyUIThreadDlg message handlers


void CMyUIThreadDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	AfxMessageBox(_T("You Clicked The Left Button!"));

	CDialogEx::OnLButtonDown(nFlags, point);
}
