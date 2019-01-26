// MFCDLL.h : main header file for the MFCDLL DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#ifdef MFCDLL_EXPORTS
#define WIN32DLL_API extern "C" __declspec(dllexport)
#else
#define WIN32DLL_API extern "C" __declspec(dllimport)
#endif

// CMFCDLLApp
// See MFCDLL.cpp for the implementation of this class
//

class CMFCDLLApp : public CWinApp
{
public:
	CMFCDLLApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern "C"  __declspec(dllexport) INT_PTR ShowDlg();
extern "C" __declspec(dllexport) int nDllValue;

