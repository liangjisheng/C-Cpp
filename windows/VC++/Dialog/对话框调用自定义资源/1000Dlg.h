// 1000Dlg.h : header file
//

#if !defined(AFX_1000DLG_H__8FCCEA30_96C4_40E2_A27A_B38E9C862859__INCLUDED_)
#define AFX_1000DLG_H__8FCCEA30_96C4_40E2_A27A_B38E9C862859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1000Dlg dialog

class CMy1000Dlg : public CDialog
{
// Construction
public:
	CMy1000Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1000Dlg)
	enum { IDD = IDD_MY1000_DIALOG };
	CString	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1000Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1000Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCallResource();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1000DLG_H__8FCCEA30_96C4_40E2_A27A_B38E9C862859__INCLUDED_)
