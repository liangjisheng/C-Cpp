// 1009Dlg.h : header file
//

#if !defined(AFX_1009DLG_H__3FEBD204_63AB_4FA1_9163_4DF6DFA970DA__INCLUDED_)
#define AFX_1009DLG_H__3FEBD204_63AB_4FA1_9163_4DF6DFA970DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1009Dlg dialog

class CMy1009Dlg : public CDialog
{
// Construction
public:
	CMy1009Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1009Dlg)
	enum { IDD = IDD_MY1009_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1009Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1009Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1009DLG_H__3FEBD204_63AB_4FA1_9163_4DF6DFA970DA__INCLUDED_)
