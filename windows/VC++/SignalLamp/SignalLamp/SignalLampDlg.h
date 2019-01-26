// SignalLampDlg.h : 头文件
//

#pragma once
#include "signallampctrl.h"


// CSignalLampDlg 对话框
class CSignalLampDlg : public CDialog
{
// 构造
public:
	CSignalLampDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SIGNALLAMP_DIALOG };

	int				m_nState;
	CSignalLampCtrl	m_slDemo;

	protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual BOOL	OnInitDialog();


// 实现
protected:
	HICON m_hIcon;

public:
	// 生成的消息映射函数
	afx_msg void	OnPaint();
	afx_msg HCURSOR	OnQueryDragIcon();
	afx_msg void	OnBnClickedRadioNormal();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
