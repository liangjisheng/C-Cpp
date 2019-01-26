
// Thread_CriticalSectionDlg.h : header file
//

#pragma once

UINT WriteW(LPVOID pParam);
UINT WriteD(LPVOID pParam);

// CThread_CriticalSectionDlg dialog
class CThread_CriticalSectionDlg : public CDialogEx
{
// Construction
public:
	CThread_CriticalSectionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_THREAD_CRITICALSECTION_DIALOG };

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
	afx_msg void OnBnClickedButtonWritew();
	afx_msg void OnBnClickedButtonWrited();
};
