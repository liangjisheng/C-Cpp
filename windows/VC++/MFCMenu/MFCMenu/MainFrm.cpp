
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MFCMenu.h"

#include "MainFrm.h"

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
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, &CMainFrame::OnUpdateFileNew)
	ON_COMMAND(IDM_SHOW, &CMainFrame::OnShow)
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
	m_bAutoMenuEnable = FALSE;
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

	// 【文件】是一个子菜单，索引号为0，【文件】子菜单下的【新建】菜单项的索引号为0 
	// 对菜单来说，如果要访问某个菜单项，既可以通过该菜单项的标识ID，也可以通过其位置
	// 索引来实现访问。但对于子菜单来说，只能通过索引号进行访问，因为子菜单是没有标识号的

	// 有的菜单项上回打钩，称这种类型的菜单为标记菜单
	// 在框架窗口中，获取程序的菜单栏指针
	// CMenu* GetMenu() const;
	// CMenu是一个MFC类，是Windows菜单句柄HMENU的一个封装，提供了一些与菜单操作有关的成员函数
	// 获取一个菜单的子菜单，只能通过索引号获得子菜单
	// CMenu* GetSubMenu(int nPos) const;

	// 上面两个函数都返回执行CMenu对象的指针，GetMenu是CWnd的成员函数，返回指向程序菜单栏
	// 对象的指针；GetSubMenu是CMenu的成员函数，返回由pos指定的子菜单的指针

	// UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);
	// 第一个参数指定需要处理的菜单项，取值由第二个参数决定，
	// 第二个参数nCheck指定怎样设置菜单项，以及如何定位该菜单项的位置
	// MF_CHECKED,			设置菜单项的复选标记
	// MF_UNCHECKED,		移除菜单项的复选标记
	// MF_BYPOSITION,		根据菜单项的位置来访问菜单项，第一个参数是菜单项的索引号
	// MF_BYCOMMAND			根据菜单项的命令来访问菜单项，第一个参数是菜单项的命令ID

	// GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
	GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MF_CHECKED);

	// 有些应用程序的子菜单下有一个菜单项是以粗体形式显示的，以这种形式显示的就是该子菜单的
	// 默认菜单项，利用CMenu类的SetDefaultItem()成员函数完成默认菜单项的设置
	// BOOL SetDefaultItem(UINT uItem, BOOL fByPos = FALSE);
	// fByPos决定是通过菜单项索引还是通过菜单项的命令ID来访问菜单项
	// 把【文件】子菜单下面的【打开】菜单项设置为该子菜单的默认菜单项

	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);
	GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN, FALSE);

	// 一个子菜单只能有一个默认菜单项
	GetMenu()->GetSubMenu(0)->SetDefaultItem(5, TRUE);


	// BOOL SetMenuItemBitmaps(UINT nPosition, UINT nFlags, const CBitmap& pBmpUnchecked,
	//							const CBitmap* pBmpChecked);
	// 第一个参数的取值也是有第二个参数决定，与上面一样，
	// 第三个参数指定当取消菜单项选中状态时的位图，
	// 第四个参数指定选中菜单项时显示的位图，这样可以让菜单项显示两幅位图，
	// 来表明其选中和未选中状态
	// 不能把位图作为局部变量来使用，否则OnCreate()结束后，在程序中就看不到位图了

	// int GetSystemMetrics(int nIndex);
	// 只有一个参数，用来指定希望获取哪部分系统信息。当该参数的值为SM_CXMENUCHECK
	// 或者SM_CYMENUCHECK时，这个函数将获取标记菜单项上标记图形的默认尺寸

	/*CString str = _T("");
	str.Format(_T("x = %d, y = %d"), GetSystemMetrics(SM_CXMENUCHECK),
		GetSystemMetrics(SM_CYMENUCHECK));
	MessageBox(str, _T("title"), MB_OKCANCEL);
	m_bitmap.LoadBitmap(IDB_BITMAP1);
	GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmap, &m_bitmap);*/


	// 禁用菜单项，第一个参数也是由第二个参数决定，
	// MF_DISABLED,MF_ENABLED,MF_GRAYED
	// UINT EnableMenuItem(UINT nIDEnableItem, UINT nEnable);
	// 菜单的灰色显示与禁用状态是不同的，如果只设置了变灰，没有设置禁用，
	// 那这个菜单项还是可以使用的，一般把MF_DISABLED和MF_GRAYED放在一起
	// 但这么做并不是必须的

	// 一旦在CMainFrame类的构造函数中把成员变量m_bAutoMenuEnable设置为FALSE后，
	// 就不需要对ON_UPDATE_COMMAND_UI或ON_COMMAND消息进行响应了，CMenu类的
	// EnableMenuItem函数能够正常工作，实际上MFC为菜单提供了一种命令更新机制
	// 程序在运行时，根据此机制去判断那个菜单可以使用，那个菜单不能够使用，然后
	// 显示其相应的状态。默认情况下，所有菜单项的更新都是有MFC的命令更新机制完成的
	// 如果我们想自己更改菜单项的状态，那就必须把m_bAutoMenuEnable设置为FALSE
	// 之后，我们自己对菜单项的更新才能起作用，在构造函数中设置为FALSE
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

	// BOOL SetMenu(CMenu *pMenu);		参数为空的时候移除菜单
	SetMenu(NULL);

	// 在编程中，除了使用自动创建的主框架菜单外，还可以自己创建一个菜单资源并加载
	// 通过这种方式，可以实现动态更换程序菜单的功能
	// 下面的菜单对象是一个局部对象，调用OnCreate()函数之后就会消失，所以一点击
	// 菜单就会报异常，一种办法是将这个菜单对象定义成框架类的成员变量
	// 另一种方法是这个菜单对象仍为局部对象，但在调用SetMenu()把此对象设置成
	// 窗口的菜单之后，立即调用CMenu类的另一个成员函数Detach，以便把菜单句柄与
	// 这个菜单对象分离。

	// SetMenu会把菜单设置为其参数指定的新菜单，导致窗口重绘，以反映菜单的这种
	// 变化，同时也将该菜单对象的所有权交给窗口对象。而随后的Detach会把菜单句柄
	// 与这个菜单对象分离，这样当这个句柄菜单对象的生命周期结束时，它不会去销毁
	// 一个它不在具有拥有权的菜单。这个菜单在窗口销毁时自动销毁。
	CMenu me;
	me.LoadMenu(IDR_MAINFRAME);
	SetMenu(&me);
	me.Detach();

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


