#pragma once
#include <vector>
// CElement 命令目标

#ifdef ELEMENT_EXPORTS
#define SKETCHER_API __declspec(dllexport)
#else
#define SKETCHER_API __declspec(dllimport)
#endif

class SKETCHER_API CElement : public CObject
{
	DECLARE_SERIAL(CElement)
public:
	// 加入pElement是为了突出当前选中的元素
	virtual void Draw(CDC* pDC,CElement* pElement = nullptr) {}
	CRect GetBoundRect() const;
	virtual ~CElement();
	virtual void Move(const CSize& aSize) {}	// Move an element
	virtual void Serialize(CArchive& ar);
protected:
	// 必须包含此默认构造函数，那么在编译IMPLEMENT_SERIAL()宏时
	// 将出现错误信息
	CElement();
	int m_PenWidth;
	COLORREF m_Color;
	CRect m_EnclosingRect;	// 封闭矩形
};

class SKETCHER_API CLine :
	public CElement
{
	DECLARE_SERIAL(CLine)
public:
	virtual void Draw(CDC* pDC, CElement* pElement = nullptr);
	// Constructor for a line object
	CLine(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth);
	virtual ~CLine();
	virtual void Move(const CSize& aSize);
	virtual void Serialize(CArchive& ar);
protected:
	CLine();
	CPoint m_StartPoint;
	CPoint m_EndPoint;
};

class SKETCHER_API CRectangle :
	public CElement
{
	DECLARE_SERIAL(CRectangle)
public:
	virtual ~CRectangle();
	virtual void Draw(CDC* pDC, CElement* pElement = nullptr);
	CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth);
	virtual void Move(const CSize& aSize);
	virtual void Serialize(CArchive& ar);
protected:
	CRectangle();
};

class SKETCHER_API CCircle :
	public CElement
{
	DECLARE_SERIAL(CCircle)
public:
	virtual ~CCircle();
	virtual void Draw(CDC* pDC, CElement* pElement = nullptr);
	CCircle(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth);
	virtual void Move(const CSize& aSize);
	virtual void Serialize(CArchive& ar);
protected:
	CCircle();
};

class SKETCHER_API CCurve :
	public CElement
{
	DECLARE_SERIAL(CCurve)
public:
	virtual ~CCurve();
	virtual void Draw(CDC* pDC, CElement* pElement = nullptr);
	CCurve(const CPoint& start, const CPoint& end, COLORREF aColor,int penWidth);
	virtual void Move(const CSize& aSize);
	void AddSegment(const CPoint& point);
	virtual void Serialize(CArchive& ar);
protected:
	CCurve();
	std::vector<CPoint> m_Points;
};

class SKETCHER_API CText : public CElement
{
	DECLARE_SERIAL(CText)
public:
	// Function to display a text element
	virtual void Draw(CDC* pDC, CElement* pElement = 0);
	// Constuctor for a text element
	CText(const CString& aString, const CRect& rect, COLORREF aColor);
	virtual void Move(const CSize& size);	// Move a text element
	virtual void Serialize(CArchive& ar);
protected:
	CString m_String;
	CText() {}			// Default constructor
};