// 1241Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1241.h"
#include "1241Dlg.h"

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
// CMy1241Dlg dialog

CMy1241Dlg::CMy1241Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1241Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1241Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1241Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1241Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1241Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1241Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(1001,OnNumber1)
	ON_COMMAND(1002,OnNumber2)
	ON_COMMAND(1003,OnNumber3)
	ON_COMMAND(1005,OnNumber4)
	ON_COMMAND(1006,OnNumber5)
	ON_COMMAND(1007,OnNumber6)
	ON_COMMAND(1009,OnNumber7)
	ON_COMMAND(1011,OnNumber8)
	ON_NOTIFY_EX(TTN_NEEDTEXT,0,OnToolTipNotify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1241Dlg message handlers

BOOL CMy1241Dlg::OnInitDialog()
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
	
	m_ImageList.Create(32,32,ILC_COLOR24 | ILC_MASK,1,1);	// 创建图像列表
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));		// 向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	
	UINT array[11];
	for(int i=0;i<11;i++)
	{
		if(i==3 || i==7 || i==9)		// 判断是否为第4，第8，第10个按钮
			array[i]=ID_SEPARATOR;		// 第4,8，10个按钮为分隔条
		else
			array[i]=i+1001;
	}
	m_ToolBar.Create(this);				// 创建工具栏窗口
	// 激活工具栏提示功能
	m_ToolBar.EnableToolTips(TRUE);

	m_ToolBar.SetButtons(array,11);		// 设置工具栏按钮的索引
	m_ToolBar.SetButtonText(0,"Icon1");	// 设置工具栏按钮文本
	m_ToolBar.SetButtonText(1,"Icon2");
	m_ToolBar.SetButtonText(2,"Icon3");
	m_ToolBar.SetButtonText(4,"Icon4");
	m_ToolBar.SetButtonText(5,"Icon5");
	m_ToolBar.SetButtonText(6,"Icon6");
	m_ToolBar.SetButtonText(8,"Icon7");
	m_ToolBar.SetButtonText(10,"Icon8");
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);	// 关联图像列表
	m_ToolBar.SetSizes(CSize(40,40),CSize(32,32));	// 设置按钮和图标的大小
	// 显示工具栏
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1241Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1241Dlg::OnPaint() 
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
HCURSOR CMy1241Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1241Dlg::OnNumber1()
{
	MessageBox("1");
}

void CMy1241Dlg::OnNumber2()
{
	MessageBox("2");
}

void CMy1241Dlg::OnNumber3()
{
	MessageBox("3");
}

void CMy1241Dlg::OnNumber4()
{
	MessageBox("4");
}

void CMy1241Dlg::OnNumber5()
{
	MessageBox("5");
}

void CMy1241Dlg::OnNumber6()
{
	MessageBox("6");
}

void CMy1241Dlg::OnNumber7()
{
	MessageBox("7");
}

void CMy1241Dlg::OnNumber8()
{
	MessageBox("8");
}

BOOL CMy1241Dlg::OnToolTipNotify(UINT id,NMHDR* pNMHDR,LRESULT* pResult)
{
	TOOLTIPTEXT* pTTT=(TOOLTIPTEXT*)pNMHDR;
	UINT nID=pNMHDR->idFrom;					// 获取工具栏按钮ID
	if(nID)			// 判断ID按钮是否存在
	{
		UINT nIndex=m_ToolBar.CommandToIndex(nID);	// 根据ID获取按钮索引
		if(nIndex!=-1)	// 判断索引是否正确
		{
			m_ToolBar.GetButtonText(nIndex,m_TipText);	// 获取工具栏文本
			pTTT->lpszText = m_TipText.GetBuffer(m_TipText.GetLength());	// 设置提示信息文本
			pTTT->hinst=AfxGetResourceHandle();		// 获得资源句柄
			return TRUE;
		}
	}
	return FALSE;
}
