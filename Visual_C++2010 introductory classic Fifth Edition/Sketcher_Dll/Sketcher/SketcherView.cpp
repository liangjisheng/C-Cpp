
// SketcherView.cpp : CSketcherView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "SketcherView.h"
#include "ScaleDialog.h"
#include "TextDialog.h"
#include "PrintData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CScrollView)

BEGIN_MESSAGE_MAP(CSketcherView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ELEMENT_MOVE, &CSketcherView::OnElementMove)
	ON_COMMAND(ID_ELEMENT_DELETE, &CSketcherView::OnElementDelete)
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_ELEMENT_SENDTOBACK, &CSketcherView::OnElementSendtoback)
	ON_COMMAND(ID_VIEW_SCALE, &CSketcherView::OnViewScale)
ON_UPDATE_COMMAND_UI(IDS_INDICATOR_SCALE, &CSketcherView::OnUpdateScale)
END_MESSAGE_MAP()

// CSketcherView ����/����

CSketcherView::CSketcherView()
	: m_FirstPoint(CPoint(0,0))
	, m_SecondPoint(CPoint(0,0))
	, m_pTempElement(NULL)
	, m_pSelected(NULL)
	, m_bMoveMode(false)
	, m_FirstPos(CPoint(0,0))
	, m_CursorPos(CPoint(0,0))
	, m_Scale(1)
{
	SetScrollSizes(MM_TEXT, CSize(0, 0));
}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSketcherView ����

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

//	pDC->MoveTo(50, 50);
//	pDC->LineTo(50, 200);
//	pDC->LineTo(150, 200);
//	pDC->LineTo(150, 50);
//	pDC->LineTo(50, 50);

//	CPen aPen;
//	aPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0, ));
//	CPen* pOldPen = pDC->SelectObject(&aPen);

//	pDC->Ellipse(50, 50, 150, 150);	// Draw the 1st(large) circle

	// Define the bounding rectangle for the 2nd(smaller) circle
//	CRect rect(250, 50, 300, 100);
//	CPoint start(275, 100);
//	CPoint end(250, 75);
//	pDC->Arc(&rect, start, end);

//	pDC->SelectObject(pOldPen);

	CElement* pElement(nullptr);
	for (auto iter = pDoc->begin(); iter != pDoc->end(); iter++)
	{
		pElement = *iter;
		// If the element is visible
		// RectVisible()�������Ϊ�����ṩ�����ľ����Ƿ���WindowsҪ��
		// ���»��Ƶľ����ص���ȷ��ֻ����λ��WindowsҪ�����»��Ƶ������е�Ԫ��
		// ���Ӧ�ó��������
		if (pDC->RectVisible(pElement->GetBoundRect()))
			pElement->Draw(pDC,m_pSelected);
	}
}


// CSketcherView ��ӡ

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ��׼����ӡ�����м����ӡҳ��
	CPrintData* p(new CPrintData);		// Create a print data object
	CSketcherDoc* pDoc = GetDocument();
	CRect docExtent = pDoc->GetDocExtent();		// Get the whole document area

	// Save the reference point for the whole document
	p->m_DocRefPoint = CPoint(docExtent.left, docExtent.top);

	// Get the name of the document file and save it
	p->m_DocTitle = pDoc->GetTitle();

	// Calculate how many printed page widths are required
	// to accommodate the width of the document
	p->m_nWidths = static_cast<UINT>(ceil(		// ����ȡ��
		static_cast<double>(docExtent.Width()) / p->printWidth));

	// Calculate how many printed page lengths are required
	// to accommodate the document length
	p->m_nLengths = static_cast<UINT>(
		ceil(static_cast<double>(docExtent.Height()) / p->printLength));

	// Set the frist page number as 1 and
	// set the last page number as the total number of pages
	pInfo->SetMinPage(1);
	pInfo->SetMaxPage(p->m_nWidths*p->m_nLengths);
	pInfo->m_lpUserData = p;	// Store address of PrintData object

	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
	// ����ڴ�ӡ������ʹ��GDI��Դ����ֱ�CPen��,��Ҫ��Ӵ����Է���
	// ��Щ��Դ��Ȼ����OnEndPrinting()�н��������Դɾ��
}

void CSketcherView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Delete our print data object
	delete static_cast<CPrintData*>(pInfo->m_lpUserData);
}


// CSketcherView ���

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView ��Ϣ�������

