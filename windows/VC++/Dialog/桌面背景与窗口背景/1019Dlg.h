// 1019Dlg.h : header file
//

#if !defined(AFX_1019DLG_H__ADA0CE99_52D1_478B_B5C0_1BE146E2BD67__INCLUDED_)
#define AFX_1019DLG_H__ADA0CE99_52D1_478B_B5C0_1BE146E2BD67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1019Dlg dialog

class CMy1019Dlg : public CDialog
{
// Construction
public:
	CMy1019Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1019Dlg)
	enum { IDD = IDD_MY1019_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1019Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1019Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1019DLG_H__ADA0CE99_52D1_478B_B5C0_1BE146E2BD67__INCLUDED_)