// UPDATE_COMMAND_UI消息的响应只能用于菜单项，不能用于永久显示的顶级菜单
// (即弹出式菜单)项目
// 当为某个菜单项添加了一个UPDATE_COMMAND_UI消息响应函数，MFC在后台所做的工作是:
// 当要显示菜单时，操作系统发出WM_INITMENUPOPUP消息，然后由窗口的基类如CFrameWnd
// 接管。它会创建一个CCmdUI对象，并与程序的第一个菜单项关联，调用该对象的一个成员
// 函数DoUpdate()。这个函数发出CN_UPDATE_COMMAND_UI消息，这条消息带有一个指向
// CCmdUI对象的指针。这是系统会判断是否存在一个ON_UPDATE_COMMAND_UI宏去捕获这个
// 菜单项消息，如果找到，就进行处理。当更新完第一个菜单项后，同一个CCmdUI对象就
// 设置为与第二个菜单项相关联，依次顺序进行，直到完成所有菜单项的处理
// 这就是MFC采用的命令更新机制。

void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	// Enable(),SetCheck(), SetText();	实现启用禁用菜单、设置标记、设置菜单项文本
	// virtual void Enable(BOOL bOn = TRUE);

	// CCmdUI类有一个m_nID成员变量，用于保存当前菜单项、工具栏按钮或者由其他CCmdUI
	// 对象表示的UI对象的标识，可以加上一个判断
	if(ID_FILE_NEW == pCmdUI->m_nID)
		pCmdUI->Enable(FALSE);
	// MFC调用菜单命令更新函数时，已经去确定了特定的菜单项，实际应用是无须判断，
	// 此处只是为了介绍知识

	// CCmdUI类还有一个成员变量m_nIndex;用来保存当前菜单项的位置索引
	// 菜单项和工具按钮的位置索引计算方式不同，为保证二者状态保持一致，最好采用
	// 菜单项标识或工具按钮标识方式来进行设置。
}


void CMainFrame::OnShow()
{
	MessageBox(_T("Main show"));
}
