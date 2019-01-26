
// Thread_messageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Thread_message.h"
#include "Thread_messageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CThread_messageDlg dialog




CThread_messageDlg::CThread_messageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThread_messageDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThread_messageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThread_messageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CThread_messageDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CThread_messageDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CThread_messageDlg::OnBnClickedRadio3)
	ON_MESSAGE(WM_DISPLAY, OnDisplay)
	ON_BN_CLICKED(IDC_BUTTON_SUM, &CThread_messageDlg::OnBnClickedButtonSum)
END_MESSAGE_MAP()


// CThread_messageDlg message handlers

BOOL CThread_messageDlg::OnInitDialog()
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

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);
	m_nAddEnd = 10;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThread_messageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThread_messageDlg::OnPaint()
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
HCURSOR CThread_messageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CThread_messageDlg::OnBnClickedRadio1()
{
	m_nAddEnd = 10;
}


void CThread_messageDlg::OnBnClickedRadio2()
{
	m_nAddEnd = 50;
}


void CThread_messageDlg::OnBnClickedRadio3()
{
	m_nAddEnd = 100;
}

LRESULT CThread_messageDlg::OnDisplay(WPARAM wParam, LPARAM lParam)
{
	int nTemp = (int)wParam;
	SetDlgItemInt(IDC_STATIC_STATUS, nTemp, FALSE);
	GetDlgItem(IDC_BUTTON_SUM)->EnableWindow(TRUE);
	return 0;
}

void CThread_messageDlg::OnBnClickedButtonSum()
{
	GetDlgItem(IDC_BUTTON_SUM)->EnableWindow(FALSE);
	m_pCalculateThread = (CCalculateThread *)AfxBeginThread(RUNTIME_CLASS(CCalculateThread));
	Sleep(500);
	m_pCalculateThread->PostThreadMessage(WM_CALCULATE, m_nAddEnd, NULL);
}
