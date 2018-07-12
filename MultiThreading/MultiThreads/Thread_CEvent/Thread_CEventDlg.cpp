
// Thread_CEventDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Thread_CEvent.h"
#include "Thread_CEventDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "afxmt.h"
TCHAR g_Array[11];
CEvent g_EventWriteD;

UINT WriteD(LPVOID lpParam)
{
	CEdit *pEdit = (CEdit *)lpParam;
	pEdit->SetWindowText(_T(""));
	// WaitForSingleObject返回后,g_EventWriteD变为无信号状态
	WaitForSingleObject(g_EventWriteD, INFINITE);

	for(int i = 0; i < 10; i ++)
	{
		g_Array[i] = _T('D');
		pEdit->SetWindowText(g_Array);
		Sleep(200);
	}

	memset(g_Array, 0, sizeof(TCHAR) * 11);
	return 0;
}

UINT WriteW(LPVOID lpParam)
{
	CEdit *pEdit = (CEdit *)lpParam;
	pEdit->SetWindowText(_T(""));

	for(int i = 0; i < 10; i ++)
	{
		g_Array[i] = _T('W');
		pEdit->SetWindowText(g_Array);
		Sleep(200);
	}

	memset(g_Array, 0, sizeof(TCHAR) * 11);
	g_EventWriteD.SetEvent();		// 设置事件对象为有信号状态
	return 0;
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CThread_CEventDlg::CThread_CEventDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThread_CEventDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThread_CEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThread_CEventDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_W, &CThread_CEventDlg::OnBnClickedButtonW)
END_MESSAGE_MAP()


// CThread_CEventDlg message handlers

BOOL CThread_CEventDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThread_CEventDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CThread_CEventDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CThread_CEventDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CThread_CEventDlg::OnBnClickedButtonW()
{
	GetDlgItem(IDC_BUTTON_W)->EnableWindow(FALSE);
	CWinThread *pWriteW = AfxBeginThread(WriteW, GetDlgItem(IDC_EDIT_W),
		THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	pWriteW->ResumeThread();

	CWinThread *pWriteD = AfxBeginThread(WriteD, GetDlgItem(IDC_EDIT_D),
		THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	pWriteD->ResumeThread();

	GetDlgItem(IDC_BUTTON_W)->EnableWindow(TRUE);
}

