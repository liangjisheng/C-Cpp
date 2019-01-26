
// MFCMenu2View.cpp : CMFCMenu2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCMenu2.h"
#endif

#include "MFCMenu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenu2View

IMPLEMENT_DYNCREATE(CMFCMenu2View, CView)

BEGIN_MESSAGE_MAP(CMFCMenu2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE_1, &CMFCMenu2View::OnPhone1)
	ON_COMMAND(IDM_PHONE_2, &CMFCMenu2View::OnPhone2)
	ON_COMMAND(IDM_PHONE_3, &CMFCMenu2View::OnPhone3)
	ON_COMMAND(IDM_PHONE_4, &CMFCMenu2View::OnPhone4)
END_MESSAGE_MAP()

// CMFCMenu2View 构造/析构

CMFCMenu2View::CMFCMenu2View()
{
	// TODO: 在此处添加构造代码
	m_nIndex = -1;
	m_strLine = _T("");
}

CMFCMenu2View::~CMFCMenu2View()
{
}

BOOL CMFCMenu2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCMenu2View 绘制

void CMFCMenu2View::OnDraw(CDC* /*pDC*/)
{
	CMFCMenu2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCMenu2View 打印

BOOL CMFCMenu2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCMenu2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCMenu2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCMenu2View 诊断

#ifdef _DEBUG
void CMFCMenu2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenu2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenu2Doc* CMFCMenu2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenu2Doc)));
	return (CMFCMenu2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenu2View 消息处理程序


void CMFCMenu2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 当第一次按下回车的时候，动态创建子菜单
	CClientDC dc(this);
	if (0x0d == nChar)
	{
		if (0 == ++m_nIndex)
		{
			m_menu.CreatePopupMenu();
			GetParent()->GetMenu()->AppendMenu(MF_POPUP, (UINT)m_menu.m_hMenu, _T("PhoneBooks"));
			// 如果只有上面两行代码，那么随便敲几个字符，然后按下回车，发现菜单栏上
			// 并没有添加【PhoneBooks】子菜单，但当我们把鼠标移动到应该显示这个子菜单
			// 的位置时，或者程序窗口的尺寸发生变化之后，这个子菜单就出现了。
			// 先前在CMainFrame类的OnCreate()函数里进行的菜单操作会立即显示。这是
			// 因为CMainFrame类的OnCreate函数的作用是实现窗口的创建，也就是说，
			// 在调用OnCreate函数时，程序的窗口还未创建和显示，所以在这个函数中对
			// 窗口上菜单所做的修改会立即在程序界面上呈现出来。但在窗口创建并显示
			// 完成之后，在去修改程序菜单的内容，需要对菜单栏进行一次重绘操作才能
			// 显现修改的结果。CWnd类提供了一个DrawMenuBar()成员函数完成对菜单的
			// 重绘操作。
			// 菜单是属于框架窗口的，因此应该让框架类去重绘菜单栏。如果在视图类里
			// 重绘菜单栏是没有效果的
			GetParent()->DrawMenuBar();	// 重绘菜单
		}
		m_menu.AppendMenu(MF_STRING, IDM_PHONE_1 + m_nIndex, 
			m_strLine.Left(m_strLine.Find(_T(" "))));
		m_strArray.Add(m_strLine);
		m_strLine.Empty();				// 回车后清除字符串
		// 如果没有下面这行代码，在此输入的文字是在上次输入的文字之上显示的
		// 希望将上次显示的内容清除掉，在显示当前输入的文字。有多重方法可以
		// 实现窗口上文字的擦除，这里利用窗口重绘的方法来实现。CWnd类有一个
		// Invalidate()的成员函数，该函数的作用是让窗口的整个客户区无效，这样
		// 当下一条WM_PAINT消息发生时，窗口就会被更新
		// void Invalidate(BOOL bErase = TRUE);
		// 如果参数为TRUE，重绘时就会把窗口的背景擦除掉；否则保留窗口的背景。
		Invalidate();
	}
	else
	{
		m_strLine += (char)nChar;
		dc.TextOut(0, 0, m_strLine);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCMenu2View::OnPhone1()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(0));
}


void CMFCMenu2View::OnPhone2()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(1));
}


void CMFCMenu2View::OnPhone3()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(2));
}


void CMFCMenu2View::OnPhone4()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(3));
}
