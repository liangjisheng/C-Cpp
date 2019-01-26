
// 1123-2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "1123-2.h"
#include "1123-2Dlg.h"
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


CMy11232Dlg::CMy11232Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy11232Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy11232Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy11232Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMy11232Dlg 消息处理程序

BOOL CMy11232Dlg::OnInitDialog()
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

	// 可以使用GetProp和SetProp函数来查找已经启动的程序的窗口
	// 使用SetProp向窗口的属性表中添加字符串
	::SetProp(this->m_hWnd, _T("test"), (HANDLE)1);
	// 使用GetProp在窗口的属性表中查找字符串
	// ::GetProp(this->m_hWnd, _T("test"));
	EnsureOneInstance();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy11232Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy11232Dlg::OnPaint()
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
HCURSOR CMy11232Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CMy11232Dlg::EnsureOneInstance()
{
	m_hMutex = CreateMutex(NULL, FALSE, _T("AutoRun"));
	if (m_hMutex)
	{
		if (GetLastError() == 183 /*ERROR_ALREADY_EXISTS*/)
		{
			CloseHandle(m_hMutex);
			HWND hWndPrevious = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
			while (::IsWindow(hWndPrevious))
			{
				if (::GetProp(hWndPrevious, _T("test")))
				{
					if (::IsIconic(hWndPrevious))
					{
						::ShowWindow(hWndPrevious, SW_RESTORE);
						::SetForegroundWindow(hWndPrevious);
					}
					else
						::SetForegroundWindow(::GetLastActivePopup(hWndPrevious));

					return FALSE;
				} // if
				hWndPrevious = ::GetWindow(hWndPrevious, GW_HWNDNEXT);
			} // while
			return FALSE;
		}
	}

	return TRUE;
}

// BOOL SetProp（HWND hWnd，LPCTSTR lpString，HANDLE hData）
// 该函数在指定窗口的属性表中增加一个新项，或者修改一个现有项，如果指定的字符串不在
// 属性表中，那就增加该新的项，否则就用指定的句柄替换该字符串的前面的句柄

// HANDLE GetProp(HWND hWnd，LPCTSTR lpString);
// 该函数从给定的窗口的属性列表中检索数据句柄，给定的字符串标识了要检索的句柄
// 字符串和句柄必须已经添加到属性表中

// HANDLE RemoveProp(HWND hWnd，LPCTSTR lpString);
// 从指定窗口的属性表中删除一项，指定的字符串标识了要删除的项
