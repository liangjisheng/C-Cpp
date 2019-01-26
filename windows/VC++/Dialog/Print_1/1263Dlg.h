// 1263Dlg.h : header file
//

#if !defined(AFX_1263DLG_H__9DF56BFA_7DE2_43D3_9887_8A04E5DAA2C1__INCLUDED_)
#define AFX_1263DLG_H__9DF56BFA_7DE2_43D3_9887_8A04E5DAA2C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1263Dlg dialog

class CMy1263Dlg : public CDialog
{
// Construction
public:
	CMy1263Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1263Dlg)
	enum { IDD = IDD_MY1263_DIALOG };
	CStatic	m_Path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1263Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString StrPath;
//	CString m_Title[4];
	// Generated message map functions
	//{{AFX_MSG(CMy1263Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButfile();
	afx_msg void OnButprint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1263DLG_H__9DF56BFA_7DE2_43D3_9887_8A04E5DAA2C1__INCLUDED_)
