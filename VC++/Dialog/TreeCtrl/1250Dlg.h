// 1250Dlg.h : header file
//

#if !defined(AFX_1250DLG_H__CDA79F6E_8026_41F5_A36C_4548D02356C7__INCLUDED_)
#define AFX_1250DLG_H__CDA79F6E_8026_41F5_A36C_4548D02356C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1250Dlg dialog

class CMy1250Dlg : public CDialog
{
// Construction
public:
	CMy1250Dlg(CWnd* pParent = NULL);	// standard constructor
	CTreeCtrl m_Tree;
	CImageList m_ImageList;
// Dialog Data
	//{{AFX_DATA(CMy1250Dlg)
	enum { IDD = IDD_MY1250_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1250Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	afx_msg void OnRclickTree1(NMHDR* pNMHDR,LRESULT* pResult);		// ÓÒ¼üµ¥»÷
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR,LRESULT* pResult);		// Êó±êË«»÷
	// Generated message map functions
	//{{AFX_MSG(CMy1250Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1250DLG_H__CDA79F6E_8026_41F5_A36C_4548D02356C7__INCLUDED_)
