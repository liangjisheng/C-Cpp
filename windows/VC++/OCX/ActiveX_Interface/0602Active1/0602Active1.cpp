// 0602Active1.cpp : Implementation of CMy0602Active1App and DLL registration.

#include "stdafx.h"
#include "0602Active1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMy0602Active1App theApp;

const GUID CDECL _tlid = { 0x77B660CE, 0xF293, 0x4325, { 0xB0, 0xBE, 0xC8, 0x82, 0xB4, 0xA0, 0x7C, 0xED } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMy0602Active1App::InitInstance - DLL initialization

BOOL CMy0602Active1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CMy0602Active1App::ExitInstance - DLL termination

int CMy0602Active1App::ExitInstance()
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
