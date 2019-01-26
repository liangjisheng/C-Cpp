// 1031Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1031.h"
#include "1031Dlg.h"

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
// CMy1031Dlg dialog

CMy1031Dlg::CMy1031Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1031Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1031Dlg)
	m_addstr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1031Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1031Dlg)
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_TEXTADD, m_addstr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1031Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1031Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_ADDNUM, OnAddnum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1031Dlg message handlers

BOOL CMy1031Dlg::OnInitDialog()
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
	// 为组合框控件添加列表项
	m_combo.AddString(_T("zhao"));
	m_combo.AddString(_T("qian"));
	m_combo.AddString(_T("sun"));
	m_combo.AddString(_T("li"));
	// 在索引为1的位置插入列表项
	m_combo.InsertString(1,_T("lishuyu"));
	// 默认选择第一项
	m_combo.SetCurSel(0);
	// SetDlgItemText(IDC_EDIT1,_T("zhao"));
	// 消除组合框中现有的内容
	((CComboBox*)GetDlgItem(IDC_COMBO1))->ResetContent();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1031Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1031Dlg::OnPaint() 
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
HCURSOR CMy1031Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1031Dlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	int nSel;
	// 获取组合框控件的列表框中选中项的索引
	nSel=m_combo.GetCurSel();
	// 根据索引获取字符串
	m_combo.GetLBText(nSel,str);
	// 显示文本
	SetDlgItemText(IDC_EDIT1,str);
}

void CMy1031Dlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_TEXTADD,m_addstr);
	m_combo.AddString(m_addstr);
	m_combo.SetCurSel(m_combo.GetCount()-1);
	SetDlgItemText(IDC_EDIT1,m_addstr);
}

void CMy1031Dlg::OnAddnum() 
{
	// TODO: Add your control notification handler code here
	CString strnum;
	for(int i=0;i<10;i++) {
		strnum.Format("%d",i);
		m_combo.AddString(strnum);
	}
}
