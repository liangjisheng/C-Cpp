
// 0921-3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "0921-3.h"
#include "0921-3Dlg.h"
#include "afxdialogex.h"

#include <strsafe.h>		// for StringCchPrintf

#pragma comment(lib, "version.lib")

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
public:
	CString GetAppVersion(WCHAR *AppName);
	void ErrorExit(LPTSTR lpszFunction);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	CString ver = GetAppVersion(L"0921-3.exe");
	if(ver.IsEmpty()) return ;

	int pos = ver.ReverseFind(_T('.'));
	CString mainVer = ver.Left(pos);
	mainVer = _T("mainVer:") + mainVer;
	CString build = ver.Right(ver.GetLength() - pos - 1);
	build = _T("build:") + build;
	GetDlgItem(IDC_STATIC_VER)->SetWindowText(mainVer);
	GetDlgItem(IDC_STATIC_BUILD)->SetWindowText(build);
}

CString CAboutDlg::GetAppVersion(WCHAR *AppName)
{
	CString AppVersion = _T("");
	DWORD ResourceVersionInfoSize;
	DWORD JustAJunkVariable;
	WCHAR *VersionInfoPtr;

	struct LANGANDCODEPAGE
	{
		WORD wLanguage;
		WORD wCodePage;
	}*TranslationPtr;
	WCHAR *InformationPtr;
	UINT VersionInfoSize;
	WCHAR VersionValue[255];

	ResourceVersionInfoSize = GetFileVersionInfoSize(AppName, &JustAJunkVariable);
	if(0 != ResourceVersionInfoSize)
	{
		VersionInfoPtr = new WCHAR[ResourceVersionInfoSize];
		if(!GetFileVersionInfo(AppName, 0, ResourceVersionInfoSize, VersionInfoPtr))
		{
			ErrorExit((LPTSTR)L"GetFileVersionInfo");
			delete [] VersionInfoPtr;
			return NULL;
		}

		if(!VerQueryValue(VersionInfoPtr, L"VarFileInfo\\Translation", 
			(LPVOID*)&TranslationPtr, &VersionInfoSize))
		{
			ErrorExit((LPTSTR)L"VerQueryValue");
			delete [] VersionInfoPtr;
			return NULL;
		}

		// retrieve product version
		wsprintf(VersionValue, L"\\StringFileInfo\\%04x%04x\\ProductVersion",
			TranslationPtr[0].wLanguage, TranslationPtr[0].wCodePage);

		if(!VerQueryValue(VersionInfoPtr, VersionValue, (LPVOID*)&InformationPtr, &VersionInfoSize))
		{
			ErrorExit((LPTSTR)L"VerQueryValue");
			delete [] VersionInfoPtr;
			return NULL;
		}

		if(wcslen(InformationPtr) > 0)
			AppVersion = CString(InformationPtr);
		delete [] VersionInfoPtr;
		VersionInfoPtr = NULL;
	}
	return AppVersion;
}

