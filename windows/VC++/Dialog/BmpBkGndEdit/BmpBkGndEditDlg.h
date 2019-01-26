// BmpBkGndEditDlg.h : header file
//

#if !defined(AFX_BMPBKGNDEDITDLG_H__F7F04B3D_3490_449D_AD63_B7082E52024E__INCLUDED_)
#define AFX_BMPBKGNDEDITDLG_H__F7F04B3D_3490_449D_AD63_B7082E52024E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpBkGndEditDlg dialog
#include "BmpEdit.h"

class CBmpBkGndEditDlg : public CDialog
{
// Construction
public:
	CBmpBkGndEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpBkGndEditDlg)
	enum { IDD = IDD_BMPBKGNDEDIT_DIALOG };
	CBmpEdit	m_BmpEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpBkGndEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpBkGndEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBKGNDEDITDLG_H__F7F04B3D_3490_449D_AD63_B7082E52024E__INCLUDED_)
