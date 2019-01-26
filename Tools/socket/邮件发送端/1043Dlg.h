// 1043Dlg.h : header file
//

#if !defined(AFX_1043DLG_H__9B89AB0B_D415_43DD_BBA3_CA670A630A52__INCLUDED_)
#define AFX_1043DLG_H__9B89AB0B_D415_43DD_BBA3_CA670A630A52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Set.h"

/////////////////////////////////////////////////////////////////////////////
// CMy1043Dlg dialog

class CMy1043Dlg : public CDialog
{
// Construction
public:
	CMy1043Dlg(CWnd* pParent = NULL);	// standard constructor
	HWND statu;
	CFile file;
	SOCKET s;
	sockaddr_in addr;	// 网络地址结构变量
	hostent *host;		// 定义主机信息结构变量
// Dialog Data
	//{{AFX_DATA(CMy1043Dlg)
	enum { IDD = IDD_MY1043_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1043Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CSet set;
	// Generated message map functions
	//{{AFX_MSG(CMy1043Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLookhelp();
	afx_msg void OnConfig();
	afx_msg void OnSendmail();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1043DLG_H__9B89AB0B_D415_43DD_BBA3_CA670A630A52__INCLUDED_)
