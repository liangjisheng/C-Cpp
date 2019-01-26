
// MainFrm.cpp : CMainFrame 类的实现
// 本程序实现了这样一个功能：在应用程序的窗口中，输入一行文字，这行文字的格式是
// 人名 电话号码。在这行文字输入完成按下回车键，就会在程序的菜单栏上的帮助菜单后
// 动态生成一个子菜单，并且刚才输入的人名将作为其中的一个菜单项来显示。然后可以继续
// 上述过程，接着在程序窗口中输入下一行文字，但这时按下回车键后，并不需要在新添一个
// 子菜单，而是直接在已添加的子菜单下添加菜单项，这个新菜单项的文本就是新输入的人名
// 当单击这个动态生成的子菜单中的某个菜单项时，程序就会把相应的人名和电话号码显示在
// 程序窗口上。

#include "stdafx.h"
#include "MFCMenu2.h"

#include "MainFrm.h"
#include "MFCMenu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	//ON_COMMAND(IDM_HELLO, OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//CMenu menu;
	//menu.CreateMenu();
	// BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	// nFlags指定新添加菜单项目的状态信息
	// MF_CHECKED,MF_UNCHECKED,MF_ENABLED,MF_DISABLED,MF_GRAYED,MF_OWNERDRAW,MF_POPUP
	// MF_SEPARATOR,MF_STRING,MF_MENUBREAK,MF_MENUBARBREAK
	// 第二个参数取决于第一个参数的只，如果第一个参数的值是MF_POPUP,那么nIDNewItem就是
	// 一个顶层菜单的句柄，否则就是要添加的新菜单项的命令ID，如果第一个参数的值是MF_SEPARATOR
	// 那么nIDNewItem的值被忽略
	// 第三个参数取值同样取决于第一个参数，如果第一个参数是MF_STRING,则lpszNewItem
	// 就是指向要添加的这个新菜单项目的文本的指针。如果第一个参数是MF_OWNERDRAW，则
	// lpszNewItem就是指向该菜单项目的一个附件数据的指针，如果第一个参数是MF_SEPARATOR
	// lpszNewItem将被忽略
	//GetMenu()->AppendMenu(MF_POPUP, (UINT)menu.m_hMenu, _T("test"));
	// 将菜单句柄与菜单对象之间的关联断开，或者可以让menu为CMainFrame类的
	// 成员变量
	//menu.Detach();


	//CMenu menu;
	//menu.CreateMenu();
	// 第一个菜单指定的是一个菜单命令标识，表示新菜单项将在这个标识所表示的菜单项之前
	// 插入
	//GetMenu()->InsertMenu(2, MF_POPUP | MF_BYPOSITION, (UINT)menu.m_hMenu, _T("test"));
	// 给子菜单添加菜单项
	//menu.AppendMenu(MF_STRING, IDM_HELLO, _T("hello"));
	//menu.AppendMenu(MF_STRING, 11112, _T("bye"));
	//menu.AppendMenu(MF_STRING, 11113, _T("mybole"));
	// 在文件子菜单下面添加一个菜单项
	//GetMenu()->GetSubMenu(0)->AppendMenu(MF_STRING, 11114, _T("welcome"));
	//menu.Detach();

	// BOOL DeleteMenu(UINT nPosition, UINT nFlags);
	// 删除一个菜单项目，包括子菜单以及子菜单下的菜单项，主要取决于调用这个函数的对象
	// 删除编辑子菜单
	//GetMenu()->DeleteMenu(1, MF_BYPOSITION);
	// 删除文件下面的菜单项
	//GetMenu()->GetSubMenu(0)->DeleteMenu(2, MF_BYPOSITION);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序
//void CMainFrame::OnHello()
//{
	//MessageBox(_T("hello"));
//}


// 让框架窗口类截获菜单命令消息。
// 当框架窗口类接受到一个消息时，它首先会把消息交给其子窗口去处理。
// 菜单命令是交由OnCommand函数来处理的，在这个函数中完成命令消息的路由。可以重写
// OnCommand，截获那些动态创建的菜单项的命令消息，让它们不在继续往下路由。
// 这样，在程序运行时，当菜单命令由程序框架类CFrameWnd的OnWndMsg函数交由OnCommand
// 函数后，因为其子类：CMainFrame类重写了这个OnCommand函数，菜单命令消息就会
// 先到子类的这个函数中报到。后者最后调用几类(即程序框架类：CFrameWnd)的OnCommand()
// 函数进行消息的路由。
// OnCommand函数是对所有的命令消息进行路由处理的，包括菜单、工具栏按钮，以及加速键
// 的命令消息。参数wParam低端的两个字节中放置的是发送当前消息的菜单项、工具项，或者
// 加速键的命令ID。LOWORD宏从给定的32位值中取得低端字，HIWORD宏从给定的32位值中
// 取得高端字

// CView* GetActiveView() const;

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类
	int MenuCmdID = LOWORD(wParam);
	CMFCMenu2View *pView = (CMFCMenu2View *)GetActiveView();
	if (MenuCmdID >= IDM_PHONE_1 &&
		MenuCmdID < IDM_PHONE_1 + pView->m_strArray.GetSize())
	{
		//MessageBox(_T("Main Frame"));
		// 创建与视图类相关联的设备描述表对象
		CClientDC dc(pView);
		dc.TextOut(0, 0, pView->m_strArray.GetAt(MenuCmdID - IDM_PHONE_1));
	}

	// CFrameWnd类的OnCommand函数继续消息路由，把消息传给视图类，如果视图类对
	// 此消息有响应，调用响应函数处理，消息路由结束。
	// 直接返回TRUE后，表示消息路由到CMainFrame后就结束了，不在继续往下传递，
	// 应用程序的视图类不会接受到此消息
	return TRUE;
	//return CFrameWnd::OnCommand(wParam, lParam);
}
