// 1261View.h : interface of the CMy1261View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1261VIEW_H__F26563E3_DD4D_4772_A550_CE43E172534F__INCLUDED_)
#define AFX_1261VIEW_H__F26563E3_DD4D_4772_A550_CE43E172534F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "1261Doc.h"

class CMy1261View : public CView
{
protected: // create from serialization only
	CMy1261View();
	DECLARE_DYNCREATE(CMy1261View)

// Attributes
public:
	CMy1261Doc* GetDocument();
	CLine CurLine;	// 保存当前正在绘制的直线
	bool IsFinished;	// 当前直线是否绘制完成
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1261View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1261View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1261View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateYellow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOne(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTwo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateThree(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFour(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDashed(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnYellow();
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
	afx_msg void OnFour();
	afx_msg void OnSolid();
	afx_msg void OnDashed();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 1261View.cpp
inline CMy1261Doc* CMy1261View::GetDocument()
   { return (CMy1261Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1261VIEW_H__F26563E3_DD4D_4772_A550_CE43E172534F__INCLUDED_)
