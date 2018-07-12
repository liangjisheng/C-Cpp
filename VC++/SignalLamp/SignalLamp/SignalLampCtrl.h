#pragma once

#define		STR_CLASS_NAME		_T("CSignalLampCtrl")

// CSignalLampCtrl

class CSignalLampCtrl : public CWnd
{
	DECLARE_DYNAMIC(CSignalLampCtrl)

	enum	StateType{Normal, Warning, Disable};

	int		nIDBitmap;
public:
	CSignalLampCtrl();
	virtual ~CSignalLampCtrl();

	void	RegisterCtrlClass();
	void	SetState(StateType nState);

protected:
	virtual void PreSubclassWindow();

public:
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()
};