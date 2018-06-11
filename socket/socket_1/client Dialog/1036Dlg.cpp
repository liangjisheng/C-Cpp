// 1036Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1036.h"
#include "1036Dlg.h"

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
// CMy1036Dlg dialog

CMy1036Dlg::CMy1036Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1036Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1036Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1036Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1036Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1036Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1036Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_MESSAGE(WM_SOCKET,OnSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1036Dlg message handlers

BOOL CMy1036Dlg::OnInitDialog()
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
	GetDlgItem(IDC_SENDTEXT)->EnableWindow(false);	// 禁用
	GetDlgItem(IDC_SEND)->EnableWindow(false);
	GetDlgItem(IDC_TEXT)->EnableWindow(false);
	s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);	// 创建流式TCP套接字
	// 将套接字设置为异步模式，最后一个参数有四种标志，FD_READ,FD_WRITE,FD_ACCEPT,FD_CLOSE
	// WM_SOCKET 为消息
	::WSAAsyncSelect(s,this->m_hWnd,WM_SOCKET,FD_READ);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1036Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1036Dlg::OnPaint() 
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
HCURSOR CMy1036Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1036Dlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	CString straddr,strport;
	GetDlgItem(IDC_ADDR)->GetWindowText(straddr);
	GetDlgItem(IDC_PORT)->GetWindowText(strport);
	if(straddr=="" || strport=="")
		MessageBox("服务器地址后端口号不能为空","title",MB_OK | MB_ICONINFORMATION);
	else {
		int port=atoi(strport.GetBuffer(0));
		addr.sin_family=AF_INET;
		addr.sin_port=htons(port);
		addr.sin_addr.S_un.S_addr=inet_addr(straddr.GetBuffer(0));
		GetDlgItem(IDC_TEXT)->SetWindowText("正在连接服务器......\r\n");
		CString strtext;
		if(::connect(s,(sockaddr*)&addr,sizeof(addr))!=SOCKET_ERROR) {
			GetDlgItem(IDC_TEXT)->GetWindowText(strtext);
			strtext+="连接服务器成功......\r\n";
			GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
			GetDlgItem(IDC_SEND)->EnableWindow(true);
			GetDlgItem(IDC_SENDTEXT)->EnableWindow(true);
			GetDlgItem(IDC_ADDR)->EnableWindow(false);
			GetDlgItem(IDC_PORT)->EnableWindow(false);
		}
		else {
			GetDlgItem(IDC_TEXT)->GetWindowText(strtext);
			strtext+="连接服务器失败......\r\n";
			GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
		}
	}
}

void CMy1036Dlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	CString strtext,strsendtext;
	GetDlgItem(IDC_SENDTEXT)->GetWindowText(strsendtext);
	if(strsendtext=="") {
		GetDlgItem(IDC_TEXT)->GetWindowText(strtext);
		strtext+="\r\n消息不能为空......\r\n";
		GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
	}
	else {
		// 发送信息到制定服务器
		::send(s,strsendtext.GetBuffer(1),sizeof(strsendtext),0);
		GetDlgItem(IDC_TEXT)->GetWindowText(strtext);
		strtext+="\r\n"+strsendtext+"\r\n";
		GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
	}
}

void CMy1036Dlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	char cs[100]={0};
	if(lParam==FD_READ) {	// 套接字读取
		CString num="";
		// sockaddr_in addr;
		// ::getpeername(s,(SOCKADDR*)&addr,(int*)sizeof(addr));
		recv(s,cs,100,NULL);
		GetDlgItem(IDC_TEXT)->GetWindowText(num);
		num+="\r\n服务器说: ";
		num+=(LPTSTR)cs;
		GetDlgItem(IDC_TEXT)->SetWindowText(num);
	}
}
