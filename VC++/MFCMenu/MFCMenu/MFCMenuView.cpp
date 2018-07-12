
// MFCMenuView.cpp : CMFCMenuView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCMenu.h"
#endif

#include "MFCMenuDoc.h"
#include "MFCMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenuView

IMPLEMENT_DYNCREATE(CMFCMenuView, CView)

BEGIN_MESSAGE_MAP(CMFCMenuView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_SHOW, &CMFCMenuView::OnShow)
END_MESSAGE_MAP()

// CMFCMenuView ����/����

CMFCMenuView::CMFCMenuView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCMenuView::~CMFCMenuView()
{
}

BOOL CMFCMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCMenuView ����

void CMFCMenuView::OnDraw(CDC* /*pDC*/)
{
	CMFCMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCMenuView ��ӡ

BOOL CMFCMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCMenuView ���

#ifdef _DEBUG
void CMFCMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenuDoc* CMFCMenuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenuDoc)));
	return (CMFCMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenuView ��Ϣ�������


void CMFCMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu *pPopup = menu.GetSubMenu(0);
	ClientToScreen(&point);
	// TrackPopupMenu()������x��y����������Ļ���꣬����굥������������ǿͻ�������
	// ������Ҫ��һ�е�ת��
	// ӵ�������ݲ˵�(Ҳ�������Ĳ˵�)������ͼ�࣬������Ӧʱ��ֻ������ͼ���������
	// ��������������Ӧ������Ҫ���˿�ݲ˵��������߱���������,�������д����޸�
	// ��ݲ˵��������ߣ�����ʱ��ͼ���ܶԴ˿�ݲ˵�������������Ӧ����Ϣ�Żᴫ���������
	// ��������ͼ��Ӧ�˵���
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, this->GetParent());
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		//point.x, point.y, this);

	CView::OnRButtonDown(nFlags, point);
}


void CMFCMenuView::OnShow()
{
	MessageBox(_T("View show"));
}
