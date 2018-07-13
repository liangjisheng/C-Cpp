#if !defined(AFX_LOGIN_H__56C7957F_3675_41A0_B467_F243A1A2EA09__INCLUDED_)
#define AFX_LOGIN_H__56C7957F_3675_41A0_B467_F243A1A2EA09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogIn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogIn dialog

class CLogIn : public CDialog
{
// Construction
public:
	CLogIn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogIn)
	enum { IDD = IDD_DIALOG1 };
	CString	m_password;
	CString	m_username;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogIn)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__56C7957F_3675_41A0_B467_F243A1A2EA09__INCLUDED_)
