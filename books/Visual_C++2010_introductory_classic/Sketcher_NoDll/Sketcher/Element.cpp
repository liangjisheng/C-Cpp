// Element.cpp : 实现文件
//

#include "stdafx.h"
#include "Sketcher.h"
#include "Element.h"
#include "SketcherConstants.h"
#include <cmath>
#include <algorithm>

// CElement
// 第三个参数是一个标识模式的无符号的32为整数，
// 如果读取不同模式号编写的数据，将抛出一个异常
// IMPLEMENT_SERIAL()支持运行时类信息，动态创建类对象，序列化
IMPLEMENT_SERIAL(CElement,CObject,VERSION_NUMBER)
IMPLEMENT_SERIAL(CLine, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CRectangle, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CCircle, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CCurve, CElement, VERSION_NUMBER)
IMPLEMENT_SERIAL(CText, CElement, VERSION_NUMBER)

CElement::CElement()
{
}

CRect CElement::GetBoundRect() const
{
	CRect boundingRect(m_EnclosingRect);
	// Increase the rectangle by the pen width and return it
	int Offset = m_PenWidth == 0 ? 0 : m_PenWidth;	// Width must be at least 1
	boundingRect.InflateRect(Offset, Offset);
	return boundingRect;
}

void CElement::Serialize(CArchive& ar)
{
	// 调用基类的序列化函数，确保序列化继承的数据成员
	CObject::Serialize(ar);		// Call the base class function

	if (ar.IsStoring())
	{
		ar << m_PenWidth
			<< m_Color
			<< m_EnclosingRect;
	}
	else
	{
		ar >> m_PenWidth
			>> m_Color
			>> m_EnclosingRect;
	}
}

CElement::~CElement()
{
}


// CElement 成员函数


CLine::CLine()
{
}

CLine::CLine(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth)
	:m_StartPoint(start), m_EndPoint(end)
{
	m_PenWidth = penWidth;	// Set pen width
	m_Color = aColor;
	m_EnclosingRect = CRect(start, end);
	m_EnclosingRect.NormalizeRect();	// 规范化矩形
}

void CLine::Draw(CDC* pDC, CElement* pElement)
{
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, this == pElement ? SELECT_COLOR : m_Color))
	{
		AfxMessageBox(_T("Pen creation failed drawing a line"), MB_OK);
		AfxAbort();
	}
	CPen* pOldPen = pDC->SelectObject(&aPen);

	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);

	pDC->SelectObject(pOldPen);
}

void CLine::Move(const CSize& aSize)
{
	m_StartPoint += aSize;		// Move the start point
	m_EndPoint += aSize;		// and end point
	m_EnclosingRect += aSize;	// Move the enclosing rectangle
}

void CLine::Serialize(CArchive& ar)
{
	CElement::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_StartPoint
			<< m_EndPoint;
	}
	else
	{
		ar >> m_StartPoint
			>> m_EndPoint;
	}
}

CLine::~CLine()
{
}


CRectangle::CRectangle()
{
}

CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth)
{
	m_Color = aColor;
	m_PenWidth = penWidth;
	m_EnclosingRect = CRect(start, end);
	m_EnclosingRect.NormalizeRect();
}

void CRectangle::Draw(CDC* pDC, CElement* pElement)
{
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, this == pElement ? SELECT_COLOR : m_Color))
	{
		AfxMessageBox(_T("Pen creation failed drawing a rectangle"), MB_OK);
		AfxAbort();
	}
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	pDC->Rectangle(m_EnclosingRect);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CRectangle::Move(const CSize& aSize)
{
	m_EnclosingRect += aSize;
}

void CRectangle::Serialize(CArchive& ar)
{
	// CRectangle类里没有其他数据成员，只调用基类的序列化函数即可
	CElement::Serialize(ar);
}

CRectangle::~CRectangle()
{
}


CCircle::CCircle()
{
}

