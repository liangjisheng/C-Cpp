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
	// ����ť�ؼ�����BS_OWNERDRAW���ʱ�������Զ����ô˷������ư�ť
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);	// ��ð�ť�豸������ 
	if(m_pImageList)		// �ж��б���ͼ���Ƿ�Ϊ��
	{
		UINT state = lpDrawItemStruct->itemState;	// ��ȡ״̬
		IMAGEINFO ImageInfo;
		// ��ȡͼ���б���ͼ��Ĵ�С
		m_pImageList->GetImageInfo(m_ImageIndex,&ImageInfo);
		CSize ImageSize;
		ImageSize.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;	// ���
		ImageSize.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;	// �߶�
		// �ڰ�ť��ֱ������ʾλͼ
		CRect rect;
		GetClientRect(&rect);
		CPoint point;	// ��ʾͼ������Ͻǵ������
		point.x = 5;
		point.y = (rect.Height() - ImageSize.cy) / 2;
		// ����ͼ��
		m_pImageList->Draw(&dc,m_ImageIndex,point,ILD_NORMAL | ILD_TRANSPARENT);
		CRect focusRect(rect);		// ������������
		focusRect.DeflateRect(2,2,2,2);		// �������ҷŴ���������
		if((state & ODS_SELECTED) || (state & ODS_FOCUS))	// ��ť��ѡ�л��߻�ý���ʱ
		{
			CPen pen(PS_DASHDOTDOT,1,RGB(0,0,0));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			dc.DrawFocusRect(focusRect);	// ���ƽ������

			dc.DrawEdge(rect,BDR_RAISEDINNER | BDR_RAISEDOUTER,
				BF_BOTTOMLEFT | BF_TOPRIGHT);	// ��������Ч��
			dc.Draw3dRect(rect,RGB(0,0,0),RGB(0,0,0));	// ��ý���ʱ���ƺ�ɫ�߿�
		}
		else	// Ĭ�������
		{
			CPen pen(PS_DOT,1,RGB(192,192,192));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			dc.Rectangle(focusRect);	// ���ƽ������

			dc.DrawEdge(rect,BDR_RAISEDINNER | BDR_RAISEDOUTER,
				BF_BOTTOMLEFT | BF_TOPRIGHT);	// ��������Ч��
		}

		if(IsPressed)	// ��ť������ʱ���ư���Ч��
		{
			dc.DrawFocusRect(focusRect);
			dc.DrawEdge(rect,BDR_SUNKENINNER | BDR_SUNKENOUTER,
				BF_BOTTOMLEFT | BF_TOPRIGHT);	// ��������Ч��
			dc.Draw3dRect(rect,RGB(0,0,0),RGB(0,0,0));	// ��ý���ʱ���ƺ�ɫ�߿�
		}

		CString text;
		GetWindowText(text);	// ��ð�ť�ϵ���ʾ�ı�
		rect.DeflateRect(point.x + ImageSize.cx,0,0,0);	// �����ı���ʾ����
		dc.SetBkMode(TRANSPARENT);
		// ���ư�ť�ı�
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
