// BmpEdit.cpp : implementation file
//

#include "stdafx.h"
#include "BmpBkGndEdit.h"
#include "BmpEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpEdit

CBmpEdit::CBmpEdit()
{
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
}

CBmpEdit::~CBmpEdit()
{
}


BEGIN_MESSAGE_MAP(CBmpEdit, CEdit)
	//{{AFX_MSG_MAP(CBmpEdit)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpEdit message handlers

HBRUSH CBmpEdit::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CEdit::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);		// �����ı�����͸��
	
	// TODO: Return a different brush if the default is not desired
	return NULL;
}

BOOL CBmpEdit::OnEraseBkgnd(CDC* pDC) 
{
	// ���Ʊ༭��λͼ����
	CDC memDC;	
	memDC.CreateCompatibleDC(pDC);	// �����ڴ��豸������
	memDC.SelectObject(&m_Bitmap);	// ��λͼѡ���豸������
	BITMAP m_Bmp;
	m_Bitmap.GetBitmap(&m_Bmp);		// ���λͼ��Ϣ
	int x = m_Bmp.bmWidth;			// λͼ���
	int y = m_Bmp.bmHeight;			// λͼ�߶�
	CRect rect;
	GetClientRect(&rect);
	// ����λͼ����
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY);
	memDC.DeleteDC();
	return TRUE;
	
	// return CEdit::OnEraseBkgnd(pDC);
}

void CBmpEdit::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	Invalidate();		// �ػ汳��
	
}
