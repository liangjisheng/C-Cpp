// 1058Dlg.h : header file
//

#if !defined(AFX_1058DLG_H__85F5E165_1052_4FB4_B15B_3B98B320DD76__INCLUDED_)
#define AFX_1058DLG_H__85F5E165_1052_4FB4_B15B_3B98B320DD76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1058Dlg dialog

class CMy1058Dlg : public CDialog
{
// Construction
public:
	CMy1058Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1058Dlg)
	enum { IDD = IDD_MY1058_DIALOG };
	int		m_Radio1;
	int		m_Radio3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1058Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1058Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadio1();
	afx_msg void OnRadio3();
	afx_msg void OnRadio2();
	afx_msg void OnRadio4();
	afx_msg void OnButton1();
	afx_msg void OnHide();
	afx_msg void OnShow();
	afx_msg void OnOpenforbid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1058DLG_H__85F5E165_1052_4FB4_B15B_3B98B320DD76__INCLUDED_)
