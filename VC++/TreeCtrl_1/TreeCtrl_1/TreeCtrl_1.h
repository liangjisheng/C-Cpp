
// TreeCtrl_1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTreeCtrl_1App:
// See TreeCtrl_1.cpp for the implementation of this class
//

class CTreeCtrl_1App : public CWinApp
{
public:
	CTreeCtrl_1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTreeCtrl_1App theApp;