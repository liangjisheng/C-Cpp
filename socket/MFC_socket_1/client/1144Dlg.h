// 1144Dlg.h : header file
//

#if !defined(AFX_1144DLG_H__B794A0DA_59FA_4A1B_B295_35BC5D637C80__INCLUDED_)
#define AFX_1144DLG_H__B794A0DA_59FA_4A1B_B295_35BC5D637C80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ClientSocket.h"

class CMy1144Dlg : public CDialog
{
// Construction
public:
	CMy1144Dlg(CWnd* pParent = NULL);	// standard constructor
	CClientSocket c;
// Dialog Data
	//{{AFX_DATA(CMy1144Dlg)
	enum { IDD = IDD_MY1144_DIALOG };
	CEdit	m_sEdit;
	CEdit	m_rEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1144Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1144Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1144DLG_H__B794A0DA_59FA_4A1B_B295_35BC5D637C80__INCLUDED_)
