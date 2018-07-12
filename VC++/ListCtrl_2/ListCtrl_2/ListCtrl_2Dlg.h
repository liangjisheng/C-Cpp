
// ListCtrl_2Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CListCtrl_2Dlg dialog
class CListCtrl_2Dlg : public CDialogEx
{
// Construction
public:
	CListCtrl_2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LISTCTRL_2_DIALOG };

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
	CListCtrl m_list;
	void test_listctrl();
	// 单击某一列表项
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	// 单击某一列的标题进行排序
	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
