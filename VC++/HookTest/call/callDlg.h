
// callDlg.h : ͷ�ļ�
//

#pragma once
#include "..\\0610-6\\0610-6.h"
#pragma comment(lib, "..\\Debug\\0610-6.lib")

// CcallDlg �Ի���
class CcallDlg : public CDialogEx
{
// ����
public:
	CcallDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
