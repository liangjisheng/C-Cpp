
// 0827-2Dlg.h : header file
//

#pragma once


// CMy08272Dlg dialog
class CMy08272Dlg : public CDialogEx
{
// Construction
public:
	CMy08272Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY08272_DIALOG };

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
	afx_msg void OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslink4(NMHDR *pNMHDR, LRESULT *pResult);
	int nClicks;
	CString GetClickText() const;
	void SetLink4Text();
	afx_msg void OnNMClickSyslink2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslink3(NMHDR *pNMHDR, LRESULT *pResult);
};
