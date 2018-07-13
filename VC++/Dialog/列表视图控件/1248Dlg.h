// 1248Dlg.h : header file
//

#if !defined(AFX_1248DLG_H__D86E4B49_BB13_453C_BFBA_3C5AC95D4307__INCLUDED_)
#define AFX_1248DLG_H__D86E4B49_BB13_453C_BFBA_3C5AC95D4307__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1248Dlg dialog

class CMy1248Dlg : public CDialog
{
// Construction
public:
	CMy1248Dlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;
// Dialog Data
	//{{AFX_DATA(CMy1248Dlg)
	enum { IDD = IDD_MY1248_DIALOG };
	CListCtrl	m_Icon;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1248Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1248Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1248DLG_H__D86E4B49_BB13_453C_BFBA_3C5AC95D4307__INCLUDED_)
