
// Thread_CriticalSection.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CThread_CriticalSectionApp:
// See Thread_CriticalSection.cpp for the implementation of this class
//

class CThread_CriticalSectionApp : public CWinApp
{
public:
	CThread_CriticalSectionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CThread_CriticalSectionApp theApp;