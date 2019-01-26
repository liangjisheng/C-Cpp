
// 1102-7Dlg.h : header file
//

#pragma once


// CMy11027Dlg dialog
class CMy11027Dlg : public CDialogEx
{
// Construction
public:
	CMy11027Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY11027_DIALOG };

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
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonWrite();
	afx_msg void OnBnClickedButtonWrite1();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonDeletekey();
};
