
// Thread_CSemaphore.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CThread_CSemaphoreApp:
// See Thread_CSemaphore.cpp for the implementation of this class
//

class CThread_CSemaphoreApp : public CWinApp
{
public:
	CThread_CSemaphoreApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CThread_CSemaphoreApp theApp;