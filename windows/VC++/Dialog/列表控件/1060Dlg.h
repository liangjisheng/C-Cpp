// 1060Dlg.h : header file
//

#if !defined(AFX_1060DLG_H__A45266BE_E0D0_44C2_A5CE_ECE5B3DE0B8A__INCLUDED_)
#define AFX_1060DLG_H__A45266BE_E0D0_44C2_A5CE_ECE5B3DE0B8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1060Dlg dialog

class CMy1060Dlg : public CDialog
{
// Construction
public:
	CMy1060Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1060Dlg)
	enum { IDD = IDD_MY1060_DIALOG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1060Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1060Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStudent();
	afx_msg void OnChange();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1060DLG_H__A45266BE_E0D0_44C2_A5CE_ECE5B3DE0B8A__INCLUDED_)
