
// 0827-2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy08272App:
// See 0827-2.cpp for the implementation of this class
//

class CMy08272App : public CWinApp
{
public:
	CMy08272App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy08272App theApp;