#pragma once


// CResult �Ի���

class CResult : public CPropertyPage
{
	DECLARE_DYNAMIC(CResult)

public:
	CResult();
	virtual ~CResult();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// virtual BOOL OnSetActive();
	// virtual BOOL OnWizardFinish();
};
