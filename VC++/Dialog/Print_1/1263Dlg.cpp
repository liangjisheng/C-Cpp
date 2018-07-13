// 1263Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1263.h"
#include "1263Dlg.h"

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
// CMy1263Dlg dialog

CMy1263Dlg::CMy1263Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1263Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1263Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1263Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1263Dlg)
	DDX_Control(pDX, IDC_FILEPATH, m_Path);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1263Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1263Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTFILE, OnButfile)
	ON_BN_CLICKED(IDC_BUTPRINT, OnButprint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1263Dlg message handlers

BOOL CMy1263Dlg::OnInitDialog()
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
	
	// 设置列表视图的扩展风格，并向列表视图中插入数据
//	m_Title[0] = "商品名称";
//	m_Title[1] = "销售数量";
//	m_Title[2] = "销售金额";
//	m_Title[3] = "售货员";
	
//	m_List.SetExtendedStyle(LVS_EX_FLATSB	// 扁平风格显示滚动条
//		| LVS_EX_FULLROWSELECT				// 允许整行选中
//		| LVS_EX_HEADERDRAGDROP				// 允许整行拖动
//		| LVS_EX_ONECLICKACTIVATE			// 单击选中项
//		| LVS_EX_GRIDLINES					// 画出网格线
//		);
	// 设置标题及列宽度
//	m_List.InsertColumn(0,m_Title[0],LVCFMT_LEFT,100,0);
//	m_List.InsertColumn(1,m_Title[1],LVCFMT_LEFT,100,1);
//	m_List.InsertColumn(2,m_Title[2],LVCFMT_LEFT,100,2);
//	m_List.InsertColumn(3,m_Title[3],LVCFMT_LEFT,100,3);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1263Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1263Dlg::OnPaint() 
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
HCURSOR CMy1263Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1263Dlg::OnButfile() 
{
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"All Files(*.*)|*.*||",AfxGetMainWnd());
	if(dlg.DoModal() == IDOK)
	{
		StrPath = dlg.GetPathName();	// 获得文件完整路径
		m_Path.SetWindowText(StrPath);
	}
}

void CMy1263Dlg::OnButprint() 
{
	// 调用Window API ShellExecute()实现打印文件的功能
	// ShellExecute()函数不仅可以实现打印磁盘文件的功能
	// 还可以直接运行磁盘中的可执行文件
	m_Path.GetWindowText(StrPath);
	::ShellExecute(NULL,"print",StrPath,"","",SW_HIDE);
}
