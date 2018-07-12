#pragma once

#define WM_CALCULATE WM_USER + 1
#define WM_DISPLAY WM_USER + 2

// CCalculateThread

class CCalculateThread : public CWinThread
{
	DECLARE_DYNCREATE(CCalculateThread)

protected:
	CCalculateThread();           // protected constructor used by dynamic creation
	virtual ~CCalculateThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCalculate(WPARAM wParam, LPARAM lParam);
};


