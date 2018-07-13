// IconBtn.cpp : implementation file
//

#include "stdafx.h"
#include "IconButton.h"
#include "IconBtn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconBtn

CIconBtn::CIconBtn()
{
}

CIconBtn::~CIconBtn()
{
}


BEGIN_MESSAGE_MAP(CIconBtn, CButton)
	//{{AFX_MSG_MAP(CIconBtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconBtn message handlers

void CIconBtn::SetImageList(CImageList* pImage)
{
	m_pImageList = pImage;
}

void CIconBtn::SetImageIndex(UINT Index)
{
	m_ImageIndex = Index;
}

void CIconBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// 当按钮控件含有BS_OWNERDRAW风格时，程序将自动调用此方法绘制按钮
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);	// 获得按钮设备上下文 
	if(m_pImageList)		// 判断列表视图中是否为空
	{
		UINT state = lpDrawItemStruct->itemState;	// 获取状态
		IMAGEINFO ImageInfo;
		// 获取图像列表中图像的大小
		m_pImageList->GetImageInfo(m_ImageIndex,&ImageInfo);
		CSize ImageSize;
		ImageSize.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;	// 宽度
		ImageSize.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;	// 高度
		// 在按钮垂直居中显示位图
		CRect rect;
		GetClientRect(&rect);
		CPoint point;	// 显示图标的左上角点的坐标
		point.x = 5;
		point.y = (rect.Height() - ImageSize.cy) / 2;
		// 绘制图标
		m_pImageList->Draw(&dc,m_ImageIndex,point,ILD_NORMAL | ILD_TRANSPARENT);
		CRect focusRect(rect);		// 声明焦点区域
		focusRect.DeflateRect(2,2,2,2);		// 上下左右放大两个像素
		if((state & ODS_SELECTED) || (state & ODS_FOCUS))	// 按钮被选中或者获得焦点时
		{
			CPen pen(PS_DASHDOTDOT,1,RGB(0,0,0));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			dc.DrawFocusRect(focusRect);	// 绘制焦点矩形

			dc.DrawEdge(rect,BDR_RAISEDINNER | BDR_RAISEDOUTER,
				BF_BOTTOMLEFT | BF_TOPRIGHT);	// 绘制立体效果
			dc.Draw3dRect(rect,RGB(0,0,0),RGB(0,0,0));	// 获得焦点时绘制黑色边框
		}
		else	// 默认情况下
		{
			CPen pen(PS_DOT,1,RGB(192,192,192));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			dc.Rectangle(focusRect);	// 绘制焦点矩形

			dc.DrawEdge(rect,BDR_RAISEDINNER | BDR_RAISEDOUTER,
				BF_BOTTOMLEFT | BF_TOPRIGHT);	// 绘制立体效果
		}

		if(IsPressed)	// 按钮被按下时绘制按下效果
		{
			dc.DrawFocusRect(focusRect);
			dc.DrawEdge(rect,BDR_SUNKENINNER | BDR_SUNKENOUTER,
				BF_BOTTOMLEFT | BF_TOPRIGHT);	// 绘制立体效果
			dc.Draw3dRect(rect,RGB(0,0,0),RGB(0,0,0));	// 获得焦点时绘制黑色边框
		}

		CString text;
		GetWindowText(text);	// 获得按钮上的显示文本
		rect.DeflateRect(point.x + ImageSize.cx,0,0,0);	// 设置文本显示区域
		dc.SetBkMode(TRANSPARENT);
		// 绘制按钮文本
		dc.DrawText(text,rect,DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}

void CIconBtn::OnLButtonDown(UINT nFlags, CPoint point) 
{
	IsPressed = TRUE;
		
	CButton::OnLButtonDown(nFlags, point);
}

void CIconBtn::OnLButtonUp(UINT nFlags, CPoint point) 
{
	IsPressed = FALSE;

	CButton::OnLButtonUp(nFlags, point);
}