void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// CClientDC���ŵ��ǣ������󳬳��������ǣ����Զ��ͷ��豸������
	CClientDC aDC(this);		// Create a device context
	// OnPrepareDC()��CScrollView�еĳ�Ա���������ö�Ӧ�ڹ���λ�õ��߼�����ϵͳ��ԭ��
	// ����OnPrepareDC()���豸�����Ľ������OnInitialUpdate()�����õ�ӳ��ģʽ
	OnPrepareDC(&aDC);			// Get origin adjusted
	aDC.DPtoLP(&point);			// Convert point to logical coordinates

	if (m_bMoveMode)
	{
		// In moving mode,so drop the element
		m_bMoveMode = false;	// Kill move mode
		m_pSelected = nullptr;	// De-select the element
		GetDocument()->UpdateAllViews(nullptr);	// Redraw all the views
		GetDocument()->SetModifiedFlag();
		return;
	}
	CSketcherDoc* pDoc = GetDocument();
	if (pDoc->GetElementType() == TEXT)
	{
		CTextDialog aDlg;
		if (aDlg.DoModal() == IDOK)
		{
			// Exit OK so create a text element
			// ��textExtent��ʼ��Ϊ���߼������ʾ���ı��ַ����Ŀ�Ⱥ͸߶�
			CSize textExtent = aDC.GetTextExtent(aDlg.m_TextString);
			CRect rect(point, textExtent);	// Create enclosing rectangle
			CText* pTextElement = new CText(aDlg.m_TextString, rect, pDoc->GetElementColor());
			// Add the element to the document
			pDoc->AddElement(pTextElement);
			// Get all views updated
			pDoc->UpdateAllViews(nullptr, 0, pTextElement);
		}
		return;
	}
	m_FirstPoint = point;
	SetCapture();
	// CView::OnLButtonDown(nFlags, point);
}


void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (this == GetCapture())
		ReleaseCapture();
	// If there is an element , add it to the document
	if (m_pTempElement)
	{
		GetDocument()->AddElement(m_pTempElement);
		// �������е���ͼ��
		GetDocument()->UpdateAllViews(nullptr, 0, m_pTempElement);
		// Call a document class function to store the element
		// pointer to by m_pTempElement in the document object
		// AfxMessageBox(_T("OnLButtonUp"));
		// delete m_pTempElement;
		// ��ȡ���»��Ƶĵ�ǰ��ͼ�Ĺ�������0��ʹ������ͼ�Ĺ�������Ч
		// InvalidateRect(nullptr);
		m_pTempElement = nullptr;
	}

	// CView::OnLButtonUp(nFlags, point);
}


void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC aDC(this);
	OnPrepareDC(&aDC);		// Get origin adjusted
	aDC.DPtoLP(&point);

	if (m_bMoveMode)
	{
		MoveElememt(aDC,point);
		return;
	}
	if ((nFlags & MK_LBUTTON) && (this == GetCapture()))
	{
		m_SecondPoint = point;
		if (m_pTempElement)
		{
			if (CURVE == GetDocument()->GetElementType())	// Is it a curve
			{
				// We are draw a curve so add a segment to the existing curve
				static_cast<CCurve*>(m_pTempElement)->AddSegment(m_SecondPoint);
				m_pTempElement->Draw(&aDC);
				return;		// We are done
			}
			// If we get to here it's not a curve so
			// redraw the old element so it disappears from the view
			aDC.SetROP2(R2_NOTXORPEN);	// Set the drawing mode
			m_pTempElement->Draw(&aDC);
			delete m_pTempElement;
			m_pTempElement = nullptr;
		}
		// Create a temporary element of the type and color that
		// is recorded in the document object, and draw it
		m_pTempElement = CreateElement();
		m_pTempElement->Draw(&aDC);
	}
	else
	{
		// ����ƶ�ʱȷ����������Ƿ���һ��Ԫ�أ��жϹ��λ���Ƿ�λ��һ��Ԫ�صı߽������
		// ����Ӧ������m_pSelected
		// We are not creating an element ,so select an element,to do hihglighting
		CSketcherDoc* pDoc = GetDocument();
		CElement* pOldSelected(m_pSelected);	// ��¼ԭ��ͻ����ʾ��Ԫ��
		m_pSelected = pDoc->FindElement(point);	// Set selected element
		if (m_pSelected != pOldSelected)
		{
			// ������if��������if-elseĿ���ǵ�����Ԫ������һ���ʱ�򣬿���һ��ͻ����ʾ
			if (m_pSelected)
				InvalidateRect(m_pSelected->GetBoundRect(), FALSE);
			if (pOldSelected)
				InvalidateRect(pOldSelected->GetBoundRect(), FALSE);
			pDoc->UpdateAllViews(nullptr);
		}
	}

	// CView::OnMouseMove(nFlags, point);
}

