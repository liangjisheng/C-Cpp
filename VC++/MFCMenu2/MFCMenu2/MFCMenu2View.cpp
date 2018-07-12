
// MFCMenu2View.cpp : CMFCMenu2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCMenu2.h"
#endif

#include "MFCMenu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMenu2View

IMPLEMENT_DYNCREATE(CMFCMenu2View, CView)

BEGIN_MESSAGE_MAP(CMFCMenu2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE_1, &CMFCMenu2View::OnPhone1)
	ON_COMMAND(IDM_PHONE_2, &CMFCMenu2View::OnPhone2)
	ON_COMMAND(IDM_PHONE_3, &CMFCMenu2View::OnPhone3)
	ON_COMMAND(IDM_PHONE_4, &CMFCMenu2View::OnPhone4)
END_MESSAGE_MAP()

// CMFCMenu2View ����/����

CMFCMenu2View::CMFCMenu2View()
{
	// TODO: �ڴ˴���ӹ������
	m_nIndex = -1;
	m_strLine = _T("");
}

CMFCMenu2View::~CMFCMenu2View()
{
}

BOOL CMFCMenu2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCMenu2View ����

void CMFCMenu2View::OnDraw(CDC* /*pDC*/)
{
	CMFCMenu2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCMenu2View ��ӡ

BOOL CMFCMenu2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCMenu2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCMenu2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCMenu2View ���

#ifdef _DEBUG
void CMFCMenu2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMenu2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMenu2Doc* CMFCMenu2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMenu2Doc)));
	return (CMFCMenu2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMenu2View ��Ϣ�������


void CMFCMenu2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ����һ�ΰ��»س���ʱ�򣬶�̬�����Ӳ˵�
	CClientDC dc(this);
	if (0x0d == nChar)
	{
		if (0 == ++m_nIndex)
		{
			m_menu.CreatePopupMenu();
			GetParent()->GetMenu()->AppendMenu(MF_POPUP, (UINT)m_menu.m_hMenu, _T("PhoneBooks"));
			// ���ֻ���������д��룬��ô����ü����ַ���Ȼ���»س������ֲ˵�����
			// ��û����ӡ�PhoneBooks���Ӳ˵����������ǰ�����ƶ���Ӧ����ʾ����Ӳ˵�
			// ��λ��ʱ�����߳��򴰿ڵĳߴ緢���仯֮������Ӳ˵��ͳ����ˡ�
			// ��ǰ��CMainFrame���OnCreate()��������еĲ˵�������������ʾ������
			// ��ΪCMainFrame���OnCreate������������ʵ�ִ��ڵĴ�����Ҳ����˵��
			// �ڵ���OnCreate����ʱ������Ĵ��ڻ�δ��������ʾ����������������ж�
			// �����ϲ˵��������޸Ļ������ڳ�������ϳ��ֳ��������ڴ��ڴ�������ʾ
			// ���֮����ȥ�޸ĳ���˵������ݣ���Ҫ�Բ˵�������һ���ػ��������
			// �����޸ĵĽ����CWnd���ṩ��һ��DrawMenuBar()��Ա������ɶԲ˵���
			// �ػ������
			// �˵������ڿ�ܴ��ڵģ����Ӧ���ÿ����ȥ�ػ�˵������������ͼ����
			// �ػ�˵�����û��Ч����
			GetParent()->DrawMenuBar();	// �ػ�˵�
		}
		m_menu.AppendMenu(MF_STRING, IDM_PHONE_1 + m_nIndex, 
			m_strLine.Left(m_strLine.Find(_T(" "))));
		m_strArray.Add(m_strLine);
		m_strLine.Empty();				// �س�������ַ���
		// ���û���������д��룬�ڴ���������������ϴ����������֮����ʾ��
		// ϣ�����ϴ���ʾ�����������������ʾ��ǰ��������֡��ж��ط�������
		// ʵ�ִ��������ֵĲ������������ô����ػ�ķ�����ʵ�֡�CWnd����һ��
		// Invalidate()�ĳ�Ա�������ú������������ô��ڵ������ͻ�����Ч������
		// ����һ��WM_PAINT��Ϣ����ʱ�����ھͻᱻ����
		// void Invalidate(BOOL bErase = TRUE);
		// �������ΪTRUE���ػ�ʱ�ͻ�Ѵ��ڵı��������������������ڵı�����
		Invalidate();
	}
	else
	{
		m_strLine += (char)nChar;
		dc.TextOut(0, 0, m_strLine);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCMenu2View::OnPhone1()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(0));
}


void CMFCMenu2View::OnPhone2()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(1));
}


void CMFCMenu2View::OnPhone3()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(2));
}


void CMFCMenu2View::OnPhone4()
{
	CClientDC dc(this);
	dc.TextOut(0, 0, m_strArray.GetAt(3));
}
