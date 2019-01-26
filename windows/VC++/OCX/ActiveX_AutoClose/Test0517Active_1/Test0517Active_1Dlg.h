
// Test0517Active_1Dlg.h : header file
//

#pragma once
#include "Dlg1.h"

// CTest0517Active_1Dlg dialog
class CTest0517Active_1Dlg : public CDialogEx 
{
// Construction
public:
	CTest0517Active_1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEST0517ACTIVE_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDlg1 m_dlg;
	afx_msg void OnBnClickedButton1();
};
