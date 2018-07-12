
// TreeCtrl_1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "TreeCtrl_1.h"
#include "TreeCtrl_1Dlg.h"
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

CTreeCtrl_1Dlg::CTreeCtrl_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTreeCtrl_1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeCtrl_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_wndTree);
}

BEGIN_MESSAGE_MAP(CTreeCtrl_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &CTreeCtrl_1Dlg::OnNMDblclkTree1)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CTreeCtrl_1Dlg::OnNMClickTree1)
END_MESSAGE_MAP()


// CTreeCtrl_1Dlg message handlers

BOOL CTreeCtrl_1Dlg::OnInitDialog()
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

	InitTreeControl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTreeCtrl_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeCtrl_1Dlg::OnPaint()
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
HCURSOR CTreeCtrl_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTreeCtrl_1Dlg::InitTreeControl()
{
	CImageList *pILNormal = new CImageList;
	BOOL bs = pILNormal->Create(IDB_NORMAL, 16, 1, RGB(1, 0, 0));
	if(bs)
		m_wndTree.SetImageList(pILNormal, TVSIL_NORMAL);
	else
		AfxMessageBox(_T("asdf"));
	m_wndTree.SetItemHeight(20);		// 设置行高
	HTREEITEM hRoot = m_wndTree.InsertItem(_T("D:\\"), 0, 2);	// 插入目录
	ShowFile(_T("D:\\"), hRoot);
}


void CTreeCtrl_1Dlg::ShowFile(CString strPath, HTREEITEM hParent)
{
	if (m_wndTree.ItemHasChildren(hParent))		// 是否有子节点
		return;  

	CFileFind find;
	BOOL bRet = find.FindFile(strPath + _T("\\*.*"));
	while(bRet)  
	{  
		HTREEITEM hItem;  
		bRet = find.FindNextFileW();
		CString strName = find.GetFileName();
		if (!find.IsDots())  // 判断是否是.或者..目录
		{
			if (find.IsDirectory())  
				hItem=m_wndTree.InsertItem(strName, 0, 2, hParent);  
			else
				hItem=m_wndTree.InsertItem(strName, 1, 3, hParent);
			//保存路径  
			CString *pPath = new CString;  
			*pPath = find.GetFilePath();  
			m_wndTree.SetItemData(hItem, (DWORD)pPath);
		}  
	}  
	find.Close();//结束查找  
	m_wndTree.Expand(hParent,TVE_EXPAND);//展开根节点  
}


void CTreeCtrl_1Dlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	HTREEITEM hCurItem = m_wndTree.GetSelectedItem();
	if(NULL == hCurItem || hCurItem == m_wndTree.GetRootItem())
		return ;
	CString *path = (CString *)m_wndTree.GetItemData(hCurItem);
	ShowFile(*path, hCurItem);
	
	*pResult = 0;
}


void CTreeCtrl_1Dlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	/*HTREEITEM hCurItem = m_wndTree.GetSelectedItem();
	if(NULL == hCurItem || hCurItem == m_wndTree.GetRootItem())
		return ;
	CString *path = (CString *)m_wndTree.GetItemData(hCurItem);
	ShowFile(*path, hCurItem);*/
	
	*pResult = 0;
}
