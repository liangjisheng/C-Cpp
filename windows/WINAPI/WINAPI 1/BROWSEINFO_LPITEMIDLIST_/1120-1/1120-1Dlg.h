
// 1120-1Dlg.h : ͷ�ļ�
//

#pragma once


// CMy11201Dlg �Ի���
class CMy11201Dlg : public CDialogEx
{
// ����
public:
	CMy11201Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY11201_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	// ���ļ�Ŀ¼ת���ɶ�Ӧ��LPITEMIDLIST
	LPITEMIDLIST ParsePidlFromPath(LPTSTR pszPath);
	// ��ָ��Ŀ¼
	void OpenDir(LPTSTR pszPath);
	void OpenDir1(LPTSTR pszPath);
};
