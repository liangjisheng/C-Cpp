#pragma once


// CPenDialog �Ի���

class CPenDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPenDialog)

public:
	CPenDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPenDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PENWIDTH_DLG };
#endif
	int m_PenWidth;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPenwidth0();
	afx_msg void OnBnClickedPenwidth3();
	afx_msg void OnBnClickedPenwidth1();
	afx_msg void OnBnClickedPenwidth2();
	afx_msg void OnBnClickedPenwidth4();
	afx_msg void OnBnClickedPenwidth5();
};
