
// ProgressDlg.h : header file
//

#pragma once


// CProgressDlg dialog
class CProgressDlg : public CDialogEx
{
// Construction
public:
	CProgressDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PROGRESS_DIALOG };

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
	LRESULT OnMsg(WPARAM wp, LPARAM lp);
	afx_msg void OnBnClickedButtonStart();
};
