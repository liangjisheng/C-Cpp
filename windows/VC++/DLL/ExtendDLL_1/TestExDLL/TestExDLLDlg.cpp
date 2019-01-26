// TestExDLLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestExDLL.h"
#include "TestExDLLDlg.h"

#pragma comment(lib, "..\\debug\\ExDll.lib")
#include "..\ExDLL\MyDlg.h"
extern "C" __declspec(dllimport) INT_PTR ShowDlg();

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestExDLLDlg dialog




CTestExDLLDlg::CTestExDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestExDLLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestExDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestExDLLDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CTestExDLLDlg message handlers

BOOL CTestExDLLDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

    // 手动进行资源切换
    HINSTANCE oldHInst = AfxGetResourceHandle();
    HINSTANCE hInst = LoadLibrary("ExDll.dll");
    AfxSetResourceHandle(hInst);
    CMyDlg dlg;
    dlg.DoModal();
    AfxSetResourceHandle(oldHInst);

    // 调用函数内部进行资源切换
    ShowDlg();

    // 未进行资源切换
    CMyDlg myDlg;
    myDlg.DoModal();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestExDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestExDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

