#if !defined(AFX_ICONBTN_H__618B69E0_E2EB_440E_8F04_A76752BD7D96__INCLUDED_)
#define AFX_ICONBTN_H__618B69E0_E2EB_440E_8F04_A76752BD7D96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IconBtn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIconBtn window

class CIconBtn : public CButton
{
// Construction
public:
	CIconBtn();

// Attributes
public:
	CImageList* m_pImageList;
	int m_ImageIndex;			// 图像索引
	BOOL IsPressed;		// 按钮是否被按下
// Operations
public:
	void SetImageList(CImageList* pImage);
	void SetImageIndex(UINT Index);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconBtn)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIconBtn();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	// Generated message map functions
protected:
	//{{AFX_MSG(CIconBtn)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONBTN_H__618B69E0_E2EB_440E_8F04_A76752BD7D96__INCLUDED_)
