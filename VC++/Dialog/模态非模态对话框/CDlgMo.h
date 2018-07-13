#if !defined(AFX_CDLGMO_H__971C4A97_6A31_4177_9BF1_D466D367E4A3__INCLUDED_)
#define AFX_CDLGMO_H__971C4A97_6A31_4177_9BF1_D466D367E4A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgMo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCDlgMo dialog

class CCDlgMo : public CDialog
{
// Construction
public:
	CCDlgMo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCDlgMo)
	enum { IDD = IDD_DLGMO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDlgMo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCDlgMo)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLGMO_H__971C4A97_6A31_4177_9BF1_D466D367E4A3__INCLUDED_)
