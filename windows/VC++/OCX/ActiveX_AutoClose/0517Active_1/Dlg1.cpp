// Dlg1.cpp : implementation file
//

#include "stdafx.h"
#include "0517Active_1.h"
#include "Dlg1.h"
#include "afxdialogex.h"
#include <math.h>

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
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlg1 message handlers


void CDlg1::OnBnClickedButton1()
{
	int res = 0;
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			double d1 = cos(1.28) + sin(3.14) + tan(2.56);
			res = res + i;
		}
	}
	CString str;
	str.Format(_T("%d"), res);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	//MessageBox(_T("¼ÆËãÍê³É"), _T("tip"), MB_OKCANCEL);

	//HWND hWnd = ::FindWindow(NULL, _T("Test0517Active_1Dlg"));
	//if(hWnd != NULL)
	//{
		::PostMessage(this->GetParent()->GetParent()->m_hWnd, WM_CREATETIMER, 0, 0);
	//}
}
