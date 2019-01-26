// CustomTree.cpp : implementation file
//

#include "stdafx.h"
#include "BmpTree.h"
#include "CustomTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomTree

CCustomTree::CCustomTree()
{
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
}

CCustomTree::~CCustomTree()
{
}


BEGIN_MESSAGE_MAP(CCustomTree, CTreeCtrl)
	//{{AFX_MSG_MAP(CCustomTree)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomTree message handlers

void CCustomTree::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	// 初始化一个与设备上下文兼容的位图
	bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
	memDC.SelectObject(&bitmap);
	CWnd::DefWindowProc(WM_PAINT,(WPARAM)memDC.m_hDC,0);	// 获取原始画布
	CMemDC tempDC(&dc,rect);	// 绘制背景图片
	CBrush brush;
	brush.CreatePatternBrush(&m_Bitmap);
	tempDC.FillRect(rect,&brush);	// 填充背景区域
	tempDC.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),
		&memDC,rect.left,rect.top,SRCAND);	// 将原始图片与背景进行组合
	brush.DeleteObject();
	
	// TODO: Add your message handler code here

	
	// Do not call CTreeCtrl::OnPaint() for painting messages
}

BOOL CCustomTree::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;	
	// return CTreeCtrl::OnEraseBkgnd(pDC);
}

void CCustomTree::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	SetRedraw(FALSE);
	
	*pResult = 0;
}

void CCustomTree::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	SetRedraw(FALSE);
		
	*pResult = 0;
}
