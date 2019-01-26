
// Thread_CriticalSectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Thread_CriticalSection.h"
#include "Thread_CriticalSectionDlg.h"
#include "afxdialogex.h"
#include "afxmt.h"

CCriticalSection critical_section;
TCHAR g_Array[11];

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UINT WriteW(LPVOID pParam)
{
	CEdit *pEdit = (CEdit *)pParam;
	pEdit->SetWindowText(_T(""));
	critical_section.Lock();

	memset(g_Array, 0, sizeof(TCHAR) * 10);
	for(int i = 0; i < 10; i++)
	{
		g_Array[i] = _T('W');
		pEdit->SetWindowText(g_Array);
		Sleep(200);
	}

	critical_section.Unlock();
	return 0;
}

UINT WriteD(LPVOID pParam)
{
	CEdit *pEdit = (CEdit *)pParam;
	pEdit->SetWindowText(_T(""));
	critical_section.Lock();

	memset(g_Array, 0, sizeof(TCHAR) * 10);
	for(int i = 0; i < 10; i++)
	{
		g_Array[i] = _T('D');
		pEdit->SetWindowText(g_Array);
		Sleep(200);
	}

	critical_section.Unlock();
	return 0;
}

// 当多个线程访问一个独占性共性资源时，可以使用临界区对象，任一时刻只有
// 一个线程可以拥有临界区对象,拥有临界区的线程可以访问被保护起来的资源
// 或代码段，其它希望进入临界区的线程将被挂起等待，直到拥有临界区的线程
// 放弃临界区为止，这样就不会在同一时刻出现多个线程访问共享资源

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

CThread_CriticalSectionDlg::CThread_CriticalSectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThread_CriticalSectionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThread_CriticalSectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThread_CriticalSectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_WRITEW, &CThread_CriticalSectionDlg::OnBnClickedButtonWritew)
	ON_BN_CLICKED(IDC_BUTTON_WRITED, &CThread_CriticalSectionDlg::OnBnClickedButtonWrited)
END_MESSAGE_MAP()


// CThread_CriticalSectionDlg message handlers

BOOL CThread_CriticalSectionDlg::OnInitDialog()
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

void CThread_CriticalSectionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThread_CriticalSectionDlg::OnPaint()
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
HCURSOR CThread_CriticalSectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CThread_CriticalSectionDlg::OnBnClickedButtonWritew()
{
	// 最后一个参数表示建立线程是不是立即执行，而是挂起
	CWinThread *pWriteW = AfxBeginThread(WriteW, GetDlgItem(IDC_EDIT_W),
		THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	// 恢复线程执行
	pWriteW->ResumeThread();
}


void CThread_CriticalSectionDlg::OnBnClickedButtonWrited()
{
	CWinThread *pWriteD = AfxBeginThread(WriteD, GetDlgItem(IDC_EDIT_D),
		THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	pWriteD->ResumeThread();
}
