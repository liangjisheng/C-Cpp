#if !defined(AFX_HELLODLG_H__29510F54_105D_4A80_8AA6_5FD58F4D5197__INCLUDED_)
#define AFX_HELLODLG_H__29510F54_105D_4A80_8AA6_5FD58F4D5197__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CHelloDlg dialog

class CHelloDlg : public CDialog
{
// Construction
public:
	CHelloDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHelloDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHelloDlg)
	afx_msg void OnHello();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLODLG_H__29510F54_105D_4A80_8AA6_5FD58F4D5197__INCLUDED_)
