// 1251Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1251.h"
#include "1251Dlg.h"

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
// CMy1251Dlg dialog

CMy1251Dlg::CMy1251Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1251Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1251Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1251Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1251Dlg)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1251Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1251Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GETTEXT, OnButtonGettext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1251Dlg message handlers

BOOL CMy1251Dlg::OnInitDialog()
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
	
//	m_Tree.Create(TVS_LINESATROOT | TVS_HASLINES | TVS_HASBUTTONS 
//		| WS_BORDER | LVS_SHOWSELALWAYS,CRect(0,0,0,0),this,10001);
//	m_Tree.MoveWindow(10,10,300,200);		// 设置控件显示位置
//	m_Tree.ShowWindow(SW_SHOW);

	m_ImageList.Create(32,32,ILC_COLOR24 | ILC_MASK,1,0);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));

	m_Tree.SetImageList(&m_ImageList,LVSIL_NORMAL);		// 关联图像列表
	HTREEITEM m_Root;		// 根节点
	m_Root = m_Tree.InsertItem("司令",0,0);		// 向根节点插入数据
	HTREEITEM m_Child;
	m_Child = m_Tree.InsertItem("将军甲",1,1,m_Root);	// 插入一个二级节点
	m_Tree.InsertItem("士兵甲",2,2,m_Child);		// 插入三级节点
	m_Tree.InsertItem("士兵乙",2,2,m_Child);
	m_Child = m_Tree.InsertItem("将军乙",1,1,m_Root);	// 插入二级节点
	m_Tree.InsertItem("士兵丙",2,2,m_Child);		// 插入三级节点
	m_Tree.InsertItem("士兵丁",2,2,m_Child);

	m_Tree.Expand(m_Root,TVE_EXPAND);			// 展开根节点
	m_StrText = "";
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1251Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1251Dlg::OnPaint() 
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
HCURSOR CMy1251Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1251Dlg::CheckToTree(HTREEITEM m_Item)
{
	m_Item = m_Tree.GetChildItem(m_Item);	// 获得当前节点的子节点
	while(m_Item != NULL)
	{
		if(m_Tree.GetCheck(m_Item))			// 判断当前节点复选框是否被选中
		{
			m_StrText += m_Tree.GetItemText(m_Item);	// 获得选中复选框的节点文本
			m_StrText += "\r\n";
		}
		CheckToTree(m_Item);		// 递归
		m_Item = m_Tree.GetNextItem(m_Item,TVGN_NEXT);	// 获得下一个节点
	}
}

void CMy1251Dlg::OnButtonGettext() 
{
	HTREEITEM item;
	item = m_Tree.GetRootItem();
	if(m_Tree.GetCheck(item))
	{
		m_StrText += m_Tree.GetItemText(item);	// 根节点文本
		m_StrText += "\r\n";
	}
	CheckToTree(item);
	MessageBox(m_StrText);
	m_StrText = "";		// 置空是为了再次点击，否则将会有重复的文本
}