// Create an element of the current type
CElement* CSketcherView::CreateElement(void) const
{
	// Get a pointer to the document for this view
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Now select the element using the type stored in the document
	switch (pDoc->GetElementType())
	{
	case RECTANGLE:
		return new CRectangle(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(),pDoc->GetPenWidth());
	case CIRCLE:
		return new CCircle(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());
	case CURVE:
		return new CCurve(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());
	case LINE:
		return new CLine(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());
	default:
		// Something is gone wrong
		AfxMessageBox(_T("Bad Element code"), MB_OK);
		AfxAbort();
		return nullptr;
	}
}

void CSketcherView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: �ڴ����ר�ô����/����û���
	// Invalidate the area coreaponding to the element pointed to 
	// if there is one,otherwise invalidate the whole client area
	if (pHint)
	{
		CClientDC aDC(this);	// Get a device context
		OnPrepareDC(&aDC);		// Get origin adjusted

		// Get the enclosing rectangle and convert to client coordinate
		CRect aRect = static_cast<CElement*>(pHint)->GetBoundRect();
		aDC.LPtoDP(aRect);
		InvalidateRect(aRect);	// Get the area redrawn
	}
	else
		InvalidateRect(nullptr);
}


void CSketcherView::OnInitialUpdate()
{
	ResetScrollSizes();		// Set up the scrollbars
	CScrollView::OnInitialUpdate();

	// Define document size
	//CSize DocSize(20000, 20000);
	// Set mapping mode and document size
	// CSize(500,500)����ÿһҳ���������ش�С
	// CSize(50,50)����ÿһ�й��������ش�С
	//SetScrollSizes(MM_TEXT, DocSize, CSize(500, 500), CSize(50, 50));
}


void CSketcherView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	if (m_pSelected)
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_ELEMENT_MENU, point.x, point.y, this);
	else
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_NOELEMENT_MENU, point.x, point.y, this);
}


void CSketcherView::OnElementMove()
{
	CClientDC aDC(this);
	OnPrepareDC(&aDC);
	GetCursorPos(&m_CursorPos);
	ScreenToClient(&m_CursorPos);
	aDC.DPtoLP(&m_CursorPos);
	m_FirstPos = m_CursorPos;
	m_bMoveMode = true;
}


void CSketcherView::OnElementDelete()
{
	if (m_pSelected)
	{
		CSketcherDoc* pDoc = GetDocument();
		pDoc->DeleteElement(m_pSelected);	// Delete the element
		pDoc->UpdateAllViews(nullptr);		// Redraw all the views
		m_pSelected = nullptr;				// Reset selected element ptr
	}
}


void CSketcherView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// ���ͷ�����Ҽ���ʱ��ر��ƶ�ģʽ,���������Ĳ˵�����ʾ
	if (m_bMoveMode)
	{
		m_bMoveMode = false;
		return;
	}
	// ����ʾ�¼ӵ������Ĳ˵�
	theApp.PreLoadState();

	//CMenu Menu;
	//if (m_pSelected)
	//	Menu.LoadMenu(IDR_ELEMENT_MENU);
	//else
	//	Menu.LoadMenu(IDR_NOELEMENT_MENU);

	//ClientToScreen(&point);		// ������ֵ�ɿͻ�����ת��Ϊ��Ļ����   
	//Menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

	// Ĭ�ϴ������ClientToScreen(), OnContextMenu(),
	CScrollView::OnRButtonUp(nFlags, point);
}


void CSketcherView::MoveElememt(CClientDC& aDC, const CPoint& point)
{
	CSize distance = point - m_CursorPos;	// Get move distance
	m_CursorPos = point;	// Set current point as 1st for next time
	// If there is an element selected,move it
	if (m_pSelected)
	{
		// If the element is text use this method
		// typeid()����const type_info���������
		if (typeid(*m_pSelected) == typeid(CText))
		{
			CRect oldRect = m_pSelected->GetBoundRect();	// Get old bound rect
			aDC.LPtoDP(oldRect);
			m_pSelected->Move(distance);
			InvalidateRect(&oldRect);		// Invalidate combined area
			UpdateWindow();					// Redraw immediately
			m_pSelected->Draw(&aDC, m_pSelected);
			return;
		}
		// ...otherwise,use this method
		aDC.SetROP2(R2_NOTXORPEN);
		m_pSelected->Draw(&aDC, m_pSelected);	// Draw the element to erase it
		m_pSelected->Move(distance);	// Now move the element
		m_pSelected->Draw(&aDC, m_pSelected);
	}
}

void CSketcherView::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (m_bMoveMode)
	{
		// In moving mode,so drop element back in original position
		CClientDC aDC(this);
		MoveElememt(aDC, m_FirstPos);
		m_pSelected = nullptr;
		GetDocument()->UpdateAllViews(nullptr);
	}

	CScrollView::OnRButtonDown(nFlags, point);
}


