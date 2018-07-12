
// ListCtrl_4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CListCtrl_4App:
// See ListCtrl_4.cpp for the implementation of this class
//

class CListCtrl_4App : public CWinApp
{
public:
	CListCtrl_4App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CListCtrl_4App theApp;