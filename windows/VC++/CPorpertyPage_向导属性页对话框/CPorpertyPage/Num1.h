#pragma once


// CNum1 对话框

class CNum1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CNum1)

public:
	CNum1();
	virtual ~CNum1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NUM1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
