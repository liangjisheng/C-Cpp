
// Thread_int_param.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CThread_int_paramApp:
// See Thread_int_param.cpp for the implementation of this class
//

class CThread_int_paramApp : public CWinApp
{
public:
	CThread_int_paramApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CThread_int_paramApp theApp;