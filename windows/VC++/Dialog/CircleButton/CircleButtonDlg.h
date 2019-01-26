// CircleButtonDlg.h : header file
//

#if !defined(AFX_CIRCLEBUTTONDLG_H__91A6CDAE_E913_4A27_8BF9_6D67B06C7725__INCLUDED_)
#define AFX_CIRCLEBUTTONDLG_H__91A6CDAE_E913_4A27_8BF9_6D67B06C7725__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCircleButtonDlg dialog
#include "CircleBtn.h"

class CCircleButtonDlg : public CDialog
{
// Construction
public:
	CCircleButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCircleButtonDlg)
	enum { IDD = IDD_CIRCLEBUTTON_DIALOG };
	CButton	m_RectangleBtn;
	CCircleBtn	m_CircleBtn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CBrush m_BrushBk;
	// Generated message map functions
	//{{AFX_MSG(CCircleButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRectangleButton();
	afx_msg void OnCircleButton();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEBUTTONDLG_H__91A6CDAE_E913_4A27_8BF9_6D67B06C7725__INCLUDED_)
