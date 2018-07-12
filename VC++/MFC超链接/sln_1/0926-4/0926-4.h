
// 0926-4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy09264App:
// See 0926-4.cpp for the implementation of this class
//

class CMy09264App : public CWinApp
{
public:
	CMy09264App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy09264App theApp;