// 1258View.cpp : implementation of the CMy1258View class
//

#include "stdafx.h"
#include "1258.h"

#include "1258Doc.h"
#include "1258View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1258View

IMPLEMENT_DYNCREATE(CMy1258View, CView)

BEGIN_MESSAGE_MAP(CMy1258View, CView)
	//{{AFX_MSG_MAP(CMy1258View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1258View construction/destruction

CMy1258View::CMy1258View()
{
	// TODO: add construction code here

}

CMy1258View::~CMy1258View()
{
}

BOOL CMy1258View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1258View drawing

void CMy1258View::OnDraw(CDC* pDC)
{
	CMy1258Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	// 填充图形区域
//	CRect rc(30,40,100,120);
//	CBrush brush(RGB(0,255,0));
//	pDC->FillRect(rc,&brush);	// 使用颜色填充区域
//	brush.DeleteObject();

//	CBitmap bitmap;
//	bitmap.LoadBitmap(IDB_BITMAP1);
//	brush.CreatePatternBrush(&bitmap);
//	CRect bmpRC(110,40,200,120);
//	pDC->FillRect(bmpRC,&brush);
//	bitmap.DeleteObject();
//	brush.DeleteObject();

//	CRect rectrc(210,40,300,120);
//	CRect hrc(280,60,350,140);
//	pDC->Rectangle(rectrc);
//	pDC->Rectangle(hrc);
	// 创建一个矩形选区
//	HRGN hRect = CreateRectRgn(210,40,300,120);
//	HRGN hrgn = CreateRectRgn(280,60,350,140);
//	HRGN hret = CreateRectRgn(0,0,0,0);
	// 组合选区，获取两个选区的公共部分
//	CombineRgn(hret,hRect,hrgn,RGN_AND);
//	brush.CreateSolidBrush(RGB(255,0,0));
//	CRgn rgn;
//	rgn.Attach(hret);	// 将选区对象附加一个选区句柄
//	pDC->FillRgn(&rgn,&brush);
//	brush.DeleteObject();
//	rgn.Detach();	// 分离选区句柄
//	DeleteObject(hRect);
//	DeleteObject(hrc);
//	DeleteObject(hret);


	// 在设备上下文中绘制图像
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);
	memDC.SelectObject(&bmp);
	pDC->BitBlt(30,20,180,180,&memDC,1,1,SRCCOPY);

	CRect rc(30,20,210,200);
	CBrush brush(RGB(0,0,0));
	pDC->FrameRect(rc,&brush);	// 绘制矩形边框
	rc.OffsetRect(220,0);		// 移动区域
	BITMAP BitInfo;
	bmp.GetBitmap(&BitInfo);	// 获取位图信息
	int x = BitInfo.bmWidth;
	int y = BitInfo.bmHeight;
	// 绘制位图
	pDC->StretchBlt(rc.left,rc.top,rc.Width(),rc.Height(),
		&memDC,0,0,x,y,SRCCOPY);
	pDC->FrameRect(rc,&brush);
	brush.DeleteObject();
	memDC.DeleteDC();
	bmp.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CMy1258View printing

BOOL CMy1258View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy1258View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy1258View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy1258View diagnostics

#ifdef _DEBUG
void CMy1258View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1258View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1258Doc* CMy1258View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1258Doc)));
	return (CMy1258Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1258View message handlers
