// SignalLampDlg.h : ͷ�ļ�
//

#pragma once
#include "signallampctrl.h"


// CSignalLampDlg �Ի���
class CSignalLampDlg : public CDialog
{
// ����
public:
	CSignalLampDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SIGNALLAMP_DIALOG };

	int				m_nState;
	CSignalLampCtrl	m_slDemo;

	protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	virtual BOOL	OnInitDialog();


// ʵ��
protected:
	HICON m_hIcon;

public:
	// ���ɵ���Ϣӳ�亯��
	afx_msg void	OnPaint();
	afx_msg HCURSOR	OnQueryDragIcon();
	afx_msg void	OnBnClickedRadioNormal();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
