// LoadExtDllDlgDlg.h : header file
//

#if !defined(AFX_LOADEXTDLLDLGDLG_H__FAB71C14_BDA2_4BDF_A105_5F1C3764E2B6__INCLUDED_)
#define AFX_LOADEXTDLLDLGDLG_H__FAB71C14_BDA2_4BDF_A105_5F1C3764E2B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLoadExtDllDlgDlg dialog

class CLoadExtDllDlgDlg : public CDialog
{
// Construction
public:
	CLoadExtDllDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLoadExtDllDlgDlg)
	enum { IDD = IDD_LOADEXTDLLDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadExtDllDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLoadExtDllDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADEXTDLLDLGDLG_H__FAB71C14_BDA2_4BDF_A105_5F1C3764E2B6__INCLUDED_)
