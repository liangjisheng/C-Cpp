// MFCDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDemo.h"
#include "MFCDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemoDlg dialog

#define		WEB_SITE		L"http://www.mariusbancila.ro"
#define		BLOG_LINK		L"http://www.mariusbancila.ro/blog"


CMFCDemoDlg::CMFCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSLINK2, Link2);
}

BEGIN_MESSAGE_MAP(CMFCDemoDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK1, &CMFCDemoDlg::OnNMClickSyslink1)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK2, &CMFCDemoDlg::OnNMClickSyslink2)
END_MESSAGE_MAP()


// CMFCDemoDlg message handlers

BOOL CMFCDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CString str = L"Visit my <a href=\"" WEB_SITE L"\">web site</a> and check my <a href=\"" BLOG_LINK L"\">blog</a>.";
	GetDlgItem(IDC_SYSLINK1)->SetWindowText(str);

	Clicks = 0;
	SetLink2Text();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDemoDlg::OnPaint()
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
HCURSOR CMFCDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCDemoDlg::OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult)
{
	PNMLINK pNMLink = (PNMLINK) pNMHDR;

	if (wcscmp(pNMLink->item.szUrl, WEB_SITE) == 0)
	{
		ShellExecuteW(NULL, L"open", pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);
	}
	else if(wcscmp(pNMLink->item.szUrl, BLOG_LINK) == 0)
	{
		ShellExecuteW(NULL, L"open", pNMLink->item.szUrl, NULL, NULL, SW_SHOWNORMAL);
	}

	*pResult = 0;
}

void CMFCDemoDlg::OnNMClickSyslink2(NMHDR *pNMHDR, LRESULT *pResult)
{
	PNMLINK pNMLink = (PNMLINK) pNMHDR;

	if (wcscmp(pNMLink->item.szID, L"clicked") == 0)
	{
		Clicks++;
		SetLink2Text();
	}

	*pResult = 0;
}

CString CMFCDemoDlg::GetClickText() const
{
	CString str;
	str.Format(L"clicked %d times", Clicks);
	return str;
}

void CMFCDemoDlg::SetLink2Text()
{
	Link2.SetWindowText(L"Link was <a ID=\"clicked\">" + GetClickText() + L"</a>");	
}