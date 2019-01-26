// 1242Dlg.h : header file
//

#if !defined(AFX_1242DLG_H__C3E661CD_AD1F_43E3_85F3_BBCC32B091C5__INCLUDED_)
#define AFX_1242DLG_H__C3E661CD_AD1F_43E3_85F3_BBCC32B091C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1242Dlg dialog

class CMy1242Dlg : public CDialog
{
// Construction
public:
	CMy1242Dlg(CWnd* pParent = NULL);	// standard constructor
	CToolBar m_ToolBar;
// Dialog Data
	//{{AFX_DATA(CMy1242Dlg)
	enum { IDD = IDD_MY1242_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1242Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	afx_msg void OnNumber1();
	afx_msg void OnNumber2();
	afx_msg void OnNumber3();
	afx_msg void OnNumber4();
	afx_msg void OnNumber5();
	// Generated message map functions
	//{{AFX_MSG(CMy1242Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1242DLG_H__C3E661CD_AD1F_43E3_85F3_BBCC32B091C5__INCLUDED_)
