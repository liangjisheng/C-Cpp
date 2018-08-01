
// 1120-1Dlg.h : 头文件
//

#pragma once


// CMy11201Dlg 对话框
class CMy11201Dlg : public CDialogEx
{
// 构造
public:
	CMy11201Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY11201_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	// 将文件目录转换成对应的LPITEMIDLIST
	LPITEMIDLIST ParsePidlFromPath(LPTSTR pszPath);
	// 打开指定目录
	void OpenDir(LPTSTR pszPath);
	void OpenDir1(LPTSTR pszPath);
};
