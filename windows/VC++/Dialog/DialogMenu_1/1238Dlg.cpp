// 1238Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1238.h"
#include "1238Dlg.h"

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
// CMy1238Dlg dialog

CMy1238Dlg::CMy1238Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1238Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1238Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1238Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1238Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1238Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1238Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUCAT,OnMenucat)		// 关联命令ID和消息处理函数
	ON_COMMAND(ID_MENUDOG,OnMenudog)
	ON_COMMAND(ID_MENUMONKEY,OnMenumonkey)
	ON_COMMAND(ID_MENULI,OnMenuLi)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1238Dlg message handlers

BOOL CMy1238Dlg::OnInitDialog()
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
	
	m_Menu.CreateMenu();		// 创建菜单窗口
	CMenu m_PopMenu;
	m_PopMenu.CreatePopupMenu();	// 创建弹出菜单窗口
	m_Menu.AppendMenu(MF_POPUP,(UINT)m_PopMenu.m_hMenu,"动物");	// 插入菜单
	m_PopMenu.AppendMenu(MF_STRING,ID_MENUCAT,"猫");	// 插入子菜单
	m_PopMenu.AppendMenu(MF_STRING,ID_MENUDOG,"狗");
	m_PopMenu.AppendMenu(MF_STRING,ID_MENUMONKEY,"猴子");
	m_Menu.AppendMenu(MF_POPUP,-1,"植物");		// 插入兄弟菜单
	m_PopMenu.AppendMenu(MF_STRING,ID_MENULI,"lishuyu");
	m_PopMenu.Detach();		// 分离菜单句柄
	SetMenu(&m_Menu);			// 将菜单和窗口进行关联
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1238Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1238Dlg::OnPaint() 
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
HCURSOR CMy1238Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1238Dlg::OnMenucat()
{
	MessageBox("猫菜单被按下");
}
void CMy1238Dlg::OnMenudog()
{
	MessageBox("狗菜单被按下");
}
void CMy1238Dlg::OnMenumonkey()
{
	MessageBox("猴子菜单被按下");
}

void CMy1238Dlg::OnMenuLi()
{
	MessageBox("lishuyu");
}
