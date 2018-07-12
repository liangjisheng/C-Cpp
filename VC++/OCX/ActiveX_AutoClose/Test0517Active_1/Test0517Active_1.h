
// Test0517Active_1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTest0517Active_1App:
// See Test0517Active_1.cpp for the implementation of this class
//

class CTest0517Active_1App : public CWinApp
{
public:
	CTest0517Active_1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTest0517Active_1App theApp;