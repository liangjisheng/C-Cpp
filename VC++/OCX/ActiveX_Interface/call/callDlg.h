
// callDlg.h : header file
//

#pragma once
#include "CDMy0602Active1.h"

// CcallDlg dialog
class CcallDlg : public CDialogEx
{
// Construction
public:
	CcallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CALL_DIALOG };

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
	CWnd m_ocxWnd;
	int m_nID;
	CDMy0602Active1 m_ocx;
	afx_msg void OnBnClickedButton1();
};
