
// Thread_Struct_paramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Thread_Struct_param.h"
#include "Thread_Struct_paramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void ThreadFunc(LPVOID lpParam)
{
	ThreadInfo *pInfo = (ThreadInfo *)lpParam;
	for(int i = 0; i < 100; i++)
	{
		pInfo->pCtrlProgress->SetPos(i);
		Sleep(pInfo->nMilliSecond);
	}
	// 进度条走完之后，在子线程中将开始按钮设置可用
	AfxGetApp()->GetMainWnd()->GetDlgItem(IDC_BUTTON_START)->EnableWindow(TRUE);
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


// CThread_Struct_paramDlg dialog




CThread_Struct_paramDlg::CThread_Struct_paramDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThread_Struct_paramDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hThread = NULL;
	m_dwThreadID = 0;
	m_Info.nMilliSecond = 0;
	m_Info.pCtrlProgress = NULL;
}

void CThread_Struct_paramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
}

BEGIN_MESSAGE_MAP(CThread_Struct_paramDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CThread_Struct_paramDlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// CThread_Struct_paramDlg message handlers

BOOL CThread_Struct_paramDlg::OnInitDialog()
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

	m_ctrlProgress.SetRange(0, 99);
	GetDlgItem(IDC_EDIT_MILLISECOND)->SetWindowText(_T("10"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThread_Struct_paramDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThread_Struct_paramDlg::OnPaint()
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
HCURSOR CThread_Struct_paramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CThread_Struct_paramDlg::OnBnClickedButtonStart()
{
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(FALSE);
	CString strNum = _T("");
	GetDlgItem(IDC_EDIT_MILLISECOND)->GetWindowText(strNum);
	m_Info.nMilliSecond = _ttoi(strNum);
	m_Info.pCtrlProgress = &m_ctrlProgress;

	m_hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc,
		(LPVOID)&m_Info, 0, &m_dwThreadID);
	// 如果加上下面这两句的话，WaitForSingleObject会导致主线程挂起，但是子线程
	// 需要设置进度条，等待主线程将进度条的刷新消息返回给子线程，而主线程等待
	// 子线程结束，不会处理任何消息，造成死锁
	// WaitForSingleObject(m_hThread, INFINITE);
	// GetDlgItem(IDC_BUTTON_START)->EnableWindow(TRUE);
}
