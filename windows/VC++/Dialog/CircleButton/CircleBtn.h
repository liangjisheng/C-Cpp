#if !defined(AFX_CIRCLEBTN_H__B7E8D111_B637_404A_B3D8_5B6424637172__INCLUDED_)
#define AFX_CIRCLEBTN_H__B7E8D111_B637_404A_B3D8_5B6424637172__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CircleBtn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCircleBtn window

class CCircleBtn : public CButton
{
// Construction
public:
	CCircleBtn();

// Attributes
public:
	BOOL m_IsPressed;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleBtn)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCircleBtn();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	// Generated message map functions
protected:
	//{{AFX_MSG(CCircleBtn)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEBTN_H__B7E8D111_B637_404A_B3D8_5B6424637172__INCLUDED_)