void CSketcherView::OnElementSendtoback()
{
	// ���Ҫ�ƶ���ɾ����Ԫ�ر���һ���ڸ�Ԫ��֮����Ƶ�Ԫ�صľ��ΰ�Χ��
	// �������Ǹ�Ԫ��ͻ����ʾ����ΪSketcher�����������ȷ����ⲿ��Ԫ�ء�
	// �ⲿԪ����ȫƽ��������Χ��Ԫ�ء�����Ԫ�����б��е�˳����ɵĽ����
	// ͨ���������Ĳ˵����Send to Back�˵�������������⣬
	// �ò˵��ĳ��Ԫ���ƶ����б�Ŀ�ͷ.
	GetDocument()->SendToBack(m_pSelected);	// Move element to start of lsit
}


void CSketcherView::OnViewScale()
{
	CScaleDialog aDlg;
	aDlg.m_Scale = m_Scale - 1;
	if (aDlg.DoModal() == IDOK)
	{
		m_Scale = 1 + aDlg.m_Scale;
		ResetScrollSizes();
		InvalidateRect(0);	// ʹ������ͼ��Ч���ػ�
	}
}


void CSketcherView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// ��ӡʱ�����ǵ����ű�����Sketcher���򽫵���OnPrepareDC()
	int scale = m_Scale;
	if (pDC->IsPrinting())	// If we are printing,set scale to 1
		scale = 1;

	CScrollView::OnPrepareDC(pDC, pInfo);
	CSketcherDoc* pDoc = GetDocument();
	pDC->SetMapMode(MM_ANISOTROPIC);	// Set the map mode
	CSize DocSize = pDoc->GetDocSize();	// Get the document size
	pDC->SetWindowExt(DocSize);			// Now set the window extent

	// Get the number of pixels per inch in x and y
	int xLogPixels = pDC->GetDeviceCaps(LOGPIXELSX);
	int yLogPixels = pDC->GetDeviceCaps(LOGPIXELSY);

	// Calculate the viewport extent in x and y
	int xExtent = (DocSize.cx*scale*xLogPixels) / 100;
	int yExtent = (DocSize.cy*scale*yLogPixels) / 100;

	pDC->SetViewportExt(xExtent, yExtent);
}


void CSketcherView::ResetScrollSizes()
{
	CClientDC aDC(this);
	OnPrepareDC(&aDC);
	CSize DocSize = GetDocument()->GetDocSize();
	aDC.LPtoDP(&DocSize);
	SetScrollSizes(MM_TEXT, DocSize);
}


void CSketcherView::OnUpdateScale(CCmdUI *pCmdUI)
{
	// ��״̬�������װ��һ������Ŀ��
	pCmdUI->Enable();	// �Ǵ����ı�������ʾ
	CString scaleStr;
	scaleStr.Format(_T("View Scale : %d"), m_Scale);
	pCmdUI->SetText(scaleStr);
}

// Print a page of the document
void CSketcherView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CPrintData* p(static_cast<CPrintData*>(pInfo->m_lpUserData));
	// Output the document file name
	pDC->SetTextAlign(TA_CENTER);	// Center the following text
	pDC->TextOut(pInfo->m_rectDraw.right / 2, 20, p->m_DocTitle);
	CString str;
	str.Format(_T("Page %u"), pInfo->m_nCurPage);
	pDC->TextOut(pInfo->m_rectDraw.right / 2, pInfo->m_rectDraw.bottom - 20, str);
	pDC->SetTextAlign(TA_LEFT);		// Left justify text

	// Calculate the origin point for the current page
	int xOrg = p->m_DocRefPoint.x +
		p->printWidth*((pInfo->m_nCurPage - 1) % (p->m_nWidths));
	int yOrg = p->m_DocRefPoint.y +
		p->printLength*((pInfo->m_nCurPage - 1) / (p->m_nWidths));

	// Calculate offsets to center drawing area on page as positive values
	int xOffset = (pInfo->m_rectDraw.right - p->printWidth) / 2;
	int yOffset = (pInfo->m_rectDraw.bottom - p->printLength) / 2;

	// Change window origin to correspond to current page & save old origin
	CPoint OldOrg = pDC->SetWindowOrg(xOrg - xOffset, yOrg - yOffset);

	// Define a clip rectangle the size of the printed area
	pDC->IntersectClipRect(xOrg, yOrg, xOrg + p->printWidth, yOrg + p->printLength);

	OnDraw(pDC);		// Draw the whole document
	pDC->SelectClipRgn(nullptr);	// Remove the clip rectangle
	pDC->SetWindowOrg(OldOrg);		// Restore old window origin

	CScrollView::OnPrint(pDC, pInfo);
}