void CAboutDlg::ErrorExit(LPTSTR lpszFunction)
{
	// Retrieve the system error message for the last-error code
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, 
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	// Display the error message and exit the process
	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));

	// StringCchPrintf是sprintf的一个替代品，它接受一个格式字符串和参数列表和返回一个格式化字符串。
	// HRESULT StringCchPrintf( LPTSTR pszDest, size_t cchDest, LPCTSTR pszFormat, ...);
	// ...同printf
	// 这个函数返回一个HRESULT，而不是像sprintf一样返回存储在其目标缓冲区的字节数
	// 我们强烈建议您使用SUCCEEDED和FAILED宏来测试这个函数的返回值
	// TCHARpszDest[30];
	// size_tcchDest=30;
	// LPCTSTRpszFormat=TEXT("%s%d+%d=%d.");
	// TCHAR*pszTxt=TEXT("Theansweris");
	// HRESULThr=StringCchPrintf(pszDest,cchDest,pszFormat,pszTxt,1,2,3);

	StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf),
		TEXT("%s failed with error %d: %s"),
		lpszFunction, dw, lpMsgBuf);

	MessageBox((LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

CMy09213Dlg::CMy09213Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy09213Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy09213Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy09213Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_VERSION, &CMy09213Dlg::OnBnClickedButtonVersion)
	ON_BN_CLICKED(IDC_BUTTON_MS_LS, &CMy09213Dlg::OnBnClickedButtonMsLs)
END_MESSAGE_MAP()


// CMy09213Dlg message handlers

BOOL CMy09213Dlg::OnInitDialog()
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

void CMy09213Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy09213Dlg::OnPaint()
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
HCURSOR CMy09213Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy09213Dlg::OnBnClickedButtonVersion()
{
	// THIS_FILE和__FILE__表示的是同样的文件
	char *p = THIS_FILE;
	char *p1 = __FILE__;

	CString strFileVersion = _T("");
	CString strProductVersion = _T("");
	GetVersion(strFileVersion, strProductVersion);
	AfxMessageBox(strFileVersion);
	AfxMessageBox(strProductVersion);
}

void CMy09213Dlg::GetVersion(CString &strFileVersion, CString &strProductVersion)
{
	CString strExePath = _T("");
	GetModuleFileName(NULL, strExePath.GetBufferSetLength(MAX_PATH), MAX_PATH);
	strExePath.ReleaseBuffer();

	// 获得版本信息资源长度
	DWORD dwHandle = 0;
	// 用于判读系统能否检索到指定文件的版本信息，如果可以返回版本信息的字节大小
	// 否则返回0.第一个参数是文件名或者全路径,函数将第二个变量设为0，实际没什么用
	DWORD dwInfoSize = GetFileVersionInfoSize((LPCTSTR)strExePath, &dwHandle);
	if(dwInfoSize == 0)
		return ;

	TCHAR *pBlock = new TCHAR[dwInfoSize];
	// 用来获得指定文件的版本信息，第一个参数为文件名或全路径,第二个参数保留
	// 第三个参数表示缓冲区的大小,第四个参数指向缓冲区的指针
	GetFileVersionInfo((LPCTSTR)strExePath, dwHandle, dwInfoSize, pBlock);

	// 获得生成文件使用的代码页及文件版本
	unsigned int uTranslate = 0;
	struct LANGANDCODEPAGE
	{
		WORD wLanguage;
		WORD wCodePage;
	}*lpTranslate;

	// 获取文件的翻译表
	VerQueryValue(pBlock, _T("\\VarFileInfo\\Translation"), 
		(LPVOID*)&lpTranslate, &uTranslate);
	void *lpBuffer = NULL;
	UINT dwBytes = 0;

	// Read the file description for each language and code page.
	for(UINT i = 0; i < (uTranslate/ sizeof(struct LANGANDCODEPAGE)); i++)
	{
		TCHAR cSubBlock[200] = {0};
		_stprintf(cSubBlock, _T("\\StringFileInfo\\%04x%04x\\FileVersion"),
			lpTranslate[i].wLanguage,
			lpTranslate[i].wCodePage);
		// 获取文件的字符串信息
		VerQueryValue(pBlock, cSubBlock, &lpBuffer, &dwBytes);
		strFileVersion += (const TCHAR*)lpBuffer;
	}

	TCHAR szSubBlock[200] = {0};
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\ProductVersion"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	strProductVersion = (const TCHAR *)lpBuffer;

	CString str = _T("");
	wmemset(szSubBlock, 0, lstrlen(szSubBlock));
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\FileDescription"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	str = (const TCHAR *)lpBuffer;
	// AfxMessageBox(str);

	str = _T("");
	wmemset(szSubBlock, 0, lstrlen(szSubBlock));
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\CompanyName"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	str = (const TCHAR *)lpBuffer;
	// AfxMessageBox(str);

	str = _T("");
	wmemset(szSubBlock, 0, lstrlen(szSubBlock));
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\InternalName"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	str = (const TCHAR *)lpBuffer;
	// AfxMessageBox(str);

	str = _T("");
	wmemset(szSubBlock, 0, lstrlen(szSubBlock));
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\LegalCopyright"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	str = (const TCHAR *)lpBuffer;
	// AfxMessageBox(str);

	str = _T("");
	wmemset(szSubBlock, 0, lstrlen(szSubBlock));
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\OriginalFilename"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	str = (const TCHAR *)lpBuffer;
	// AfxMessageBox(str);

	str = _T("");
	wmemset(szSubBlock, 0, lstrlen(szSubBlock));
	_stprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\ProductName"),
		lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);
	VerQueryValue(pBlock, szSubBlock, &lpBuffer, &dwBytes);
	str = (const TCHAR *)lpBuffer;
	AfxMessageBox(str);

	delete [] pBlock;
	pBlock = NULL;
}

void CMy09213Dlg::OnBnClickedButtonMsLs()
{
	
}
