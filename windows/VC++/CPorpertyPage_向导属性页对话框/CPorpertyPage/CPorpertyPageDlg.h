
// CPorpertyPageDlg.h : ͷ�ļ�
//

#pragma once


// CCPorpertyPageDlg �Ի���
class CCPorpertyPageDlg : public CDialogEx
{
// ����
public:
	CCPorpertyPageDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CPORPERTYPAGE_DIALOG };
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
	afx_msg void OnBnClickedInstructButton();
	double m_dNum1;
	double m_dNum2;
	double m_dResult;
	afx_msg void OnBnClickedButtonAdd();
};
