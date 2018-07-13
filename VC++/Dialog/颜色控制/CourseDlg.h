#if !defined(AFX_COURSEDLG_H__42406261_173B_432E_9D81_FE5AE6C9E83E__INCLUDED_)
#define AFX_COURSEDLG_H__42406261_173B_432E_9D81_FE5AE6C9E83E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog

class CCourseDlg : public CDialog
{
// Construction
public:
	CCourseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCourseDlg)
	enum { IDD = IDD_DIALOG1 };
	CSpinButtonCtrl	m_spinOpen;
	CComboBox	m_comboSpecial;
	CString	m_strNo;
	CString	m_strName;
	CString	m_strSpecial;
	CString	m_strType;
	BYTE	m_nOpen;
	int		m_nHours;
	double	m_dCredit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCourseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSEDLG_H__42406261_173B_432E_9D81_FE5AE6C9E83E__INCLUDED_)
