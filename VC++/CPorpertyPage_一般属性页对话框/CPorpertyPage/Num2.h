#pragma once


// CNum2 对话框

class CNum2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CNum2)

public:
	CNum2();
	virtual ~CNum2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NUM2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
