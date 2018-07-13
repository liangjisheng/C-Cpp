// 1251Dlg.h : header file
//

#if !defined(AFX_1251DLG_H__AA22E2D6_1B2F_4E41_9BEF_5E768B791869__INCLUDED_)
#define AFX_1251DLG_H__AA22E2D6_1B2F_4E41_9BEF_5E768B791869__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1251Dlg dialog

class CMy1251Dlg : public CDialog
{
// Construction
public:
	CMy1251Dlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;
	CString m_StrText;
	
	// 判断当前节点的复选框是否被选中
	void CheckToTree(HTREEITEM m_Item);
	// Dialog Data
	//{{AFX_DATA(CMy1251Dlg)
	enum { IDD = IDD_MY1251_DIALOG };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1251Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1251Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGettext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1251DLG_H__AA22E2D6_1B2F_4E41_9BEF_5E768B791869__INCLUDED_)
