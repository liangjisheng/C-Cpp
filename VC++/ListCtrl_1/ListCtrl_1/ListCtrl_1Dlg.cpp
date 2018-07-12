
// ListCtrl_1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrl_1.h"
#include "ListCtrl_1Dlg.h"
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


// CListCtrl_1Dlg dialog




CListCtrl_1Dlg::CListCtrl_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListCtrl_1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrl_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TEST, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CListCtrl_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_TEST_1, &CListCtrl_1Dlg::OnBnClickedTest1)
	ON_BN_CLICKED(IDC_BUTTON_TEST_2, &CListCtrl_1Dlg::OnBnClickedButtonTest2)
	ON_BN_CLICKED(IDC_RADIO_ALL_SEL, &CListCtrl_1Dlg::OnBnClickedRadioAllSel)
	ON_BN_CLICKED(IDC_RADIO_REVERSE_SEL, &CListCtrl_1Dlg::OnBnClickedRadioReverseSel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_TEST, &CListCtrl_1Dlg::OnNMCustomdrawListTest)
END_MESSAGE_MAP()


// CListCtrl_1Dlg message handlers

BOOL CListCtrl_1Dlg::OnInitDialog()
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

	/*CRect rc;
	GetClientRect(&rc);
	rc.top += 50;
	rc.right -= 50;
	m_ListCtrl.Create(0, rc, this, IDC_LIST_TEST);*/

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListCtrl_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListCtrl_1Dlg::OnPaint()
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
HCURSOR CListCtrl_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListCtrl_1Dlg::OnBnClickedTest1()
{
	// LVS_EX_CHECKBOXES每行最前面带个复选框
	// LVS_EX_HEADERDRAGDROP列表头可以拖动

	// 整行选择，网格线
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	// m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	// m_ListCtrl.SetExtendedStyle(LVS_EX_CHECKBOXES);
	// m_ListCtrl.SetExtendedStyle(LVS_EX_HEADERDRAGDROP);

	// m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_LEFT, 0);
	// LVCFMT_LEFT(左对齐),LVCFMT_CENTER(居中),LVCFMT_LEFT(右对齐)
	// 第4个参数表示这一列的宽度，nSubItem子项的索引与列(一般默认，不用填)
	m_ListCtrl.InsertColumn(0, _T("name"), LVCFMT_LEFT, 100);	// 第二列列名
	m_ListCtrl.InsertColumn(1, _T("age"), LVCFMT_LEFT, 100);	// 第三列列名
	m_ListCtrl.InsertColumn(2, _T("sex"), LVCFMT_LEFT, 100);	// 第四列列名

	CString strName = _T("");
	CString strAge = _T("");
	CString strSex = _T("");
	for(int i = 0; i <= 7; i++)
	{
		strName.Format(_T("test_%d"), i);
		strAge.Format(_T("%d"), 20 + i);
		strSex = i % 2 ? _T("M") : _T("F");
		m_ListCtrl.InsertItem(i, _T(""));			// 插入行
		m_ListCtrl.SetItemText(i, 0, strName);		// 第二列文本
		m_ListCtrl.SetItemText(i, 1, strAge);		// 第三列文本
		m_ListCtrl.SetItemText(i, 2, strSex);		// 第四列文本
	}

	// 上面的第170行代码，把列表的第一列的宽度设置成了0，而SetItemText()的时候
	// 第1列的数据也是没有插入。这是因为：列表控件的第一列好像是叫虚列，
	// 当大数据的时候好像能够利用这个加快速度什么的，具体不是很清楚
	// 但就是因为这个原因，发现第一列无法设置里面的文本居中对齐！！！
	// 即使设置成居中，仍然是左对齐的效果.为了能够居中的显示，这里就放弃了第一列
	// 不过，如果是要显示图片的，或者是有CheckBox的列表，一定要有这个虚列，
	// 不然图片和CheckBox就无法显示了。如果仅仅是简单的文字，
	// 这样可以达到第一列居中的效果。
}


void CListCtrl_1Dlg::OnBnClickedButtonTest2()
{
	m_ListCtrl.m_if_hotLine = true;
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	// m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_LEFT, 0);
	m_ListCtrl.InsertColumn(0, _T("name"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(1, _T("age"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(2, _T("sex"), LVCFMT_LEFT, 100);

	CString strName = _T("");
	CString strAge = _T("");
	CString strSex = _T("");
	for(int i = 0; i <= 7; i++)
	{
		strName.Format(_T("second_%d"), i);
		strAge.Format(_T("%d"), 20 + i);
		strSex = i % 2 ? _T("M") : _T("F");
		m_ListCtrl.InsertItem(i, _T(""));
		m_ListCtrl.SetItemText(i, 0, strName);
		m_ListCtrl.SetItemText(i, 1, strAge);
		m_ListCtrl.SetItemText(i, 2, strSex);
	}
}


void CListCtrl_1Dlg::OnBnClickedRadioAllSel()
{
	for(int i = 0; i < m_ListCtrl.GetItemCount(); i++)
	{
		// 设置复选框打钩
		m_ListCtrl.SetCheck(i, TRUE);
		// 设置某一行的状态是否选中
		m_ListCtrl.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
	}
}


void CListCtrl_1Dlg::OnBnClickedRadioReverseSel()
{
	BOOL bState = FALSE;
	for(int i = 0; i < m_ListCtrl.GetItemCount(); i++)
	{
		bState = m_ListCtrl.GetCheck(i);
		if(!bState)
		{
			m_ListCtrl.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
			m_ListCtrl.SetCheck(i, TRUE);
		}
		else
		{
			m_ListCtrl.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);
			m_ListCtrl.SetCheck(i, FALSE);
		}
	}
}


void CListCtrl_1Dlg::OnNMCustomdrawListTest(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	//int nItemIndex = pNMCD->dwItemSpec;
	//if(pNMCD->dwDrawStage == CDDS_PREPAINT)
	//	*pResult = CDRF_NOTIFYITEMDRAW;
	//else if(pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	//{
	//	// 选中行(鼠标选中的行)
	//	if(m_ListCtrl.GetItemState(nItemIndex, LVIS_SELECTED) == LVIS_SELECTED)
	//	{
	//		pNMCD->uItemState = ~CDIS_SELECTED;
	//	}
	//}
	
	*pResult = 0;
}
