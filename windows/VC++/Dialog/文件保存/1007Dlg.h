// 1007Dlg.h : header file
//

#if !defined(AFX_1007DLG_H__D8D28159_2FD1_41E2_B4CF_925CA681AD45__INCLUDED_)
#define AFX_1007DLG_H__D8D28159_2FD1_41E2_B4CF_925CA681AD45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1007Dlg dialog

class CMy1007Dlg : public CDialog
{
// Construction
public:
	CMy1007Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1007Dlg)
	enum { IDD = IDD_MY1007_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1007Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1007Dlg)
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

#endif // !defined(AFX_1007DLG_H__D8D28159_2FD1_41E2_B4CF_925CA681AD45__INCLUDED_)
