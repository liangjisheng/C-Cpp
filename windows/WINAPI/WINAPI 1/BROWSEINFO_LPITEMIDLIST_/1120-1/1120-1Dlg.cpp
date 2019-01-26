
// 1120-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "1120-1.h"
#include "1120-1Dlg.h"
#include "afxdialogex.h"

//#ifdef _DEBUG
//	#include "vld.h"
//#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int CALLBACK BrowseCallBackFun(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

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


CMy11201Dlg::CMy11201Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy11201Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy11201Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy11201Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11201Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy11201Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy11201Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy11201Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMy11201Dlg 消息处理程序

BOOL CMy11201Dlg::OnInitDialog()
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

void CMy11201Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy11201Dlg::OnPaint()
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
HCURSOR CMy11201Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy11201Dlg::OnBnClickedButton1()
{
	CString ReturnPath;
	TCHAR szPath[_MAX_PATH] = {0};			// 保存路径变量
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = GetSafeHwnd();			// HWND句柄	or bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;						// 设置开始搜索位置，为NULL默认从the desktop folder开始
	bi.lpszTitle =_T("Choose a directory");	// 显示位于对话框左上部的标题
	bi.pszDisplayName = szPath;				// 被选中的文件夹缓冲区地址
	bi.ulFlags = BIF_BROWSEINCLUDEFILES;	// 指定对话框的外观和功能的标志,BIF_BROWSEINCLUDEFILES表示文件也能被选中
	bi.lpfn = NULL;							// 处理事件的回调函数
	bi.lParam = NULL;						// 应用程序传给回调函数的参数
	bi.iImage = 0;							// 文件夹对话框的图片索引

	// SHBrowseForFolder用来显示一个让用户可以选择文件夹的对话框，
	// 返回值是指向选定的文件夹相对应于所选择根目录地址的路径标识符指针
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		// 将路径标识符指针转换为路径
		if(SHGetPathFromIDList(pItemIDList,szPath))	// 判断是否获得文件夹路径
			ReturnPath = szPath;					
	}
	else
		ReturnPath = "";	// 路径为空
	
	AfxMessageBox(ReturnPath);
}

int CALLBACK BrowseCallBackFun(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:	// 选择文件夹对话框初始化	
		// 设置默认路径
		::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);

		// 在STATUSTEXT区域显示当前路径
		::SendMessage(hwnd, BFFM_SETSTATUSTEXT, 0, lpData);

		// 设置选择文件夹对话框的标题
		::SetWindowText(hwnd, TEXT("请先设置个工作目录"));
		break;

	case BFFM_SELCHANGED:	// 选择文件夹变更时
		{
			TCHAR pszPath[MAX_PATH] = {0};
			// 获取当前路径
			SHGetPathFromIDList((LPCITEMIDLIST)lParam, pszPath);
			// 在STATUSTEXT区域中显示当前路径
			::SendMessage(hwnd, BFFM_SETSTATUSTEXT, TRUE, (LPARAM)pszPath);
		}
		break;
	}

	return 0;
}


void CMy11201Dlg::OnBnClickedButton2()
{
	CString ReturnPath = _T("");
	TCHAR szPath[_MAX_PATH] = {0};			// 保存路径变量
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = GetSafeHwnd();			// HWND句柄	or bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;						// 设置开始搜索位置，为NULL默认从the desktop folder开始
	bi.lpszTitle =_T("Choose a directory");	// 显示位于对话框左上部的标题
	bi.pszDisplayName = szPath;				// 被选中的文件夹缓冲区地址
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_USENEWUI;	// 指定对话框的外观和功能的标志,BIF_BROWSEINCLUDEFILES表示文件也能被选中
	bi.lpfn = BrowseCallBackFun;			// 处理事件的回调函数
	bi.lParam = (LPARAM)_T("D:\\");		// 应用程序传给回调函数的参数
	bi.iImage = 0;							// 文件夹对话框的图片索引

	// SHBrowseForFolder用来显示一个让用户可以选择文件夹的对话框，
	// 返回值是指向选定的文件夹相对应于所选择根目录地址的路径标识符指针
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		// 将路径标识符指针转换为路径
		if(SHGetPathFromIDList(pItemIDList,szPath))	// 判断是否获得文件夹路径
			ReturnPath = szPath;					
	}
	else
		ReturnPath = _T("");	// 路径为空

	AfxMessageBox(ReturnPath);
}


