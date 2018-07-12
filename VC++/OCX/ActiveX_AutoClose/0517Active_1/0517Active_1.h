#pragma once

// 0517Active_1.h : main header file for 0517Active_1.DLL

#if !defined( __AFXCTL_H__ )
#error "include 'afxctl.h' before including this file"
#endif

#include "resource.h"       // main symbols


// CMy0517Active_1App : See 0517Active_1.cpp for implementation.

class CMy0517Active_1App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

