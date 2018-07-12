
// 1102-7.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy11027App:
// See 1102-7.cpp for the implementation of this class
//

class CMy11027App : public CWinApp
{
public:
	CMy11027App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy11027App theApp;