
// callDlg.h : 头文件
//

#pragma once
#include "..\\0610-6\\0610-6.h"
#pragma comment(lib, "..\\Debug\\0610-6.lib")

// CcallDlg 对话框
class CcallDlg : public CDialogEx
{
// 构造
public:
	CcallDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CHookTest m_HookTest;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
