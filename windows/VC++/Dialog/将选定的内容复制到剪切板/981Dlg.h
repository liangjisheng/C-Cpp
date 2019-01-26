// 981Dlg.h : header file
//

#if !defined(AFX_981DLG_H__3D9FEF2F_F606_47FA_8F99_8F1598822B5C__INCLUDED_)
#define AFX_981DLG_H__3D9FEF2F_F606_47FA_8F99_8F1598822B5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy981Dlg dialog

class CMy981Dlg : public CDialog
{
// Construction
public:
	CMy981Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy981Dlg)
	enum { IDD = IDD_MY981_DIALOG };
	CEdit	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy981Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy981Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_981DLG_H__3D9FEF2F_F606_47FA_8F99_8F1598822B5C__INCLUDED_)
