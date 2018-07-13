// 1016Dlg.h : header file
//

#if !defined(AFX_1016DLG_H__61A51889_6F83_411A_9D98_4EF2BB4878AA__INCLUDED_)
#define AFX_1016DLG_H__61A51889_6F83_411A_9D98_4EF2BB4878AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1016Dlg dialog

class CMy1016Dlg : public CDialog
{
// Construction
public:
	CMy1016Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1016Dlg)
	enum { IDD = IDD_MY1016_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1016Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1016Dlg)
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

#endif // !defined(AFX_1016DLG_H__61A51889_6F83_411A_9D98_4EF2BB4878AA__INCLUDED_)
