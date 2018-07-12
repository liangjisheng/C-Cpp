
// ListCtrl_1Dlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "ListCtrlEx.h"

// CListCtrl_1Dlg dialog
class CListCtrl_1Dlg : public CDialogEx
{
// Construction
public:
	CListCtrl_1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LISTCTRL_1_DIALOG };

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
	CListCtrlEx m_ListCtrl;							// 列表控件变量
	afx_msg void OnBnClickedTest1();				// test_1
	afx_msg void OnBnClickedButtonTest2();			// test_2
	afx_msg void OnBnClickedRadioAllSel();			// 全选
	afx_msg void OnBnClickedRadioReverseSel();		// 反选
	afx_msg void OnNMCustomdrawListTest(NMHDR *pNMHDR, LRESULT *pResult);
};
