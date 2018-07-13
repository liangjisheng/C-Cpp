
// 1128-1View.h : interface of the CMy11281View class
//

#pragma once


class CMy11281View : public CView
{
protected: // create from serialization only
	CMy11281View();
	DECLARE_DYNCREATE(CMy11281View)

// Attributes
public:
	CMy11281Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy11281View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 1128-1View.cpp
inline CMy11281Doc* CMy11281View::GetDocument() const
   { return reinterpret_cast<CMy11281Doc*>(m_pDocument); }
#endif

