// 1017Dlg.h : header file
//

#if !defined(AFX_1017DLG_H__1B005D38_4059_4C5C_945E_23B7BC18FF08__INCLUDED_)
#define AFX_1017DLG_H__1B005D38_4059_4C5C_945E_23B7BC18FF08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1017Dlg dialog

class CMy1017Dlg : public CDialog
{
// Construction
public:
	CFont m_font;
	CMy1017Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1017Dlg)
	enum { IDD = IDD_MY1017_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1017Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1017Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1017DLG_H__1B005D38_4059_4C5C_945E_23B7BC18FF08__INCLUDED_)
