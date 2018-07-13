#if !defined(AFX_SCOREDLG_H__10573C64_F0D2_4ED7_AF69_6AE35015E7CC__INCLUDED_)
#define AFX_SCOREDLG_H__10573C64_F0D2_4ED7_AF69_6AE35015E7CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog

class CScoreDlg : public CDialog
{
// Construction
public:
	CString m_strAddText;
	CScoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScoreDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strCourseNo;
	double	m_dScore;
	double	m_dCredit;
	CString	m_strStuNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoreDlg)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREDLG_H__10573C64_F0D2_4ED7_AF69_6AE35015E7CC__INCLUDED_)
