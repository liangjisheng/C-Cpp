
// ListCtrl_2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrl_2.h"
#include "ListCtrl_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListCtrl_2Dlg dialog




CListCtrl_2Dlg::CListCtrl_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListCtrl_2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrl_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CListCtrl_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CListCtrl_2Dlg::OnNMClickList1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &CListCtrl_2Dlg::OnLvnColumnclickList1)
END_MESSAGE_MAP()


// CListCtrl_2Dlg message handlers

BOOL CListCtrl_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	test_listctrl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListCtrl_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CListCtrl_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CListCtrl_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListCtrl_2Dlg::test_listctrl()
{
	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle()
		| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);		// 全选和网格

	m_list.InsertColumn(0, _T("语言"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_list.InsertColumn(1, _T("2012.02排名"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_list.InsertColumn(2, _T("2011.02排名"), LVCFMT_CENTER, rect.Width() / 3, 2);

	m_list.InsertItem(0, _T("Java"));
	m_list.SetItemText(0, 1, _T("1"));
	m_list.SetItemText(0, 2, _T("1"));
	m_list.InsertItem(1, _T("C"));
	m_list.SetItemText(1, 1, _T("2"));
	m_list.SetItemText(1, 2, _T("2"));
	m_list.InsertItem(2, _T("C#"));
	m_list.SetItemText(2, 1, _T("3"));
	m_list.SetItemText(2, 2, _T("3"));
	m_list.InsertItem(3, _T("C++"));
	m_list.SetItemText(3, 1, _T("4"));
	m_list.SetItemText(3, 2, _T("4"));
}


void CListCtrl_2Dlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;

	CString strContent = _T("");
	NMLISTVIEW *pNMListView = (NMLISTVIEW *)pNMHDR;

	// 如果不是-1,说明有列表项被选择
	if(-1 != pNMListView->iItem)
	{
		// 获取被选择列表项第一个子项的文本
		strContent = m_list.GetItemText(pNMListView->iItem, 0);
		SetDlgItemText(IDC_EDIT1, strContent);
	}
}

static bool bSort = false;

// 排序回调函数,单击列标题时实现不同的排序，升序-降序-升序-降序
// 参数列表必须要有，否则编译不通过
static int CALLBACK SortFunction(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	// 点击列标题时，排序是随机的，不一定是升序还是降序
	bSort = !bSort;
	return bSort;
}

void CListCtrl_2Dlg::OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	m_list.SortItems(SortFunction, (LPARAM)(&m_list));

	*pResult = 0;
}
