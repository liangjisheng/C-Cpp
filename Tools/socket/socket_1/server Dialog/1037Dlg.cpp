// 1037Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1037.h"
#include "1037Dlg.h"

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
// CMy1037Dlg dialog

CMy1037Dlg::CMy1037Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1037Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1037Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1037Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1037Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1037Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1037Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SOCKET,OnSocket)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1037Dlg message handlers

BOOL CMy1037Dlg::OnInitDialog()
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
	s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	CString straddr;
	char name[100]={0};
	::gethostname((char*)&name,(int)sizeof(name));	// 获取主机名字
	hostent *p=::gethostbyname((char*)name);
	in_addr *a=(in_addr*)*p->h_addr_list;	// 获得本机IP地址
	straddr=::inet_ntoa(a[0]);

	addr.sin_family=AF_INET;
	addr.sin_port=htons(80);
	addr.sin_addr.S_un.S_addr=inet_addr(straddr);	// INADDR_ANY表示可以接受任意客户端的连接
	::bind(s,(sockaddr*)&addr,sizeof(addr));	// 套接字绑定服务器地址
	::listen(s,5);	// 最多客户端数为5个
	GetDlgItem(IDC_STATIC)->SetWindowText("服务器监听已经启动!");
	GetDlgItem(IDC_TEXT)->EnableWindow(false);	// 禁用
	::WSAAsyncSelect(s,this->m_hWnd,WM_SOCKET,FD_READ | FD_WRITE);	// 异步模式

	hi[0]=::LoadIcon(AfxGetApp()->m_hInstance,(char*)IDI_ICON1);
	hi[1]=::LoadIcon(AfxGetApp()->m_hInstance,(char*)IDI_ICON2);
	::SendMessage(m_hWnd,WM_SETICON,0,(LONG)hi[0]);	// 出事设置窗口图标

	CTime time;
	CString str,str1;
	time=CTime::GetCurrentTime();
	str=time.Format("%H:%M:%S");
	str1="当前时间:";
	str1+=str;
	MessageBox(str1);

	// SetWindowText("lishuyu");	// 设置窗口标题
	// ::SendMessage(,SB_SETBKCOLOR,0,(long)RGB(255,0,0));	// 状态栏初始颜色为红色
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1037Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1037Dlg::OnPaint() 
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
HCURSOR CMy1037Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 监听事件消息响应函数
void CMy1037Dlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	CString strtext;
	char cs[100]={0};	// 数据缓冲区
	int n=0;
	switch(lParam) {

	case FD_ACCEPT: {
		// 应答客户端的连接请求
		s1=::accept(s,(SOCKADDR*)&addr1,(int*)sizeof(addr1));
		n=n+1;
		strtext.Format("已经有%d个客户端连接上了\r\n",n);
		// GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
		::getpeername(s1,(SOCKADDR*)&addr1,(int*)sizeof(addr1));	// 获取连接客户端的IP
		strtext+=::inet_ntoa(addr1.sin_addr);	// 转换IP地址
		strtext+="登录\r\n";
		GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
		break; }

	case FD_READ: {
		CString num="";
		::recv(s1,cs,100,0);
		GetDlgItem(IDC_TEXT)->GetWindowText(num);
		num=num+"\r\n"+(LPTSTR)::inet_ntoa(addr1.sin_addr);
		num=num+"对您说:"+(LPTSTR)cs;
		GetDlgItem(IDC_TEXT)->SetWindowText(num);
		break;  }
	}
}

void CMy1037Dlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	CString strsendtext="",strtext="";
	GetDlgItem(IDC_SENDTEXT)->GetWindowText(strsendtext);
	if(strsendtext=="")
		MessageBox("消息不能为空","title",MB_OK | MB_ICONINFORMATION);
	else {
		if(::send(s1,strsendtext.GetBuffer(1),sizeof(strsendtext),0)!=SOCKET_ERROR) {
			GetDlgItem(IDC_TEXT)->SetWindowText("消息已经发送到客户端");
			GetDlgItem(IDC_TEXT)->GetWindowText(strtext);
			strtext+="\r\n";
			GetDlgItem(IDC_TEXT)->SetWindowText(strtext);
		}
		else 
			GetDlgItem(IDC_TEXT)->SetWindowText("消息发送失败!\r\n");
	}
}

void CMy1037Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int i=0;
	if(i<=1) {
		::SendMessage(m_hWnd,WM_SETICON,0,(LONG)hi[i++]);
	}
	else i=0;
	CDialog::OnTimer(nIDEvent);
}

void CMy1037Dlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	CDialog::OnClose();
}
