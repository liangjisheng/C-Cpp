// 1261View.cpp : implementation of the CMy1261View class
//

#include "stdafx.h"
#include "1261.h"

#include "1261View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1261View

IMPLEMENT_DYNCREATE(CMy1261View, CView)

BEGIN_MESSAGE_MAP(CMy1261View, CView)
	//{{AFX_MSG_MAP(CMy1261View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_BLUE, OnUpdateBlue)
	ON_UPDATE_COMMAND_UI(ID_RED, OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_GREEN, OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_YELLOW, OnUpdateYellow)
	ON_UPDATE_COMMAND_UI(ID_ONE, OnUpdateOne)
	ON_UPDATE_COMMAND_UI(ID_TWO, OnUpdateTwo)
	ON_UPDATE_COMMAND_UI(ID_THREE, OnUpdateThree)
	ON_UPDATE_COMMAND_UI(ID_FOUR, OnUpdateFour)
	ON_UPDATE_COMMAND_UI(ID_SOLID, OnUpdateSolid)
	ON_UPDATE_COMMAND_UI(ID_DASHED, OnUpdateDashed)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_RED, OnRed)
	ON_COMMAND(ID_GREEN, OnGreen)
	ON_COMMAND(ID_BLUE, OnBlue)
	ON_COMMAND(ID_YELLOW, OnYellow)
	ON_COMMAND(ID_ONE, OnOne)
	ON_COMMAND(ID_TWO, OnTwo)
	ON_COMMAND(ID_THREE, OnThree)
	ON_COMMAND(ID_FOUR, OnFour)
	ON_COMMAND(ID_SOLID, OnSolid)
	ON_COMMAND(ID_DASHED, OnDashed)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1261View construction/destruction

CMy1261View::CMy1261View()
{
	// 在构造函数中完成第一条直线的颜色、粗细和样式的初始化
	IsFinished = false;
	CurLine.color = 0;		// 黑色
	CurLine.thick = 1;		// 粗细为一个像素
	CurLine.style = PS_SOLID;	// 样式为实线
}

CMy1261View::~CMy1261View()
{
}

BOOL CMy1261View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1261View drawing

void CMy1261View::OnDraw(CDC* pDC)
{
	CMy1261Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	CPen pen;
	CPen* pOldPen;
	CObList* list = &pDoc->list;
	if(IsFinished)
		list->AddTail((CObject*)new CLine(CurLine));
	POSITION p = list->GetHeadPosition();	// 链表头结点位置
	CLine* t;
	while(p)
	{
		t = (CLine*)list->GetNext(p);
		pen.CreatePen(t->style,t->thick,t->color);
		pOldPen = pDC->SelectObject(&pen);
		pDC->MoveTo(t->start);
		pDC->LineTo(t->end);
		pDC->SelectObject(pOldPen);
		pen.DeleteObject();
	}
	IsFinished = false;		// 避免重复向链表中加入同一直线
}

/////////////////////////////////////////////////////////////////////////////
// CMy1261View printing

BOOL CMy1261View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy1261View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy1261View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy1261View diagnostics

#ifdef _DEBUG
void CMy1261View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1261View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1261Doc* CMy1261View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1261Doc)));
	return (CMy1261Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1261View message handlers

void CMy1261View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CurLine.start = point;
	IsFinished = false;
	Invalidate();		// 重绘窗口
	
	CView::OnLButtonDown(nFlags, point);
}

void CMy1261View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CurLine.end = point;
	IsFinished = true;
	Invalidate();
	
	CView::OnLButtonUp(nFlags, point);
}

void CMy1261View::OnMouseMove(UINT nFlags, CPoint point) 
{

}

void CMy1261View::OnRed() 
{
	CurLine.color = RGB(255,0,0);
}

void CMy1261View::OnGreen() 
{
	CurLine.color = RGB(0,255,0);
}

void CMy1261View::OnBlue() 
{
	CurLine.color = RGB(0,0,255);	
}

void CMy1261View::OnYellow() 
{
	CurLine.color = RGB(255,255,0);	
}

void CMy1261View::OnOne() 
{
	CurLine.thick = 1;	
}

void CMy1261View::OnTwo() 
{
	CurLine.thick = 2;	
}

void CMy1261View::OnThree() 
{
	CurLine.thick = 3;	
}

void CMy1261View::OnFour() 
{
	CurLine.thick = 4;	
}

void CMy1261View::OnSolid() 
{
	CurLine.style = PS_SOLID;	
}

void CMy1261View::OnDashed() 
{
	CurLine.style = PS_DASHDOT;
}

void CMy1261View::OnUpdateBlue(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.color == RGB(0,0,255));
}

void CMy1261View::OnUpdateRed(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.color == RGB(255,0,0));	
}

void CMy1261View::OnUpdateGreen(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.color == RGB(0,255,0));	
}

void CMy1261View::OnUpdateYellow(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.color == RGB(255,255,0));
}

void CMy1261View::OnUpdateOne(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.thick == 1);
}

void CMy1261View::OnUpdateTwo(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.thick == 2);
}

void CMy1261View::OnUpdateThree(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.thick == 3);
}

void CMy1261View::OnUpdateFour(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.thick == 4);
}

void CMy1261View::OnUpdateSolid(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.style == PS_SOLID);
}

void CMy1261View::OnUpdateDashed(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(CurLine.style == PS_DASHDOT);
}
