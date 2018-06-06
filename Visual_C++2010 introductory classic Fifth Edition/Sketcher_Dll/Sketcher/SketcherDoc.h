
// SketcherDoc.h : CSketcherDoc 类的接口
//


#pragma once
#include "SketcherConstants.h"
#include "Element.h"
#include <list>

class CSketcherDoc : public CDocument
{
protected: // 仅从序列化创建
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// 特性
public:

// 操作
public:
	unsigned int GetElementType() const
	{
		return m_Element;
	}
	COLORREF GetElementColor() const
	{
		return m_Color;
	}
	void AddElement(CElement* pElement)
	{
		m_ElementList.push_back(pElement);
		SetModifiedFlag();		// 设置文档修改标识，默认参数为true
	}
	std::list<CElement*>::const_iterator begin() const
	{	// Get list begin iterator
		return m_ElementList.begin();
	}
	std::list<CElement*>::const_iterator end() const
	{	// Get list end iterator
		return m_ElementList.end();
	}
	CElement* FindElement(const CPoint& point) const;
	void DeleteElement(CElement* pElement);		// Delete an element
	void SendToBack(CElement* pElement);
	int GetPenWidth() const
	{
		return m_PenWidth;
	}
	CSize GetDocSize() const
	{
		return m_DocSize;
	}
	CRect GetDocExtent();	// Get the bounding rectangle for the whole document
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnElmentLine();
	afx_msg void OnElmentRectangle();
	afx_msg void OnElmentCircle();
	afx_msg void OnElmentCurve();
protected:
	// Current Element type
	ElementType m_Element;
	COLORREF m_Color;
	std::list<CElement*> m_ElementList;
	int m_PenWidth;		// Current line width
	CSize m_DocSize;	// Document Size
public:
	afx_msg void OnUpdateElmentLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElmentRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElmentCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElmentCurve(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnPenWidth();
	afx_msg void OnElmentText();
	afx_msg void OnUpdateElmentText(CCmdUI *pCmdUI);
};
