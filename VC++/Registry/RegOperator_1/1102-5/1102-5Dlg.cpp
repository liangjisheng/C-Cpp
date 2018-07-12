
// 1102-5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1102-5.h"
#include "1102-5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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

CMy11025Dlg::CMy11025Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy11025Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy11025Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMy11025Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_READREG, &CMy11025Dlg::OnBnClickedButtonReadreg)
	ON_BN_CLICKED(IDC_BUTTON_READREG2, &CMy11025Dlg::OnBnClickedButtonReadreg2)
END_MESSAGE_MAP()

BOOL CMy11025Dlg::OnInitDialog()
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

	CRect rclistctrl;
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.GetClientRect(&rclistctrl);
	m_list.InsertColumn(0, _T("序号"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(1, _T("软件名"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(2, _T("显示名称"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(3, _T("发布者"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(4, _T("安装日期"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(5, _T("大小"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(6, _T("版本号"), LVCFMT_LEFT, rclistctrl.Width() / 8);
	m_list.InsertColumn(7, _T("语言"), LVCFMT_LEFT, rclistctrl.Width() / 8);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy11025Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy11025Dlg::OnPaint()
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
HCURSOR CMy11025Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CMy11025Dlg::AllRegKey(HKEY hKey, LPCTSTR szDesKeyItem)
{
	HKEY hSubKey;
	DWORD dwIndex = 0;
	long lResult;
	int i = 0;

	lResult = RegOpenKeyEx(hKey, szDesKeyItem, 0, KEY_READ, &hSubKey);
	if(ERROR_SUCCESS == lResult)
	{
		TCHAR szKeyName[256] = {0};
		DWORD cbName = 256 * sizeof(TCHAR);
		lResult = RegEnumKeyEx(hSubKey, dwIndex, szKeyName, &cbName, 0, NULL, NULL, NULL);
		while(lResult == ERROR_SUCCESS && lResult != ERROR_MORE_DATA)
		{
			OutputDebugString(szKeyName);
			OutputDebugString(_T("\r\n"));
			CString str;
			str.Format(_T("%d"), i);
			// m_list.InsertItem(i, _T(""));
			// m_list.SetItemText(i, 0, str);
			// m_list.SetItemText(i++, 1, szKeyName);

			i = m_list.InsertItem(i, str);	// 返回所在行号
			m_list.SetItemText(i++, 1, szKeyName);

			dwIndex = dwIndex + 1;		// 获取下个字段
			cbName = 256 * sizeof(TCHAR);
			lResult = RegEnumKeyEx(hSubKey, dwIndex, szKeyName, &cbName, 0, NULL, NULL, NULL);
		}

		RegCloseKey(hSubKey);
		return true;
	}

	RegCloseKey(hKey);
	return false;
}

void CMy11025Dlg::OnBnClickedButtonReadreg()
{
	m_list.DeleteAllItems();
	AllRegKey(HKEY_LOCAL_MACHINE, TEXT("SoftWare\\Microsoft\\Windows\\CurrentVersion\\Uninstall"));
}


bool CMy11025Dlg::AllRegKey2(HKEY hKey, LPCTSTR szDesKeyItem)
{
	HKEY hSubKey;
	DWORD dwIndex = 1;
	long lResult;

	lResult = RegOpenKeyEx(hKey, szDesKeyItem, 0, KEY_READ, &hSubKey);
	if(ERROR_SUCCESS == lResult)
	{
		int id = 1;							// 序号
		TCHAR s_name[256] = {0};			// 软件名
		TCHAR s_DisplayName[256] = {0};		// 显示名称
		TCHAR s_Publisher[256] = {0};		// 发布者
		TCHAR s_InstallDate[12] = {0};		// 安装日期
		DWORD s_EstimatedSize = 0;			// 最终大小
		TCHAR s_DisplayVersion[256] = {0};	// 版本
		DWORD s_LanguageID = 0;				// 语言ID
		DWORD cbName = 256 * sizeof(TCHAR);
		DWORD cbName2 = 0xffffffff;

		DWORD typeSZ = REG_SZ;				// SZ 注册表类型
		DWORD typeDWORD = REG_DWORD;		// DWORD 注册表类型

		lResult = RegEnumKeyEx(hSubKey, dwIndex, s_name, &cbName, 0, NULL, NULL, NULL);
		while(ERROR_SUCCESS == lResult && lResult != ERROR_MORE_DATA)
		{
			OutputDebugString(s_name);
			OutputDebugString(_T("\r\n"));
			CString str;
			str.Format(_T("%d"), id);
			id = m_list.InsertItem(id, str);
			m_list.SetItemText(id, 1, s_name);

			HKEY hItem;		// 下一级注册表句柄
			if(::RegOpenKeyEx(hSubKey, s_name, 0, KEY_READ, &hItem) == ERROR_SUCCESS)
			{
				// 提取下一级注册表程序的属性信息
				cbName = 256 * sizeof(TCHAR);
				if(::RegQueryValueEx(hItem, _T("DisplayName"), 0, &typeSZ, (LPBYTE)s_DisplayName, &cbName) == ERROR_SUCCESS)
					m_list.SetItemText(id, 2, s_DisplayName);

				cbName = 256 * sizeof(TCHAR);
				if(::RegQueryValueEx(hItem, _T("Publisher"), 0, &typeSZ, (LPBYTE)s_Publisher, &cbName) == ERROR_SUCCESS)
					m_list.SetItemText(id, 3, s_Publisher);

				cbName = 256 * sizeof(TCHAR);
				if(::RegQueryValueEx(hItem, _T("InstallDate"), 0, &typeSZ, (LPBYTE)s_InstallDate, &cbName) == ERROR_SUCCESS)
					m_list.SetItemText(id, 4, s_InstallDate);

				if(::RegQueryValueEx(hItem, _T("EstimatedSize"), 0, &typeDWORD, (LPBYTE)&s_EstimatedSize, &cbName2) == ERROR_SUCCESS)
				{
					// float f_Size = s_EstimatedSize / 1024.0;
					CString strSize;
					strSize.Format(_T("%u KB"), s_EstimatedSize);
					m_list.SetItemText(id, 5, strSize);
				}

				cbName = 256 * sizeof(TCHAR);
				if(::RegQueryValueEx(hItem, _T("DisplayVersion"), 0, &typeSZ, (LPBYTE)s_DisplayVersion, &cbName) == ERROR_SUCCESS)
					m_list.SetItemText(id, 6, s_DisplayVersion);

				cbName2 = 0xffffffff;
				if(::RegQueryValueEx(hItem, _T("Language"), 0, &typeDWORD, (LPBYTE)&s_LanguageID, &cbName2) == ERROR_SUCCESS)
				{
					// float f_Size = s_EstimatedSize / 1024.0;
					CString strLanguage;
					strLanguage.Format(_T("%u"), s_LanguageID);
					m_list.SetItemText(id, 7, strLanguage);
				}

				::RegCloseKey(hItem);		// 关闭二级注册表(程序属性信息)
			}

			dwIndex = dwIndex + 1;
			cbName = 256 * sizeof(TCHAR);
			cbName2 = 0xffffffff;
			s_EstimatedSize = 0;
			s_LanguageID = 0;
			lResult = RegEnumKeyEx(hSubKey, dwIndex, s_name, &cbName, 0, NULL, NULL, NULL);
			id++;
		}

		RegCloseKey(hSubKey);		// 关闭一级注册表(读取程序信息)
		return true;
	}

	RegCloseKey(hKey);
	return false;
}

void CMy11025Dlg::OnBnClickedButtonReadreg2()
{
	m_list.DeleteAllItems();
	AllRegKey2(HKEY_LOCAL_MACHINE, TEXT("SoftWare\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall"));
}