// 弹出指本地特殊指定的文件夹窗口，类似我们双击某个文件夹打开
//CSIDL_DRIVES是我的电脑
//CSIDL_BITBUCKET 回收站
//CSIDL_CONTROLS 控制面板
//CSIDL_DESKTOP Windows 桌面Desktop
//CSIDL_DESKTOPDIRECTORY Desktop的目录
//CSIDL_DRIVES 我的电脑
//CSIDL_FONTS 字体目录
//CSIDL_NETHOOD 网上邻居
//CSIDL_NETWORK 网上邻居虚拟目录
//CSIDL_PERSONAL 我的文档
//CSIDL_PRINTERS 打印机
//CSIDL_PROGRAMS 程序组
//CSIDL_RECENT 最近打开的文档
//CSIDL_SENDTO “发送到”菜单项
//CSIDL_STARTMENU 任务条启动菜单项
//CSIDL_STARTUP 启动目录
//CSIDL_TEMPLATES 文档模板
void CMy11201Dlg::OnBnClickedButton3()
{
	// 下面被注释掉的几句话好像并没有起作用，把注释打开得到的结果是一样的

	//LPMALLOC pMalloc;
	LPITEMIDLIST pidl;
	if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_DRIVES, &pidl)))
	{
		SHELLEXECUTEINFO sei;
		ZeroMemory(&sei, sizeof(sei));
		sei.cbSize = sizeof(sei);
		sei.fMask = SEE_MASK_IDLIST;
		sei.lpIDList = pidl;
		sei.lpVerb = _T("open");
		sei.hwnd = AfxGetMainWnd()->GetSafeHwnd();
		sei.nShow = BIF_RETURNONLYFSDIRS;
		ShellExecuteEx(&sei);

		//if (SUCCEEDED(SHGetMalloc(&pMalloc)))
		//{
		//	pMalloc->Free(pidl);
		//	pMalloc->Release();
		//}
	}
}

// 文件目录转成LPITEMIDLIST
void CMy11201Dlg::OnBnClickedButton4()
{
	// OpenDir(_T("C:\\"));
	OpenDir1(_T("D:\vs2010_projects"));
}

void CMy11201Dlg::OpenDir(LPTSTR pszPath)
{
	// 直接打开某个给定的目录
	LPITEMIDLIST pidl;
	LPMALLOC pMalloc;
	pidl = ParsePidlFromPath(pszPath);

	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei, sizeof(sei));
	sei.cbSize = sizeof(sei);
	sei.fMask = SEE_MASK_IDLIST;
	sei.lpIDList = pidl;
	sei.lpVerb = _T("open");
	sei.hwnd = AfxGetMainWnd()->GetSafeHwnd();
	sei.nShow = BIF_RETURNONLYFSDIRS;
	ShellExecuteEx(&sei);

	if (SUCCEEDED(SHGetMalloc(&pMalloc)))
	{
		pMalloc->Free(pidl);
		pMalloc->Release();
	}
}

void CMy11201Dlg::OpenDir1(LPTSTR pszPath)
{
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	TCHAR szName[MAX_PATH] = {0};
	bi.pidlRoot = ParsePidlFromPath(pszPath);
	bi.hwndOwner = GetSafeHwnd();
	bi.pszDisplayName = szName;
	bi.lpszTitle = _T("browse directory");
	bi.ulFlags = BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	if (NULL != pidl && SHGetPathFromIDList(pidl, szName))
		AfxMessageBox(szName);
	else
		AfxMessageBox(_T(""));
}

LPITEMIDLIST CMy11201Dlg::ParsePidlFromPath(LPTSTR pszPath)
{
	OLECHAR szOldChar[MAX_PATH] = {0};
	LPSHELLFOLDER IpsfDeskTop;
	LPITEMIDLIST lpifq;
	ULONG ulEaten, ulAttribs;
	HRESULT hres;

	SHGetDesktopFolder(&IpsfDeskTop);
	hres = IpsfDeskTop->ParseDisplayName(NULL, NULL, pszPath, &ulEaten, &lpifq, &ulAttribs);
	hres = IpsfDeskTop->Release();

	if (FAILED(hres))
		return NULL;
	return lpifq;
}
