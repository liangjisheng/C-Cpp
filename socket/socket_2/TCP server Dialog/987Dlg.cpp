// 987Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "987.h"
#include "987Dlg.h"

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
// CMy987Dlg dialog

CMy987Dlg::CMy987Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy987Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy987Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy987Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy987Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy987Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy987Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SOCKET,OnSocket)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy987Dlg message handlers

BOOL CMy987Dlg::OnInitDialog()
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
	addr.sin_family=AF_INET;
	addr.sin_port=htons(54321);
	addr.sin_addr.S_un.S_addr=INADDR_ANY;
	::bind(s,(sockaddr*)&addr,sizeof(addr));
	::listen(s,2);
	GetDlgItem(IDC_TEXT)->EnableWindow(false);
	GetDlgItem(IDC_ADDR)->SetWindowText("服务器监听已经启动!");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy987Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy987Dlg::OnPaint() 
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
HCURSOR CMy987Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy987Dlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	CString str;
	int n=0;
	char cs[100]={0};
	switch(lParam) {

	case FD_ACCEPT:
		s1=::accept(s,(sockaddr*)&addr1,(int*)sizeof(addr1));
		n=n+1;
		str.Format("有%d个客户端已经连接上了",n);
		GetDlgItem(IDC_TEXT)->SetWindowText(str);
		str+=::inet_ntoa(addr1.sin_addr);	// 转换IP地址
		str+="登录\r\n";
		GetDlgItem(IDC_TEXT)->SetWindowText(str);
		break;

	case FD_READ:
		CString num="";
		::recv(s1,cs,100,0);
		GetDlgItem(IDC_TEXT)->GetWindowText(num);
		num+="\r\n";
		num+="对您说: ";
		num+=(LPCTSTR)cs;
		GetDlgItem(IDC_TEXT)->SetWindowText(num);
		break;
	}
}

void CMy987Dlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItem(IDC_SENDTEXT)->GetWindowText(str);
	if(str=="")
		MessageBox("消息不能为空");
	else {
		if(::send(s1,str.GetBuffer(1),sizeof(str),0)!=SOCKET_ERROR) {
			GetDlgItem(IDC_TEXT)->SetWindowText("消息以发送到客户端\r\n");
			GetDlgItem(IDC_TEXT)->GetWindowText(str);
			str+="\r\n";
			GetDlgItem(IDC_TEXT)->SetWindowText(str);
		}
		else 
			GetDlgItem(IDC_TEXT)->SetWindowText("消息发送失败!\r\n");
	}
}
