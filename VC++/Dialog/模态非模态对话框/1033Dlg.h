// 1033Dlg.h : header file
//

#if !defined(AFX_1033DLG_H__D961F809_90FD_4066_B9E1_474EE888E0CD__INCLUDED_)
#define AFX_1033DLG_H__D961F809_90FD_4066_B9E1_474EE888E0CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CDlgMo.h"
#include "CDlgNoMo.h"

/////////////////////////////////////////////////////////////////////////////
// CMy1033Dlg dialog

class CMy1033Dlg : public CDialog
{
// Construction
public:
	CMy1033Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1033Dlg)
	enum { IDD = IDD_MY1033_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1033Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1033Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDoModal();
	afx_msg void OnDoNoModal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1033DLG_H__D961F809_90FD_4066_B9E1_474EE888E0CD__INCLUDED_)
