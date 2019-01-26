// 0515Active_1.cpp : Implementation of CMy0515Active_1App and DLL registration.

#include "stdafx.h"
#include "0515Active_1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMy0515Active_1App theApp;

const GUID CDECL _tlid = { 0xEC724B27, 0x9859, 0x4CDB, { 0xBF, 0xB3, 0x50, 0x8E, 0x0, 0xD7, 0x30, 0x66 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMy0515Active_1App::InitInstance - DLL initialization

BOOL CMy0515Active_1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CMy0515Active_1App::ExitInstance - DLL termination

int CMy0515Active_1App::ExitInstance()
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
