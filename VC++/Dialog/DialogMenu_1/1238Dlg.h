// 1238Dlg.h : header file
//

#if !defined(AFX_1238DLG_H__10D39276_4FE7_4DB2_8F9B_02DB88552C97__INCLUDED_)
#define AFX_1238DLG_H__10D39276_4FE7_4DB2_8F9B_02DB88552C97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1238Dlg dialog

class CMy1238Dlg : public CDialog
{
// Construction
public:
	CMy1238Dlg(CWnd* pParent = NULL);	// standard constructor
	CMenu m_Menu;
// Dialog Data
	//{{AFX_DATA(CMy1238Dlg)
	enum { IDD = IDD_MY1238_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1238Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	afx_msg void OnMenucat();		// 声明菜单消息处理函数
	afx_msg void OnMenudog();
	afx_msg void OnMenumonkey();
	afx_msg void OnMenuLi();
// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CMy1238Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1238DLG_H__10D39276_4FE7_4DB2_8F9B_02DB88552C97__INCLUDED_)
