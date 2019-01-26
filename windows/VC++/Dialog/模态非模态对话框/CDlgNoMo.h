#if !defined(AFX_CDLGNOMO_H__A006F440_1A83_4AF6_B510_76680F1F8933__INCLUDED_)
#define AFX_CDLGNOMO_H__A006F440_1A83_4AF6_B510_76680F1F8933__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgNoMo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCDlgNoMo dialog

class CCDlgNoMo : public CDialog
{
// Construction
public:
	CCDlgNoMo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCDlgNoMo)
	enum { IDD = IDD_DLGNOMO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDlgNoMo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCDlgNoMo
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLGNOMO_H__A006F440_1A83_4AF6_B510_76680F1F8933__INCLUDED_)
