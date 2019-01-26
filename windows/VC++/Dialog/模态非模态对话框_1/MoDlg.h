#if !defined(AFX_MODLG_H__53ACBF3A_DD30_4A9F_99BD_C518D08B7E0E__INCLUDED_)
#define AFX_MODLG_H__53ACBF3A_DD30_4A9F_99BD_C518D08B7E0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMoDlg dialog

class CMoDlg : public CDialog
{
// Construction
public:
	CMoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMoDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMoDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODLG_H__53ACBF3A_DD30_4A9F_99BD_C518D08B7E0E__INCLUDED_)
