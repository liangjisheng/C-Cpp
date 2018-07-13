#if !defined(AFX_BMPEDIT_H__28307916_0A7A_4AF7_9E56_D800EDDBD488__INCLUDED_)
#define AFX_BMPEDIT_H__28307916_0A7A_4AF7_9E56_D800EDDBD488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BmpEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBmpEdit window

class CBmpEdit : public CEdit
{
// Construction
public:
	CBmpEdit();

// Attributes
public:
	CBitmap m_Bitmap;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBmpEdit)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnChange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPEDIT_H__28307916_0A7A_4AF7_9E56_D800EDDBD488__INCLUDED_)
