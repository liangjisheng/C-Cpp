// 0517Active_1.cpp : Implementation of CMy0517Active_1App and DLL registration.

#include "stdafx.h"
#include "0517Active_1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMy0517Active_1App theApp;

const GUID CDECL _tlid = { 0x2380D1B, 0x2096, 0x4206, { 0x86, 0x27, 0xF2, 0xE6, 0xAB, 0xF0, 0x2A, 0x2A } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMy0517Active_1App::InitInstance - DLL initialization

BOOL CMy0517Active_1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CMy0517Active_1App::ExitInstance - DLL termination

int CMy0517Active_1App::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
