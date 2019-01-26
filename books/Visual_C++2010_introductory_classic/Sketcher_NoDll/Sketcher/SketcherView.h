
// SketcherView.h : CSketcherView 类的接口
//

#pragma once
#include "atltypes.h"
#include "Element.h"
#include <typeinfo>

class CSketcherView : public CScrollView
{
protected: // 仅从序列化创建
	CSketcherView();
	DECLARE_DYNCREATE(CSketcherView)

// 特性
public:
	CSketcherDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSketcherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CElement* CreateElement(void) const;
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	// Frist point recorded for the element
	CPoint m_FirstPoint;
	// Second point recorded for the element
	CPoint m_SecondPoint;
	CElement* m_pTempElement;
	CElement* m_pSelected;
	bool m_bMoveMode;		// Move element flag
	CPoint m_CursorPos;
	CPoint m_FirstPos;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	void MoveElememt(CClientDC& aDC, const CPoint& point);		// Move an element
	int m_Scale;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnElementMove();
	afx_msg void OnElementDelete();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnElementSendtoback();
	afx_msg void OnViewScale();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	void ResetScrollSizes();
	afx_msg void OnUpdateScale(CCmdUI *pCmdUI);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // SketcherView.cpp 中的调试版本
inline CSketcherDoc* CSketcherView::GetDocument() const
   { return reinterpret_cast<CSketcherDoc*>(m_pDocument); }
#endif

