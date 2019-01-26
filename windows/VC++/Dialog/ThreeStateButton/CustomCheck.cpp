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
	m_Check = FALSE;	// Ĭ�����ø�ѡ��û��ѡ��
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
	dc.Attach(lpDrawItemStruct->hDC);	// ��ð�ť�豸������
	UINT state = lpDrawItemStruct->itemState;	// ��ø�ѡ���״̬
	CRect rect;
	GetClientRect(&rect);
	CString Caption;
	GetWindowText(Caption);		// ��ø�ѡ�����ʾ�ı�

	if(m_Check)
		m_ImageList.Draw(&dc,2,CPoint(0,0),ILD_TRANSPARENT);	// ����ѡ��ʱ��λͼ
	else
		m_ImageList.Draw(&dc,0,CPoint(0,0),ILD_TRANSPARENT);
	if(state & ODS_DISABLED)		// ��ѡ�򲻿���
		m_ImageList.Draw(&dc,1,CPoint(0,0),ILD_TRANSPARENT);	// ���Ʊ�ѡ״̬��λͼ

	// ���û����ı�������
	CRect textRect(rect.left+15,rect.top,rect.right,rect.bottom);
	dc.DrawText(Caption,textRect,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CCustomCheck::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CRect rect;
	GetClientRect(&rect);
	if(rect.PtInRect(point))	// �ж��Ƿ��ڸ�ѡ����
	{
		if(!m_Check)	// ѡ��״̬
			m_Check = !m_Check;		// ����ΪΪѡ��
		else
			m_Check = !m_Check;
	}

	CButton::OnLButtonDown(nFlags, point);
}
