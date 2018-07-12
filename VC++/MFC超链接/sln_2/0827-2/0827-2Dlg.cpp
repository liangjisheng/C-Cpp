
// 0827-2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "0827-2.h"
#include "0827-2Dlg.h"
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


// CMy08272Dlg dialog




CMy08272Dlg::CMy08272Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy08272Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy08272Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy08272Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK1, &CMy08272Dlg::OnNMClickSyslink1)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK4, &CMy08272Dlg::OnNMClickSyslink4)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK2, &CMy08272Dlg::OnNMClickSyslink2)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK3, &CMy08272Dlg::OnNMClickSyslink3)
END_MESSAGE_MAP()


// CMy08272Dlg message handlers

BOOL CMy08272Dlg::OnInitDialog()
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

	// GetDlgItem(IDC_SYSLINK1)->SetWindowText(_T("Visit my web site and check my blog."));
	// _T("<a href=\"http://blog.csdn.net/weiwenhp\">weiwenhp²©¿Í</a>")
	CString strUrl = _T("<a href=\"http://blog.csdn.net/liangjisheng\">liangjisheng blog</a>");
	strUrl += _T("<a href=\" https://www.baidu.com \">   baidu</a>");
	GetDlgItem(IDC_SYSLINK1)->SetWindowText(strUrl);

	// GetDlgItem(IDC_SYSLINK4)->SetWindowText(L"Link was <a ID=\"clicked\">" + GetClickText() + L"</a>");
	CString strBaidu = _T("click to  <a href=\"");
	strBaidu = strBaidu + _T("https://www.baidu.com") + _T("\"> baidu.com</a>");
	GetDlgItem(IDC_SYSLINK2)->SetWindowText(strBaidu);

	CString str51CTO = _T("click to  <a href=\" http://down.51cto.com/ \" > 51CTO</a>");
	GetDlgItem(IDC_SYSLINK3)->SetWindowText(str51CTO);

	nClicks = 0;
	SetLink4Text();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy08272Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy08272Dlg::OnPaint()
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
HCURSOR CMy08272Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy08272Dlg::OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult)
{
	PNMLINK pNMLink = (PNMLINK)pNMHDR;
	//if(_tcscmp(pNMLink->item.szUrl, _T("https://www.baidu.com")) == 0)
		// ShellExecute(NULL, _T("open"), pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);
	//else if(_tcscmp(pNMLink->item.szUrl, _T("http://blog.csdn.net/liangjisheng")) == 0)
		// ShellExecute(NULL, _T("open"), pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);

	// ShellExecute(NULL, _T("open"), _T("https://www.baidu.com"), NULL, NULL, SW_SHOWNORMAL);
	// ShellExecute(NULL, _T("open"), _T("http://blog.csdn.net/liangjisheng"), NULL, NULL, SW_SHOWNORMAL);

	ShellExecute(NULL, _T("open"), pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);
	
	*pResult = 0;
}


void CMy08272Dlg::OnNMClickSyslink4(NMHDR *pNMHDR, LRESULT *pResult)
{
	PNMLINK pNMLink = (PNMLINK)pNMHDR;

	if (wcscmp(pNMLink->item.szID, L"clicked") == 0)
	{
		nClicks++;
		SetLink4Text();
	}
	
	*pResult = 0;
}

void CMy08272Dlg::SetLink4Text()
{
	GetDlgItem(IDC_SYSLINK4)->SetWindowText(L"Link was <a ID=\"clicked\">" + GetClickText() + L"</a>");
}

CString CMy08272Dlg::GetClickText() const
{
	CString strNum = _T("");
	strNum.Format(_T("clicked %d times"), nClicks);
	return strNum;
}


void CMy08272Dlg::OnNMClickSyslink2(NMHDR *pNMHDR, LRESULT *pResult)
{
	PNMLINK pNMLink = (PNMLINK)pNMHDR;
	ShellExecute(NULL, _T("open"), pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);
	
	*pResult = 0;
}


void CMy08272Dlg::OnNMClickSyslink3(NMHDR *pNMHDR, LRESULT *pResult)
{
	PNMLINK pNMLink = (PNMLINK)pNMHDR;
	ShellExecute(NULL, _T("open"), pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);
	
	*pResult = 0;
}
