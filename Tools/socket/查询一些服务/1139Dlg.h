// 1139Dlg.h : header file
//

#if !defined(AFX_1139DLG_H__455B849C_F198_41F1_A97D_AAB0375F8E2D__INCLUDED_)
#define AFX_1139DLG_H__455B849C_F198_41F1_A97D_AAB0375F8E2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1139Dlg dialog

class CMy1139Dlg : public CDialog
{
// Construction
public:
	CMy1139Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1139Dlg)
	enum { IDD = IDD_MY1139_DIALOG };
	CString	m_host;
	CString	m_out;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1139Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void TryURL(CString URL);
	void TryFTPSite(CString host);
	void TryGopherSite(CString host);
	void TryFinger(CString host);
	void TryWhois(CString host);
	// Generated message map functions
	//{{AFX_MSG(CMy1139Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1139DLG_H__455B849C_F198_41F1_A97D_AAB0375F8E2D__INCLUDED_)
