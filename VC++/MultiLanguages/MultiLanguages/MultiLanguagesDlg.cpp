
// MultiLanguagesDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MultiLanguages.h"
#include "MultiLanguagesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


CMultiLanguagesDlg::CMultiLanguagesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMultiLanguagesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bRestartFlag = false;
}

void CMultiLanguagesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiLanguagesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMultiLanguagesDlg::OnBnClickedButton1)
	ON_COMMAND(ID_LANGUAGE_TRANS, &CMultiLanguagesDlg::OnLanguageTrans)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMultiLanguagesDlg 消息处理程序

BOOL CMultiLanguagesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMultiLanguagesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMultiLanguagesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMultiLanguagesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMultiLanguagesDlg::OnBnClickedButton1()
{
	static int s_iClickTime = 0;
	s_iClickTime++;
	CString str = _T("");
	CString strnum = _T("");
	str.LoadString(IDC_STATIC_STRING_SAMPLE);
	strnum.Format(_T("%d"), s_iClickTime);
	str = str + strnum;
	AfxMessageBox(str);
}


// 窗口在初始化时候就导入了资源文件，在通过SetThreadUILanguage更换了
// 线程语言后，窗口的资源并不会更改，必须要通过代码来重新装载资源
// 因为窗口中存在多种与线程本地语言相关的资源，因此
// 重新启动软件是一种较快捷的更新语言环境的方法。
void CMultiLanguagesDlg::OnLanguageTrans()
{
	// 读取当前线程语言，并根据当前线程语言进行语言切换
	// GetThreadLocale()这个函数在win7下是不管用的
	// LCID lcidNew = GetThreadLocale();
	LCID lcidNew = GetThreadUILanguage();
	if(LANG_ENGLISH == PRIMARYLANGID(LANGIDFROMLCID(lcidNew)))
		lcidNew = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT);
	else
		lcidNew = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);

	CFile file;
	file.Open(_T("Language.ini"), CFile::modeWrite | CFile::modeCreate | CFile::typeBinary);
	file.Write(&lcidNew, sizeof(lcidNew));
	file.Close();

	m_bRestartFlag = true;
	PostMessage(WM_CLOSE);
}


void CMultiLanguagesDlg::OnClose()
{
	if(m_bRestartFlag)
	{
		CString strFileName = _T("");
		GetModuleFileName(NULL, strFileName.GetBuffer(MAX_PATH), MAX_PATH);
		ShellExecute(NULL, _T(""), strFileName, NULL, NULL, SW_SHOWNORMAL);
		strFileName.ReleaseBuffer();
	}

	CDialogEx::OnClose();
}


// 与本地化相关的函数和类型如下：
// GetSystemDefaultLCID
// GetSystemDefaultLocaleName
// GetUserDefaultLCID
// GetUserDefaultLocaleName
// SetThreadLocale
// GetThreadLocale
// GetThreadUILanguage
// SetThreadUILanguage

// MAKELCID
// MAKELANGID
// LCIDToLocalName
// LocalNameToLCID
// LANGIDFROMLCID
// PRIMARYLANGID

// LCID
// LANGID
// LANG_CHINESE 0x04
// LANG_ENGLISH 0x09
