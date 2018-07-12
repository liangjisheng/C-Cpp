
// 1102-5Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CMy11025Dlg dialog
class CMy11025Dlg : public CDialogEx
{
// Construction
public:
	CMy11025Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY11025_DIALOG };

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
	// 获取系统安装程序列表
	bool AllRegKey(HKEY hKey, LPCTSTR szDesKeyItem);
	bool AllRegKey2(HKEY hKey, LPCTSTR szDesKeyItem);
	CListCtrl m_list;
	afx_msg void OnBnClickedButtonReadreg();
	afx_msg void OnBnClickedButtonReadreg2();
};
