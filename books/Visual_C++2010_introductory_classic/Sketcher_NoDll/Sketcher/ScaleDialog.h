#pragma once


// CScaleDialog 对话框

class CScaleDialog : public CDialog
{
	DECLARE_DYNAMIC(CScaleDialog)

public:
	CScaleDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScaleDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCALE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Scale;
	virtual BOOL OnInitDialog();
};
