// ThreeStateButtonDlg.h : header file
//

#if !defined(AFX_THREESTATEBUTTONDLG_H__C5B08E71_6468_474D_BAF0_28384306B2AC__INCLUDED_)
#define AFX_THREESTATEBUTTONDLG_H__C5B08E71_6468_474D_BAF0_28384306B2AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CustomCheck.h"
/////////////////////////////////////////////////////////////////////////////
// CThreeStateButtonDlg dialog

class CThreeStateButtonDlg : public CDialog
{
// Construction
public:
	CThreeStateButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreeStateButtonDlg)
	enum { IDD = IDD_THREESTATEBUTTON_DIALOG };
	CCustomCheck	m_CustomCheck3;
	CCustomCheck	m_ChineseCustomCheck;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreeStateButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreeStateButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREESTATEBUTTONDLG_H__C5B08E71_6468_474D_BAF0_28384306B2AC__INCLUDED_)
