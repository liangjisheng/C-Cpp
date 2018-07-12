
// 0926-4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "0926-4.h"
#include "0926-4Dlg.h"
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

CMy09264Dlg::CMy09264Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy09264Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy09264Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy09264Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMy09264Dlg message handlers

BOOL CMy09264Dlg::OnInitDialog()
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

	GetDlgItem(IDC_STATIC_SLink)->GetWindowRect(&m_Rect);
	ScreenToClient(&m_Rect);

	m_cfNtr = this->GetFont();
	m_cfNtr->GetLogFont(&m_lfNtr);
	m_cfNtr->GetLogFont(&m_lfUL);
	m_lfUL.lfUnderline = TRUE;
	// 通过逻辑结构创建字体
	m_cfUL.CreateFontIndirect(&m_lfUL);

	m_brush.CreateSysColorBrush(COLOR_MENU);	
	m_color = RGB(0, 0, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy09264Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy09264Dlg::OnPaint()
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
HCURSOR CMy09264Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy09264Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(point.x > m_Rect.left && point.x < m_Rect.right
		&& point.y > m_Rect.top && point.y < m_Rect.bottom)
	{
		ShellExecute(NULL,_T("open"), _T("http://blog.csdn.net/liangjisheng"),
			NULL, NULL, SW_NORMAL);
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMy09264Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if(point.x > m_Rect.left && point.x < m_Rect.right
		&& point.y > m_Rect.top && point.y < m_Rect.bottom)
	{
		HCURSOR hCursor = ::LoadCursor(NULL, IDC_HAND);
		::SetCursor(hCursor);

		GetDlgItem(IDC_STATIC_SLink)->SetFont(&m_cfUL);

		m_color = RGB(0, 0, 255);
		CStatic *m_pStatic = (CStatic *)GetDlgItem(IDC_STATIC_SLink);
		m_pStatic->RedrawWindow();
	}
	else
	{
		GetDlgItem(IDC_STATIC_SLink)->SetFont(m_cfNtr);

		m_color = RGB(0, 0, 0);
		CStatic *m_pStatic = (CStatic *)GetDlgItem(IDC_STATIC_SLink);
		m_pStatic->RedrawWindow();
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


HBRUSH CMy09264Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC)
	{
		// 如果是静态文本控件的话
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_color);
		return (HBRUSH)m_brush.GetSafeHandle();
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
