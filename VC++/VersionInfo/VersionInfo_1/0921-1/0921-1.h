
// 0921-1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy09211App:
// See 0921-1.cpp for the implementation of this class
//

class CMy09211App : public CWinApp
{
public:
	CMy09211App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy09211App theApp;