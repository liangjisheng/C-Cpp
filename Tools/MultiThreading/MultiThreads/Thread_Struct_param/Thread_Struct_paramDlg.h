
// Thread_Struct_paramDlg.h : header file
//

#pragma once
#include "afxcmn.h"

struct ThreadInfo
{
	UINT nMilliSecond;
	CProgressCtrl *pCtrlProgress;
};

// CThread_Struct_paramDlg dialog
class CThread_Struct_paramDlg : public CDialogEx
{
// Construction
public:
	CThread_Struct_paramDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_THREAD_STRUCT_PARAM_DIALOG };

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
	DWORD m_dwThreadID;
	ThreadInfo m_Info;
	CProgressCtrl m_ctrlProgress;
	afx_msg void OnBnClickedButtonStart();
};
