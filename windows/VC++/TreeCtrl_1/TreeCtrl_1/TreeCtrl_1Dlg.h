
// TreeCtrl_1Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CTreeCtrl_1Dlg dialog
class CTreeCtrl_1Dlg : public CDialogEx
{
// Construction
public:
	CTreeCtrl_1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TREECTRL_1_DIALOG };

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
	CTreeCtrl m_wndTree;
	void InitTreeControl();
	void ShowFile(CString strPath, HTREEITEM hParent);
	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);	// 双击
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);	// 单击好像不管作用
};
