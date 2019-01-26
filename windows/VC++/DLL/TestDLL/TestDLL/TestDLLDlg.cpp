// TestDLLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDLL.h"
#include "TestDLLDlg.h"

// 调用静态库的包含
#include "..\StaticLib\StaticLib.h"
#pragma comment(lib, "..\\debug\\staticlib.lib")

// 调用Win32DLL的包含
#include "..\Win32DLL\Win32DLL.h"
#pragma comment(lib, "..\\debug\\Win32DLL.lib")

// 调用MFCDLL的包含
#pragma comment(lib, "..\\debug\\MFCDLL.lib")
extern "C" __declspec(dllimport) int nDllValue;
extern "C" __declspec(dllimport) INT_PTR ShowDlg();


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestDLLDlg dialog


CTestDLLDlg::CTestDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDLLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDLLDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CTestDLLDlg message handlers

BOOL CTestDLLDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

    // 测试静态库函数
    int sum = Add(1, 3);

    // 测试Win32DLL
    CWin32DLL winDLL;
    sum = winDLL.Add(2, 3);
    int nValue = GetValue();
    typedef int (*PADDFUN)(void);
    HINSTANCE hModule = LoadLibrary("Win32DLL.dll");
    if (NULL != hModule)
    {  
        PADDFUN pAddFun = (PADDFUN)GetProcAddress(hModule, "GetValue");
        PADDFUN pAddFun1 = (PADDFUN)GetProcAddress(hModule, MAKEINTRESOURCE(5));
        int* pInt = (int*)GetProcAddress(hModule, MAKEINTRESOURCE(4));
        ASSERT(NULL != pAddFun);
        nValue = pAddFun(); 

        FreeLibrary(hModule);
    }

    // 测试MFC常规DLL
    ShowDlg();
    nValue = nDllValue;


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDLLDlg::OnPaint()
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
HCURSOR CTestDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

