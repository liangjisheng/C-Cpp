// 1009Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1009.h"
#include "1009Dlg.h"
#pragma comment(lib,"User32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1009Dlg dialog

CMy1009Dlg::CMy1009Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1009Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1009Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1009Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1009Dlg)
	DDX_Control(pDX, IDC_TEXT, m_Edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1009Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1009Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1009Dlg message handlers

BOOL CMy1009Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Edit.SetWindowText("此窗体为动画显示窗体");
	// this->UpdateData(false);
	CenterWindow();	// 创建窗体
	DWORD dwStyle=AW_CENTER;	// 居中
	HINSTANCE hInst=LoadLibrary("User32.DLL");	// 载入动态库
	typedef BOOL(WINAPI MYFUNC(HWND,DWORD,DWORD));// 定义函数类型
	MYFUNC * AnimateWindow;	// 定义函数指针
	AnimateWindow=(MYFUNC*)::GetProcAddress(hInst,"AnimateWindow");	// 获取函数地址
	AnimateWindow(this->m_hWnd,1000,dwStyle);	// 设置窗体动画
	FreeLibrary(hInst);	// 释放动态库
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1009Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy1009Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy1009Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1009Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	DWORD dwStyle=AW_CENTER;
	HINSTANCE hInst=LoadLibrary("User32.DLL");
	typedef BOOL(WINAPI MYFUNC(HWND,DWORD,DWORD));// 定义函数类型
	MYFUNC * AnimateWindow;	// 定义函数指针
	AnimateWindow=(MYFUNC*)::GetProcAddress(hInst,"AnimateWindow");	// 获取函数地址
	AnimateWindow(this->GetSafeHwnd(),700,AW_HIDE | dwStyle);	// 设置窗体动画
	FreeLibrary(hInst);	// 释放动态库
	CDialog::OnCancel();
}
