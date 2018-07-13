// 1239Dlg.h : header file
//

#if !defined(AFX_1239DLG_H__9B54901C_D923_470B_AC53_612BC98D1B6A__INCLUDED_)
#define AFX_1239DLG_H__9B54901C_D923_470B_AC53_612BC98D1B6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1239Dlg dialog

class CMy1239Dlg : public CDialog
{
// Construction
public:
	CMy1239Dlg(CWnd* pParent = NULL);	// standard constructor
	CMenu m_Menu;
// Dialog Data
	//{{AFX_DATA(CMy1239Dlg)
	enum { IDD = IDD_MY1239_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1239Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1239Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMenuitemadd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1239DLG_H__9B54901C_D923_470B_AC53_612BC98D1B6A__INCLUDED_)
