#pragma once


// CNum1 �Ի���

class CNum1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CNum1)

public:
	CNum1();
	virtual ~CNum1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NUM1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
