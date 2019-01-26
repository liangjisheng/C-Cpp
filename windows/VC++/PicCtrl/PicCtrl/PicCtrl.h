
// PicCtrl.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPicCtrlApp:
// See PicCtrl.cpp for the implementation of this class
//

class CPicCtrlApp : public CWinApp
{
public:
	CPicCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPicCtrlApp theApp;