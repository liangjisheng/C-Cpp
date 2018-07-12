
// WrokThreadDlg.h : header file
//

#pragma once
#include "afxcmn.h"

struct ThreadInfo
{
	UINT nMilliSecond;
	CProgressCtrl *pCtrlProgress;
};


// CWrokThreadDlg dialog
class CWrokThreadDlg : public CDialogEx
{
// Construction
public:
	CWrokThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WROKTHREAD_DIALOG };

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
	HANDLE m_hThread;
	DWORD m_dwTheadID;
	ThreadInfo m_Info;
	CProgressCtrl m_ctrlProgress;
	afx_msg void OnBnClickedButtonStart();
};
