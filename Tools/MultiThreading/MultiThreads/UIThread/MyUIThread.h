#pragma once

#include "MyUIThreadDlg.h"

// CMyUIThread

class CMyUIThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyUIThread)

protected:
	CMyUIThread();           // protected constructor used by dynamic creation
	virtual ~CMyUIThread();

	CMyUIThreadDlg m_dlg;

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


