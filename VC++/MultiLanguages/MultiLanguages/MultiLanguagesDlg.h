
// MultiLanguagesDlg.h : ͷ�ļ�
//

#pragma once


// CMultiLanguagesDlg �Ի���
class CMultiLanguagesDlg : public CDialogEx
{
// ����
public:
	CMultiLanguagesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MULTILANGUAGES_DIALOG };

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
	bool m_bRestartFlag;				// �رմ������Ƿ���Ҫ��������
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLanguageTrans();
	afx_msg void OnClose();
};
