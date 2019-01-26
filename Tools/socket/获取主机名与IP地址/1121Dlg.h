// 1121Dlg.h : header file
//

#if !defined(AFX_1121DLG_H__48184342_66E5_4560_859E_D1F5F42B2802__INCLUDED_)
#define AFX_1121DLG_H__48184342_66E5_4560_859E_D1F5F42B2802__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1121Dlg dialog

class CMy1121Dlg : public CDialog
{
// Construction
public:
	CMy1121Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1121Dlg)
	enum { IDD = IDD_MY1121_DIALOG };
	CString	m_strHostName;
	CString	m_strIP;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1121Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1121Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1121DLG_H__48184342_66E5_4560_859E_D1F5F42B2802__INCLUDED_)
