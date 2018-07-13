// 1245Dlg.h : header file
//

#if !defined(AFX_1245DLG_H__F657BB6B_4D64_4648_8E5B_5B66935AF9CC__INCLUDED_)
#define AFX_1245DLG_H__F657BB6B_4D64_4648_8E5B_5B66935AF9CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1245Dlg dialog

class CMy1245Dlg : public CDialog
{
// Construction
public:
	CMy1245Dlg(CWnd* pParent = NULL);	// standard constructor
	CStatusBar m_StatusBar;
// Dialog Data
	//{{AFX_DATA(CMy1245Dlg)
	enum { IDD = IDD_MY1245_DIALOG };
	CProgressCtrl	m_Progress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1245Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1245Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1245DLG_H__F657BB6B_4D64_4648_8E5B_5B66935AF9CC__INCLUDED_)
