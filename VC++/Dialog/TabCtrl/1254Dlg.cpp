// 1254Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1254.h"
#include "1254Dlg.h"

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
// CMy1254Dlg dialog

CMy1254Dlg::CMy1254Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1254Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1254Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1254Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1254Dlg)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1254Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1254Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1254Dlg message handlers

BOOL CMy1254Dlg::OnInitDialog()
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
	
	m_ImageList.Create(32,32,ILC_COLOR24 | ILC_MASK,1,0);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));

	m_Tab.SetImageList(&m_ImageList);		// 关联图像列表
	// 第一个参数表示标签项索引，第三个参数表示图像列表索引，两者之间没有任何关系
	m_Tab.InsertItem(0,"员工信息",0);		// 插入标签项
	m_Tab.InsertItem(1,"客户信息",1);
	m_Tab.InsertItem(2,"供应商信息",2);

	m_eDlg = new CEmployee;			// 分配内存
	m_cDlg = new CClient;
	m_pDlg = new CProvidedlg;

	m_eDlg->Create(IDD_DIALOG_EMP,&m_Tab);	// 创建对话框
	m_cDlg->Create(IDD_DIALOG_CLI,&m_Tab);
	m_pDlg->Create(IDD_DIALOG_PRO,&m_Tab);

	m_eDlg->CenterWindow();		// 设置员工对话框中心位置
	m_eDlg->ShowWindow(SW_SHOW);		// 显示
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1254Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1254Dlg::OnPaint() 
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
HCURSOR CMy1254Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1254Dlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int Index = m_Tab.GetCurSel();		// 获得当前选中标签项索引
	switch(Index)
	{
	case 0:
		m_eDlg->CenterWindow();		// 员工对话框在中心
		m_eDlg->ShowWindow(SW_SHOW);
		m_cDlg->ShowWindow(SW_HIDE);	// 隐藏
		m_pDlg->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_cDlg->CenterWindow();
		m_eDlg->ShowWindow(SW_HIDE);
		m_cDlg->ShowWindow(SW_SHOW);
		m_pDlg->ShowWindow(SW_HIDE);
		break;
	case 2:
		m_pDlg->CenterWindow();
		m_eDlg->ShowWindow(SW_HIDE);
		m_cDlg->ShowWindow(SW_HIDE);
		m_pDlg->ShowWindow(SW_SHOW);
		break;
	}
	
	*pResult = 0;
}

void CMy1254Dlg::OnClose() 
{
	// 主对话框关闭时销毁三个非模态对话框，并释放指针
	m_eDlg->DestroyWindow();
	delete m_eDlg;
	m_eDlg = NULL;
	m_cDlg->DestroyWindow();
	delete m_cDlg;
	m_cDlg = NULL;
	m_pDlg->DestroyWindow();
	delete m_pDlg;
	m_pDlg = NULL;

	CDialog::OnClose();
}
