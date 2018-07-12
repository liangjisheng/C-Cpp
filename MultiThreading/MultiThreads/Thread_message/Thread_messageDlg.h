
// Thread_messageDlg.h : header file
//

#pragma once
#include "CalculateThread.h"


// CThread_messageDlg dialog
class CThread_messageDlg : public CDialogEx
{
// Construction
public:
	CThread_messageDlg(CWnd* pParent = NULL);	// standard constructor
	CCalculateThread *m_pCalculateThread;

// Dialog Data
	enum { IDD = IDD_THREAD_MESSAGE_DIALOG };

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

	int m_nAddEnd;
	LRESULT OnDisplay(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButtonSum();
};
