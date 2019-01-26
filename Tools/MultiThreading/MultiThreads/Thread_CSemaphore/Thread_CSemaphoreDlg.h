
// Thread_CSemaphoreDlg.h : header file
//

#pragma once

UINT WriteA(LPVOID lpParam);
UINT WriteB(LPVOID lpParam);
UINT WriteC(LPVOID lpParam);

// CThread_CSemaphoreDlg dialog
class CThread_CSemaphoreDlg : public CDialogEx
{
// Construction
public:
	CThread_CSemaphoreDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_THREAD_CSEMAPHORE_DIALOG };

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
	afx_msg void OnBnClickedButtonStart();
};
