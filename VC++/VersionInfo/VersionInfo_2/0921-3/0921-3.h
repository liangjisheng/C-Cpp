
// 0921-3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy09213App:
// See 0921-3.cpp for the implementation of this class
//

class CMy09213App : public CWinApp
{
public:
	CMy09213App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy09213App theApp;