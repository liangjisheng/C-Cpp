// 1143Dlg.h : header file
//

#if !defined(AFX_1143DLG_H__8D7115EA_08AE_4E9E_A30A_D26BC432771C__INCLUDED_)
#define AFX_1143DLG_H__8D7115EA_08AE_4E9E_A30A_D26BC432771C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ServerSocket.h"
#include "ClientSocket.h"

class CMy1143Dlg : public CDialog
{
// Construction
public:
	CMy1143Dlg(CWnd* pParent = NULL);	// standard constructor
	CServerSocket s;
	CClientSocket c;
// Dialog Data
	//{{AFX_DATA(CMy1143Dlg)
	enum { IDD = IDD_MY1143_DIALOG };
	CEdit	m_sEdit;
	CEdit	m_rEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1143Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1143Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1143DLG_H__8D7115EA_08AE_4E9E_A30A_D26BC432771C__INCLUDED_)
