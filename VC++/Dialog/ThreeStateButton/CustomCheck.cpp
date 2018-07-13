// CustomCheck.cpp : implementation file
//

#include "stdafx.h"
#include "ThreeStateButton.h"
#include "CustomCheck.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomCheck

CCustomCheck::CCustomCheck()
{
	m_ImageList.Create(IDB_BITMAP1,13,0,ILC_COLOR16 | ILC_MASK);
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_ImageList.Add(&m_Bitmap,ILC_MASK);
	m_Bitmap.Detach();
	m_Bitmap.LoadBitmap(IDB_BITMAP2);
	m_ImageList.Add(&m_Bitmap,ILC_MASK);
	m_Bitmap.Detach();
	m_Bitmap.LoadBitmap(IDB_BITMAP3);
	m_ImageList.Add(&m_Bitmap,ILC_MASK);
	m_Bitmap.Detach();
	m_Check = FALSE;	// 默认设置复选框没有选中
}

CCustomCheck::~CCustomCheck()
{
}


BEGIN_MESSAGE_MAP(CCustomCheck, CButton)
	//{{AFX_MSG_MAP(CCustomCheck)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomCheck message handlers

void CCustomCheck::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);	// 获得按钮设备上下文
	UINT state = lpDrawItemStruct->itemState;	// 获得复选框的状态
	CRect rect;
	GetClientRect(&rect);
	CString Caption;
	GetWindowText(Caption);		// 获得复选框的显示文本

	if(m_Check)
		m_ImageList.Draw(&dc,2,CPoint(0,0),ILD_TRANSPARENT);	// 绘制选中时的位图
	else
		m_ImageList.Draw(&dc,0,CPoint(0,0),ILD_TRANSPARENT);
	if(state & ODS_DISABLED)		// 复选框不可用
		m_ImageList.Draw(&dc,1,CPoint(0,0),ILD_TRANSPARENT);	// 绘制必选状态的位图

	// 设置绘制文本的区域
	CRect textRect(rect.left+15,rect.top,rect.right,rect.bottom);
	dc.DrawText(Caption,textRect,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CCustomCheck::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CRect rect;
	GetClientRect(&rect);
	if(rect.PtInRect(point))	// 判断是否在复选框内
	{
		if(!m_Check)	// 选中状态
			m_Check = !m_Check;		// 设置为为选中
		else
			m_Check = !m_Check;
	}

	CButton::OnLButtonDown(nFlags, point);
}
