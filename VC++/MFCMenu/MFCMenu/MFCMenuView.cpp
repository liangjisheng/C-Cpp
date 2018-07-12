
// MFCMenuView.cpp : CMFCMenuView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCMenu.h"
#endif

#include "MFCMenuDoc.h"
#include "MFCMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenuView

IMPLEMENT_DYNCREATE(CMFCMenuView, CView)

BEGIN_MESSAGE_MAP(CMFCMenuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_SHOW, &CMFCMenuView::OnShow)
END_MESSAGE_MAP()

// CMFCMenuView 构造/析构

CMFCMenuView::CMFCMenuView()
{
	// TODO: 在此处添加构造代码

}

CMFCMenuView::~CMFCMenuView()
{
}

BOOL CMFCMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCMenuView 绘制

void CMFCMenuView::OnDraw(CDC* /*pDC*/)
{
	CMFCMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCMenuView 打印

BOOL CMFCMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCMenuView 诊断

#ifdef _DEBUG
void CMFCMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenuDoc* CMFCMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenuDoc)));
	return (CMFCMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenuView 消息处理程序


void CMFCMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu *pPopup = menu.GetSubMenu(0);
	ClientToScreen(&point);
	// TrackPopupMenu()函数中x和y参数都是屏幕坐标，而鼠标单击点出的坐标是客户区坐标
	// 所以需要上一行的转换
	// 拥有这个快捷菜单(也叫上下文菜单)的是视图类，所以响应时，只会在视图类里面查找
	// 如果想让主框架响应，则需要将此快捷菜单的所有者变成主框架类,下面两行代码修改
	// 快捷菜单的所有者，但此时视图不能对此快捷菜单项命令做出响应，消息才会传到主框架类
	// 否则还是视图响应菜单项
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, this->GetParent());
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		//point.x, point.y, this);

	CView::OnRButtonDown(nFlags, point);
}


void CMFCMenuView::OnShow()
{
	MessageBox(_T("View show"));
}
