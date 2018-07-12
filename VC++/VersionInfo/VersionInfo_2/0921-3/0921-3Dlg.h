
// 0921-3Dlg.h : header file
//

#pragma once


// CMy09213Dlg dialog
class CMy09213Dlg : public CDialogEx
{
// Construction
public:
	CMy09213Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY09213_DIALOG };

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
	void GetVersion(CString &strFileVersion, CString &strProductVersion);
	afx_msg void OnBnClickedButtonVersion();
	afx_msg void OnBnClickedButtonMsLs();
};