CCircle::CCircle(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth)
{
	// First calculate radius
	// We use floating point because that is required by 
	// the library function (in math) for calculating a square root.
	long radius = static_cast<long>(sqrt(
		static_cast<double>((end.x - start.x)*(end.x - start.x) +
		(end.y - start.y)*(end.y - start.y))));

	// Now calculate the rectangle enclosing
	// the circle assuming the MM_TEXT mapping mode
	m_EnclosingRect = CRect(start.x - radius, start.y - radius,
		start.x + radius, start.y + radius);
	m_EnclosingRect.NormalizeRect();	// Normalize-in case it's not MM_TEXT

	m_Color = aColor;
	m_PenWidth = penWidth;
}

void CCircle::Draw(CDC* pDC, CElement* pElement)
{
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, this == pElement ? SELECT_COLOR : m_Color))
	{
		AfxMessageBox(_T("Pen creation failed drawing a circle"), MB_OK);
		AfxAbort();
	}

	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	pDC->Ellipse(m_EnclosingRect);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CCircle::Move(const CSize& aSize)
{
	m_EnclosingRect += aSize;
}

void CCircle::Serialize(CArchive& ar)
{
	CElement::Serialize(ar);
}

CCircle::~CCircle()
{
}


CCurve::CCurve()
{
}

CCurve::CCurve(const CPoint& first, const CPoint& second, COLORREF aColor,int penWidth)
{
	m_Points.push_back(first);
	m_Points.push_back(second);
	m_EnclosingRect = CRect(min(first.x, second.x), min(first.y, second.y),
		max(first.x, second.y), max(first.y, second.y));

	m_PenWidth = penWidth;
	m_Color = aColor;
}

void CCurve::AddSegment(const CPoint& point)
{
	m_Points.push_back(point);
	// Modify the enclosing rectangle for the new point
	m_EnclosingRect = CRect(min(point.x, m_EnclosingRect.left),
							min(point.y, m_EnclosingRect.top),
							max(point.x, m_EnclosingRect.right),
							max(point.y, m_EnclosingRect.bottom));
}

void CCurve::Draw(CDC* pDC, CElement* pElement)
{
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, this == pElement ? SELECT_COLOR : m_Color))
	{
		AfxMessageBox(_T("Pen creation failed drawing a curve"), MB_OK);
		AfxAbort();
	}

	CPen* pOldPen = pDC->SelectObject(&aPen);
	// Now draw the curve
	pDC->MoveTo(m_Points[0]);
	for (size_t i = 1; i<m_Points.size(); i++)
		pDC->LineTo(m_Points[i]);

	pDC->SelectObject(pOldPen);
}

void CCurve::Move(const CSize& aSize)
{
	m_EnclosingRect += aSize;
	// Now move all the points
	std::for_each(m_Points.begin(),m_Points.end(),
		[&aSize](CPoint& p) { p += aSize; });
}

void CCurve::Serialize(CArchive& ar)
{
	CElement::Serialize(ar);

	// Serialize the vector of points
	if (ar.IsStoring())
	{
		ar << m_Points.size();
		// Now store the points
		for (size_t i = 0; i < m_Points.size(); i++)
			ar << m_Points[i];
	}
	else
	{
		size_t nPoints(0);
		ar >> nPoints;		// Retrieve the number of points
		CPoint point;
		for (size_t i = 0; i < nPoints; i++)
		{
			ar >> point;
			m_Points.push_back(point);
		}
	}
}

CCurve::~CCurve()
{
}


CText::CText(const CString& aString, const CRect& rect, COLORREF aColor)
{
	m_PenWidth = 1;
	m_Color = aColor;
	m_String = aString;

	m_EnclosingRect = rect;
	m_EnclosingRect.NormalizeRect();	// 规范化
}

void CText::Draw(CDC* pDC, CElement* pElement)
{
	COLORREF Color(m_Color);	// Initialize with element color
	if (this == pElement)
		Color = SELECT_COLOR;	// Set selected color
	// Set the text color and output the text
	pDC->SetTextColor(Color);
	pDC->DrawText(m_String, m_EnclosingRect, DT_CENTER | DT_VCENTER
		| DT_SINGLELINE | DT_NOCLIP);
}

void CText::Move(const CSize& size)
{
	m_EnclosingRect += size;
}

void CText::Serialize(CArchive& ar)
{
	CElement::Serialize(ar);

	if (ar.IsStoring())
		ar << m_String;
	else
		ar >> m_String;
}