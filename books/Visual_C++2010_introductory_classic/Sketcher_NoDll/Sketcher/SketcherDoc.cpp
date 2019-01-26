
// SketcherDoc.cpp : CSketcherDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "PenDialog.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
	ON_COMMAND(ID_COLOR_BLACK, &CSketcherDoc::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CSketcherDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CSketcherDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CSketcherDoc::OnColorBlue)
	ON_COMMAND(ID_ELMENT_LINE, &CSketcherDoc::OnElmentLine)
	ON_COMMAND(ID_ELMENT_RECTANGLE, &CSketcherDoc::OnElmentRectangle)
	ON_COMMAND(ID_ELMENT_CIRCLE, &CSketcherDoc::OnElmentCircle)
	ON_COMMAND(ID_ELMENT_CURVE, &CSketcherDoc::OnElmentCurve)
	ON_UPDATE_COMMAND_UI(ID_ELMENT_LINE, &CSketcherDoc::OnUpdateElmentLine)
	ON_UPDATE_COMMAND_UI(ID_ELMENT_RECTANGLE, &CSketcherDoc::OnUpdateElmentRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELMENT_CIRCLE, &CSketcherDoc::OnUpdateElmentCircle)
	ON_UPDATE_COMMAND_UI(ID_ELMENT_CURVE, &CSketcherDoc::OnUpdateElmentCurve)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CSketcherDoc::OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSketcherDoc::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSketcherDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE,&CSketcherDoc::OnUpdateColorBlue)
	ON_COMMAND(ID_PEN_WIDTH, &CSketcherDoc::OnPenWidth)
	ON_COMMAND(ID_ELMENT_TEXT, &CSketcherDoc::OnElmentText)
	ON_UPDATE_COMMAND_UI(ID_ELMENT_TEXT, &CSketcherDoc::OnUpdateElmentText)
END_MESSAGE_MAP()


// CSketcherDoc 构造/析构

CSketcherDoc::CSketcherDoc() :m_Element(LINE),m_Color(BLACK)
{
	m_PenWidth = 0;
	m_DocSize = CSize(3000, 3000);
}

CSketcherDoc::~CSketcherDoc()
{
	// Delete the element pointed to by each list array
	for (auto iter = m_ElementList.begin(); iter != m_ElementList.end(); iter++)
		delete *iter;
	m_ElementList.clear();	// Finally delete all pointers
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

// CSketcherDoc 序列化

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_Color
			<< static_cast<int>(m_Element)	// The current element type as an integer
			<< m_PenWidth
			<< m_DocSize;	// The current document size
		ar << m_ElementList.size();	// Store the number of elements in the list
		// Now store the elements from the list
		for (auto iter = m_ElementList.begin(); iter != m_ElementList.end(); ++iter)
			ar << *iter;
	}
	else
	{
		int elementType(0);		// Stores element type
		ar >> m_Color
			>> elementType
			>> m_PenWidth
			>> m_DocSize;
		m_Element = static_cast<ElementType>(elementType);

		size_t elementCount(0);		// Count of number of elements
		CElement* pElement(nullptr);
		ar >> elementCount;
		// Now retrieve all the elements ans store in the list
		for (size_t i = 0; i < elementCount; ++i)
		{
			ar >> pElement;
			m_ElementList.push_back(pElement);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CSketcherDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CSketcherDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CSketcherDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSketcherDoc 诊断

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

// CSketcherDoc 命令

void CSketcherDoc::OnColorBlack()
{
	m_Color = BLACK;
}


void CSketcherDoc::OnColorRed()
{
	m_Color = RED;
}


void CSketcherDoc::OnColorGreen()
{
	m_Color = GREEN;
}


void CSketcherDoc::OnColorBlue()
{
	m_Color = BLUE;
}


void CSketcherDoc::OnElmentLine()
{
	m_Element = LINE;
}


void CSketcherDoc::OnElmentRectangle()
{
	m_Element = RECTANGLE;
}


void CSketcherDoc::OnElmentCircle()
{
	m_Element = CIRCLE;
}


void CSketcherDoc::OnElmentCurve()
{
	m_Element = CURVE;
}

void CSketcherDoc::OnUpdateElmentLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Element == LINE);
}

void CSketcherDoc::OnUpdateElmentRectangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Element == RECTANGLE);
}


void CSketcherDoc::OnUpdateElmentCircle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Element == CIRCLE);
}


void CSketcherDoc::OnUpdateElmentCurve(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Element == CURVE);
}


void CSketcherDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == BLACK);
}


void CSketcherDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == RED);
}


void CSketcherDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == GREEN);
}

void CSketcherDoc::OnUpdateColorBlue(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_Color == BLUE);
}

CElement* CSketcherDoc::FindElement(const CPoint& point) const
{
	// 搜索边界矩形封闭了point的第一个元素
	for (auto rIter = m_ElementList.rbegin(); rIter != m_ElementList.rend(); rIter++)
	{
		if ((*rIter)->GetBoundRect().PtInRect(point))
			return *rIter;
	}
	return nullptr;
}

void CSketcherDoc::DeleteElement(CElement* pElement)
{
	if (pElement)
	{
		m_ElementList.remove(pElement);
		delete pElement;
		SetModifiedFlag();
	}
}

void CSketcherDoc::SendToBack(CElement* pElement)
{
	// 将pElement所指元素移动到列表的开头，remove()只是在列表中删除了pElement
	// 所指元素，并没有在内存中删除，然后将其添加到开头，搜索突出显示的元素的
	// 操作是从列表的尾部开始的
	if (pElement)
	{
		m_ElementList.remove(pElement);
		m_ElementList.push_front(pElement);
	}
}

void CSketcherDoc::OnPenWidth()
{
	CPenDialog aDlg;	// Create a local dialog object
	// Set the pen width in the dialog to that stored in the document
	aDlg.m_PenWidth = m_PenWidth;
	// Display the dialog as modal
	// When closed with OK,get the pen width
	if (aDlg.DoModal() == IDOK)
		m_PenWidth = aDlg.m_PenWidth;
}


void CSketcherDoc::OnElmentText()
{
	// 将文档中的元素设置为TEXT类型
	m_Element = TEXT;
}


void CSketcherDoc::OnUpdateElmentText(CCmdUI *pCmdUI)
{
	// Set checked if the current element is text
	pCmdUI->SetCheck(m_Element == TEXT);
}

CRect CSketcherDoc::GetDocExtent()
{
	CRect docExtent(0, 0, 1, 1);
	// UnionRect()不能正确处理高度或宽度为0的矩形，所以对docExtent进行初始化
	// 计算包含两个矩形的最下矩形
	for (auto iter = m_ElementList.begin(); iter != m_ElementList.end(); ++iter)
		docExtent.UnionRect(docExtent, (*iter)->GetBoundRect());

	docExtent.NormalizeRect();
	return docExtent;
}