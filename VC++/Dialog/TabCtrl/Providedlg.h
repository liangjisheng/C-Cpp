#if !defined(AFX_PROVIDEDLG_H__649DC245_8950_4C19_80F2_5541F33943A3__INCLUDED_)
#define AFX_PROVIDEDLG_H__649DC245_8950_4C19_80F2_5541F33943A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Providedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProvidedlg dialog

class CProvidedlg : public CDialog
{
// Construction
public:
	CProvidedlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProvidedlg)
	enum { IDD = IDD_DIALOG_PRO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProvidedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProvidedlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROVIDEDLG_H__649DC245_8950_4C19_80F2_5541F33943A3__INCLUDED_)
