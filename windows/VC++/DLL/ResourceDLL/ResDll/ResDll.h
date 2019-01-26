// ResDll.h : main header file for the ResDll DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CResDllApp
// See ResDll.cpp for the implementation of this class
//

class CResDllApp : public CWinApp
{
public:
	CResDllApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
