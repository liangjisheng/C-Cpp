
// Thread_CEventDlg.h : header file
//

#pragma once

UINT WriteD(LPVOID lpParam);
UINT WriteW(LPVOID lpParam);

// CThread_CEventDlg dialog
class CThread_CEventDlg : public CDialogEx
{
// Construction
public:
	CThread_CEventDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_THREAD_CEVENT_DIALOG };

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
	afx_msg void OnBnClickedButtonW();
};
