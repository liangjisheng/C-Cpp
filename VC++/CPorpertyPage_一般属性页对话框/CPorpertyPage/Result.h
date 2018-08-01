#pragma once


// CResult 对话框

class CResult : public CPropertyPage
{
	DECLARE_DYNAMIC(CResult)

public:
	CResult();
	virtual ~CResult();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// virtual BOOL OnSetActive();
	// virtual BOOL OnWizardFinish();
};
