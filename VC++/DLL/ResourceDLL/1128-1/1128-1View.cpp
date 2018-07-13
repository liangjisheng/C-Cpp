
// 1128-1View.cpp : implementation of the CMy11281View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "1128-1.h"
#endif

#include "1128-1Doc.h"
#include "1128-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11281View

IMPLEMENT_DYNCREATE(CMy11281View, CView)

BEGIN_MESSAGE_MAP(CMy11281View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy11281View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy11281View construction/destruction

CMy11281View::CMy11281View()
{
	// TODO: add construction code here

}

CMy11281View::~CMy11281View()
{
}

BOOL CMy11281View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy11281View drawing

void CMy11281View::OnDraw(CDC* /*pDC*/)
{
	CMy11281Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy11281View printing


void CMy11281View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy11281View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy11281View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy11281View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy11281View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy11281View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy11281View diagnostics

#ifdef _DEBUG
void CMy11281View::AssertValid() const
{
	CView::AssertValid();
}

void CMy11281View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy11281Doc* CMy11281View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11281Doc)));
	return (CMy11281Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11281View message handlers
