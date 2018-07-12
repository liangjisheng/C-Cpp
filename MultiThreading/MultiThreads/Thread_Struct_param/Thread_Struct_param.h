
// Thread_Struct_param.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CThread_Struct_paramApp:
// See Thread_Struct_param.cpp for the implementation of this class
//

class CThread_Struct_paramApp : public CWinApp
{
public:
	CThread_Struct_paramApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CThread_Struct_paramApp theApp;