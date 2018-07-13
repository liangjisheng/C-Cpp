// 1031Dlg.h : header file
//

#if !defined(AFX_1031DLG_H__BCF99F82_BFD2_4DC3_963C_9F4B92ECA131__INCLUDED_)
#define AFX_1031DLG_H__BCF99F82_BFD2_4DC3_963C_9F4B92ECA131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1031Dlg dialog

class CMy1031Dlg : public CDialog
{
// Construction
public:
	CMy1031Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1031Dlg)
	enum { IDD = IDD_MY1031_DIALOG };
	CComboBox	m_combo;
	CString	m_addstr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1031Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1031Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnAdd();
	afx_msg void OnAddnum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1031DLG_H__BCF99F82_BFD2_4DC3_963C_9F4B92ECA131__INCLUDED_)
