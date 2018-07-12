
// ListCtrl_3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrl_3.h"
#include "ListCtrl_3Dlg.h"
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


// CListCtrl_3Dlg dialog




CListCtrl_3Dlg::CListCtrl_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListCtrl_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrl_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_wndStyle);
	DDX_Control(pDX, IDC_LIST1, m_wndList);
}

BEGIN_MESSAGE_MAP(CListCtrl_3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CListCtrl_3Dlg::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CListCtrl_3Dlg::OnBnClickedButtonDelete)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CListCtrl_3Dlg::OnCbnSelchangeCombo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CListCtrl_3Dlg::OnNMDblclkList1)
END_MESSAGE_MAP()


// CListCtrl_3Dlg message handlers

BOOL CListCtrl_3Dlg::OnInitDialog()
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

	InitListCtrl();
	m_wndStyle.AddString(_T("图标(ICON)"));
	m_wndStyle.AddString(_T("小图标(SMALL ICON)"));
	m_wndStyle.AddString(_T("列表(LIST)"));
	m_wndStyle.AddString(_T("报表(REPORT)"));
	m_wndStyle.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListCtrl_3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListCtrl_3Dlg::OnPaint()
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
HCURSOR CListCtrl_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListCtrl_3Dlg::OnBnClickedButtonSelect()
{
	POSITION pos = m_wndList.GetFirstSelectedItemPosition();
	while(pos)
	{
		int nItem = m_wndList.GetNextSelectedItem(pos);
		MessageBox(m_wndList.GetItemText(nItem, 0));
	}
}

void CListCtrl_3Dlg::OnBnClickedButtonDelete()
{
	POSITION pos = m_wndList.GetFirstSelectedItemPosition();
	while(pos)
	{
		int nItem = m_wndList.GetNextSelectedItem(pos);
		m_wndList.DeleteItem(nItem);
		OnCbnSelchangeCombo1();
		// m_wndList.Invalidate();
		// MessageBox(m_wndList.GetItemText(nItem, 0));
	}
}


void CListCtrl_3Dlg::InitListCtrl()
{
	// 设置控件的图标列表
	CImageList *pILNormal = new CImageList;
	pILNormal->Create(IDB_NORMAL, 32, 1, RGB(0, 0, 0));
	m_wndList.SetImageList(pILNormal, LVSIL_NORMAL);
	// 设置控件的小图标
	CImageList *pILSmall = new CImageList;
	pILSmall->Create(IDB_SMALL, 18, 1, RGB(0, 0, 255));
	m_wndList.SetImageList(pILSmall, LVSIL_SMALL);

	// 设置风格
	m_wndList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 设置列
	m_wndList.InsertColumn(0, _T("名称"), LVCFMT_LEFT, 150);
	m_wndList.InsertColumn(1, _T("大小"), LVCFMT_LEFT, 80);
	m_wndList.InsertColumn(2, _T("类型"), LVCFMT_LEFT, 80);
	m_wndList.InsertColumn(3, _T("修改日期"), LVCFMT_LEFT, 100);

	// 插入测试数据
	m_wndList.InsertItem(0, _T("文件"), 0);
	m_wndList.SetItemText(0, 1, _T("15"));
	m_wndList.SetItemText(0, 2, _T("文件"));
	m_wndList.SetItemText(0, 3, _T("2012-03-06"));

	m_wndList.InsertItem(1, _T("文件夹"), 1);
	m_wndList.SetItemText(1, 1, _T("12"));
	m_wndList.SetItemText(1, 2, _T("文件夹"));
	m_wndList.SetItemText(1, 3, _T("2011-03-06"));

	// 设置空间背景色
	m_wndList.SetBkColor(RGB(200, 200, 200));
	m_wndList.SetTextBkColor(RGB(255, 0, 0));
	m_wndList.SetTextBkColor(CLR_NONE);

	// 设置控件的背景图片
	m_wndList.SetBkImage(_T("res\\icon1.ico"));
}


void CListCtrl_3Dlg::OnCbnSelchangeCombo1()
{
	int nSel = m_wndStyle.GetCurSel();
	switch(nSel)
	{
	case 0:	// 图标
		m_wndList.ModifyStyle(LVS_SMALLICON | LVS_LIST | LVS_REPORT, LVS_ICON);
		break;
	case 1: // 小图标
		m_wndList.ModifyStyle(LVS_ICON | LVS_LIST | LVS_REPORT, LVS_SMALLICON);
		break;
	case 2: // 列表
		m_wndList.ModifyStyle(LVS_SMALLICON | LVS_ICON | LVS_REPORT, LVS_LIST);
		break;
	case 3: // 报表
		m_wndList.ModifyStyle(LVS_ICON | LVS_LIST | LVS_SMALLICON, LVS_REPORT);
		break;
	}
}


void CListCtrl_3Dlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	int nSel = pNMItemActivate->iItem;
	if(-1 != nSel)
	{
		CString *path = (CString*)m_wndList.GetItemData(nSel);
		//if(!path)
			//*path = _T("");
		// AfxMessageBox(*path);
		if(path)
			ShowFile(*path + _T("\\*.*"));
	}
	
	*pResult = 0;
}


void CListCtrl_3Dlg::ShowFile(CString strPath)
{
	m_wndList.DeleteAllItems();			// 清空数据
	int nIndex = 0;
	CFileFind find;
	BOOL bRet = find.FindFile(strPath + _T("*.*"));
	while(bRet)
	{
		bRet = find.FindNextFile();
		if(find.IsDirectory())
		{
			m_wndList.InsertItem(nIndex, find.GetFileName(), 0);
			m_wndList.SetItemText(nIndex, 2, _T("文件夹"));
		}
		else
		{
			m_wndList.InsertItem(nIndex, find.GetFileName(), 1);
			DWORD nLen = find.GetLength();
			CString strLen = _T("");
			strLen.Format(_T("%d"), nLen);
			m_wndList.SetItemText(nIndex, 1, strLen);
		}
		CString *pPath = new CString;
		*pPath = find.GetFilePath();
		m_wndList.SetItemData(nIndex, (DWORD)pPath);
		nIndex++;
	}
	find.Close();	// 结束查找
}

