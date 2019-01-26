
// ListCtrl_4Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CListCtrl_4Dlg dialog
class CListCtrl_4Dlg : public CDialogEx
{
// Construction
public:
	CListCtrl_4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LISTCTRL_4_DIALOG };

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
	void InitListCtrl();
};
