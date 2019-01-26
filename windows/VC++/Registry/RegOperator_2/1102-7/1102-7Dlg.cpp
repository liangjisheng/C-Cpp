
// 1102-7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1102-7.h"
#include "1102-7Dlg.h"
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

CMy11027Dlg::CMy11027Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy11027Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy11027Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy11027Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_READ, &CMy11027Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_WRITE, &CMy11027Dlg::OnBnClickedButtonWrite)
	ON_BN_CLICKED(IDC_BUTTON_WRITE1, &CMy11027Dlg::OnBnClickedButtonWrite1)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy11027Dlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_DELETEKEY, &CMy11027Dlg::OnBnClickedButtonDeletekey)
END_MESSAGE_MAP()


// CMy11027Dlg message handlers

BOOL CMy11027Dlg::OnInitDialog()
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

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy11027Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy11027Dlg::OnPaint()
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
HCURSOR CMy11027Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy11027Dlg::OnBnClickedButtonRead()
{
	HKEY hkey;
	LPCTSTR data_set = _T("SoftWare\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{002D9D5E-29BA-3E6D-9BC4-3D7D6DBC735C}");
	if(ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_set, 0, KEY_READ, &hkey))
	{
		DWORD dwValue;
		DWORD dwSize = sizeof(DWORD);
		DWORD dwType = REG_DWORD;
		if(::RegQueryValueEx(hkey, _T("EstimatedSize"), 
			0, &dwType, (LPBYTE)&dwValue, &dwSize) == ERROR_SUCCESS)
		{
			CString str;
			str.Format(_T("%u"), dwValue);
			str = _T("EstimatedSize: ") + str;
			GetDlgItem(IDC_EDIT_READVALUE)->SetWindowText(str);
		}
		else
			GetDlgItem(IDC_EDIT_READVALUE)->SetWindowText(_T("RegQueryValueEx error"));
	}
	else
		GetDlgItem(IDC_EDIT_READVALUE)->SetWindowText(_T("RegOpenKeyEx error"));
}


void CMy11027Dlg::OnBnClickedButtonWrite()
{
	HKEY hkey, hTempKey;
	DWORD dwValue = 6;
	DWORD dwSize = sizeof(DWORD);
	DWORD dwType = REG_DWORD;

	// LPCTSTR data_set = _T("SoftWare\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{002D9D5E-29BA-3E6D-9BC4-3D7D6DBC735C}");
	LPCTSTR data_set = _T("SOFTWARE");
	if(ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_SET_VALUE, &hkey))
	{
		// 使用hkey来操作data_set这个key里面的值
		if(ERROR_SUCCESS == ::RegCreateKey(hkey, _T("liangjisheng"), &hTempKey))
		{
			if(ERROR_SUCCESS != 
				::RegSetValueEx(hTempKey, _T("Name"), 0, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)))
			{
				AfxMessageBox(_T("error"));
				::RegCloseKey(hkey);
				return ;
			}
		}
	}

	::RegCloseKey(hkey);
	AfxMessageBox(_T("ok"));
}


void CMy11027Dlg::OnBnClickedButtonWrite1()
{
	HKEY hkey;
	HKEY hTempKey;
	char* name_set = "China";
	DWORD length = strlen(name_set) + 1;

	LPCTSTR data_set = _T("SoftWare");
	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set,0,KEY_SET_VALUE, &hkey))
	{
		if (ERROR_SUCCESS == ::RegCreateKey(hkey, _T("test111"), &hTempKey))
		{
			if (ERROR_SUCCESS != ::RegSetValueEx(hTempKey, _T("Name"), 0, REG_SZ, (LPBYTE)name_set, length))
			{
				AfxMessageBox(_T("error"));
				::RegCloseKey(hkey);
				return ;
			}
		}
	}

	AfxMessageBox(_T("ok"));
	::RegCloseKey(hkey);
}


void CMy11027Dlg::OnBnClickedButtonDelete()
{
	HKEY hkey;
	LPCTSTR data_set = _T("SoftWare\\test111");
	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set,0,KEY_SET_VALUE, &hkey))
	{
		if(ERROR_SUCCESS != ::RegDeleteValue(hkey, _T("Name")))
		{
			AfxMessageBox(_T("Error"));
			::RegCloseKey(hkey);
			return ;
		}
	}

	::RegCloseKey(hkey);
	AfxMessageBox(_T("ok"));
}


void CMy11027Dlg::OnBnClickedButtonDeletekey()
{
	HKEY hkey;
	LPCTSTR data_set = _T("SoftWare");
	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set,0,KEY_SET_VALUE, &hkey))
	{
		if(ERROR_SUCCESS != ::RegDeleteKey(hkey, _T("test111")))
		{
			AfxMessageBox(_T("error"));
			::RegCloseKey(hkey);
			return ;
		}
	}

	AfxMessageBox(_T("ok"));
	::RegCloseKey(hkey);
}
