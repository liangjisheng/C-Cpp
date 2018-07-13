// 1241Dlg.h : header file
//

#if !defined(AFX_1241DLG_H__E38B962A_CE25_47B6_88EB_59579C978047__INCLUDED_)
#define AFX_1241DLG_H__E38B962A_CE25_47B6_88EB_59579C978047__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1241Dlg dialog

class CMy1241Dlg : public CDialog
{
// Construction
public:
	CMy1241Dlg(CWnd* pParent = NULL);	// standard constructor
	CToolBar m_ToolBar;			// 工具栏对象
	CImageList m_ImageList;		// 列表视图对象
	CString m_TipText;			// 工具栏提示文本
// Dialog Data
	//{{AFX_DATA(CMy1241Dlg)
	enum { IDD = IDD_MY1241_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1241Dlg)
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
	afx_msg void OnNumber6();
	afx_msg void OnNumber7();
	afx_msg void OnNumber8();
	afx_msg BOOL OnToolTipNotify(UINT id,NMHDR* pNMHDR,LRESULT* pResult);
	// Generated message map functions
	//{{AFX_MSG(CMy1241Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1241DLG_H__E38B962A_CE25_47B6_88EB_59579C978047__INCLUDED_)
