
// ListCtrl_1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CListCtrl_1App:
// See ListCtrl_1.cpp for the implementation of this class
//

class CListCtrl_1App : public CWinApp
{
public:
	CListCtrl_1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CListCtrl_1App theApp;