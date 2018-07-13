// CircleBtn.cpp : implementation file
//

#include "stdafx.h"
#include "CircleButton.h"
#include "CircleBtn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleBtn

CCircleBtn::CCircleBtn()
{
	m_IsPressed = FALSE;
}

CCircleBtn::~CCircleBtn()
{
}


BEGIN_MESSAGE_MAP(CCircleBtn, CButton)
	//{{AFX_MSG_MAP(CCircleBtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleBtn message handlers

void CCircleBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	dc.SetBkMode(TRANSPARENT);
	CBrush m_Brush;
	m_Brush.CreateStockObject(NULL_BRUSH);
	dc.SelectObject(&m_Brush);

	if(m_IsPressed)
	{
		CPen pen(PS_SOLID,2,RGB(255,0,0));
		dc.SelectObject(&pen);
		HRGN h_rgn = CreateEllipticRgn(0,0,rect.Width(),rect.Height());
		SetWindowRgn(h_rgn,true);	// 设置按钮的显示区域
		dc.Ellipse(0,0,rect.Width(),rect.Height());
		dc.SetTextColor(RGB(255,0,0));
	}
	else
	{
		CPen pen(PS_SOLID,2,RGB(255,255,255));
		dc.SelectObject(&pen);
		HRGN h_rgn = CreateEllipticRgn(0,0,rect.Width(),rect.Height());
		SetWindowRgn(h_rgn,true);
		dc.Ellipse(0,0,rect.Width(),rect.Height());
		dc.SetTextColor(RGB(255,255,255));
	}
	CString str;
	GetWindowText(str);		// 获取按钮文本
	dc.DrawText(str,CRect(0,0,rect.right,rect.bottom),
		DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	dc.DeleteDC();
}

void CCircleBtn::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_IsPressed = TRUE;
	
	CButton::OnLButtonDown(nFlags, point);
}

void CCircleBtn::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_IsPressed = FALSE;
	
	CButton::OnLButtonUp(nFlags, point);
}

BOOL CCircleBtn::OnEraseBkgnd(CDC* pDC) 
{
	return FALSE;
	// return CButton::OnEraseBkgnd(pDC);
}
