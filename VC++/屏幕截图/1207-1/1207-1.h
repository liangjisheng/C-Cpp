
// 1207-1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy12071App:
// See 1207-1.cpp for the implementation of this class
//

class CMy12071App : public CWinApp
{
public:
	CMy12071App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	ULONG_PTR m_gdiplusToken;
};

extern CMy12071App theApp;