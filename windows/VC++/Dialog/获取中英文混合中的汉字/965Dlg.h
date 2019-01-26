// 965Dlg.h : header file
//

#if !defined(AFX_965DLG_H__ADDD4FF7_498B_4DBA_A5F9_765DA6306C34__INCLUDED_)
#define AFX_965DLG_H__ADDD4FF7_498B_4DBA_A5F9_765DA6306C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy965Dlg dialog

class CMy965Dlg : public CDialog
{
// Construction
public:
	CMy965Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy965Dlg)
	enum { IDD = IDD_MY965_DIALOG };
	CString	m_result;
	CString	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy965Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy965Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_965DLG_H__ADDD4FF7_498B_4DBA_A5F9_765DA6306C34__INCLUDED_)
