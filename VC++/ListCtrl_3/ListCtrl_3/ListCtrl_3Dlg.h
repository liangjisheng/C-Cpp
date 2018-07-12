
// ListCtrl_3Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CListCtrl_3Dlg dialog
class CListCtrl_3Dlg : public CDialogEx
{
// Construction
public:
	CListCtrl_3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LISTCTRL_3_DIALOG };

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
	afx_msg void OnBnClickedButtonSelect();		// 获取选中按钮
	afx_msg void OnBnClickedButtonDelete();		// 删除按钮
	CComboBox m_wndStyle;						// 列表控件风格，组合框控制
	CListCtrl m_wndList;						// 列表控件
	void InitListCtrl();						// 初始化列表控件
	afx_msg void OnCbnSelchangeCombo1();		// 风格组合框改变
	// 列表控件的双击事件
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	void ShowFile(CString strPath);				// 显示文件
};
