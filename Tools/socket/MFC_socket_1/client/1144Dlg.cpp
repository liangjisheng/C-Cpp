// 1144Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1144.h"
#include "1144Dlg.h"

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
// CMy1144Dlg dialog

CMy1144Dlg::CMy1144Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1144Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1144Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1144Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1144Dlg)
	DDX_Control(pDX, IDC_EDIT_SENDTEXT, m_sEdit);
	DDX_Control(pDX, IDC_EDIT_RECVTEXT, m_rEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1144Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1144Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1144Dlg message handlers

BOOL CMy1144Dlg::OnInitDialog()
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
	
	c.Create();
	m_sEdit.EnableWindow(false);
	GetDlgItem(IDC_SEND)->EnableWindow(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1144Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1144Dlg::OnPaint() 
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
HCURSOR CMy1144Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1144Dlg::OnConnect() 
{
	CString straddr,strport,strtext;
	GetDlgItem(IDC_EDIT_ADDR)->GetWindowText(straddr);
	GetDlgItem(IDC_EDIT_PORT)->GetWindowText(strport);
	int port=atoi(strport);
	if(straddr=="" || strport=="") {
		MessageBox("IP地址或端口号不能为空","title",MB_OK);
		return ;
	}
	if(strport!="8888") {
		MessageBox("端口号错误......\r\n","title",MB_OK);
		return ;
	}
	if(!c.Connect(straddr,port)) {
		MessageBox("连接服务器成功......","Title",MB_OK);
		GetDlgItem(IDC_EDIT_ADDR)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_PORT)->EnableWindow(false);
		GetDlgItem(IDC_CONNECT)->EnableWindow(false);
		m_sEdit.EnableWindow(true);
		GetDlgItem(IDC_SEND)->EnableWindow(true);
		m_sEdit.SetFocus();
	}
	else
		MessageBox("连接服务器失败......\r\n重新输入IP地址和端口号\r\n",
			"Title",MB_OK);
}

void CMy1144Dlg::OnSend() 
{
	CString sendtext,recvtext;
	m_sEdit.GetWindowText(sendtext);
	if(sendtext=="")
		MessageBox("发送内容不能为空","Title",MB_OK);
	else {
		c.Send(sendtext.GetBuffer(0),sendtext.GetLength(),0);
		sendtext.ReleaseBuffer();
		m_sEdit.SetWindowText("");
		m_sEdit.SetFocus();
		m_rEdit.GetWindowText(recvtext);
		recvtext=recvtext+"client:"+sendtext+"\r\n";
		m_rEdit.SetWindowText(recvtext);
	}
}
