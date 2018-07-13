#if !defined(AFX_CUSTOMCHECK_H__21E4F678_DD76_4332_AA58_165A677CA93A__INCLUDED_)
#define AFX_CUSTOMCHECK_H__21E4F678_DD76_4332_AA58_165A677CA93A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomCheck.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomCheck window

class CCustomCheck : public CButton
{
// Construction
public:
	CCustomCheck();

// Attributes
public:
	BOOL m_Check;		// 复选框是否选中
	UINT m_State;		// 复选框的状态
	CBitmap m_Bitmap;
	CImageList m_ImageList;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomCheck)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomCheck();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomCheck)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMCHECK_H__21E4F678_DD76_4332_AA58_165A677CA93A__INCLUDED_)
