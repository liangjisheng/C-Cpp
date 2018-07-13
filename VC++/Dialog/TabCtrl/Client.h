#if !defined(AFX_CLIENT_H__68312F45_1CA3_4B41_82CA_CB659DD28069__INCLUDED_)
#define AFX_CLIENT_H__68312F45_1CA3_4B41_82CA_CB659DD28069__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Client.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClient dialog

class CClient : public CDialog
{
// Construction
public:
	CClient(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClient)
	enum { IDD = IDD_DIALOG_CLI };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClient)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClient)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT_H__68312F45_1CA3_4B41_82CA_CB659DD28069__INCLUDED_)
