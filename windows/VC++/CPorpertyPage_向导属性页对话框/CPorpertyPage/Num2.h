#pragma once


// CNum2 �Ի���

class CNum2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CNum2)

public:
	CNum2();
	virtual ~CNum2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NUM2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
