// 1060Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1060.h"
#include "1060Dlg.h"
#include "ScoreDlg.h"

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
// CMy1060Dlg dialog

CMy1060Dlg::CMy1060Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1060Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1060Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1060Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1060Dlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1060Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1060Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STUDENT, OnStudent)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1060Dlg message handlers

BOOL CMy1060Dlg::OnInitDialog()
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
	// 创建列表控件的标题头
	CString strHeader[4]={"学号","课程号","成绩","学分"};
	for(int nCol=0;nCol<4;nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,80);
	GetDlgItem(IDC_CHANGE)->EnableWindow(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1060Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1060Dlg::OnPaint() 
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
HCURSOR CMy1060Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1060Dlg::OnStudent() 
{
	// TODO: Add your control notification handler code here
	CScoreDlg dlg;
	if(dlg.DoModal()!=IDOK) return;
	int nItem=m_ListCtrl.GetItemCount();
	m_ListCtrl.InsertItem(nItem,dlg.m_strStuNo);
	m_ListCtrl.SetItemText(nItem,1,dlg.m_strCourseNo);
	CString str;
	str.Format("%4.1lf",dlg.m_dScore);
	m_ListCtrl.SetItemText(nItem,2,str);
	str.Format("%4.1lf",dlg.m_dCredit);
	m_ListCtrl.SetItemText(nItem,3,str);
}

void CMy1060Dlg::OnChange() 
{
	// TODO: Add your control notification handler code here
	// 获取被选择的列表项的索引号
	POSITION pos;
	pos=m_ListCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL) {
		MessageBox("你还没有选中列表项"); return;
	}
	int nItem=m_ListCtrl.GetNextSelectedItem(pos);
	CScoreDlg dlg;
	dlg.m_strAddText="修改";
	dlg.m_strStuNo=m_ListCtrl.GetItemText(nItem,0);
	dlg.m_strCourseNo=m_ListCtrl.GetItemText(nItem,1);
	CString str=m_ListCtrl.GetItemText(nItem,2);
	dlg.m_dScore=(double)atof(str);
	str=m_ListCtrl.GetItemText(nItem,3);
	dlg.m_dCredit=(double)atof(str);
	if(dlg.DoModal()!=IDOK) return;
	UpdateData(false);
	m_ListCtrl.SetItemText(nItem,0,dlg.m_strStuNo);
	m_ListCtrl.SetItemText(nItem,1,dlg.m_strCourseNo);
	str.Format("%4.1lf",dlg.m_dScore);
	m_ListCtrl.SetItemText(nItem,2,str);
	str.Format("%4.1lf",dlg.m_dCredit);
	m_ListCtrl.SetItemText(nItem,3,str);
}

void CMy1060Dlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_CHANGE)->EnableWindow(true);
	*pResult = 0;
}

void CMy1060Dlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	// POSITION pos;
	/*pos=m_ListCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL) {
		MessageBox("没有选中列表项"); return;
	}*/
	for(int i=0;i<m_ListCtrl.GetItemCount();i++) {
		if(m_ListCtrl.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
			break;
	}
	m_ListCtrl.DeleteItem(i);
}
