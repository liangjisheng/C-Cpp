// 1074.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "1074.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


// This is an example of an exported variable
MY1074_API int n=0;

// This is an example of an exported function.
MY1074_API int fnMy1074(void)
{
	printf("lishuyu\n");
	return 0;
}

// This is the constructor of a class that has been exported.
// see 1074.h for the class definition
CMy1074::CMy1074()
{ 
	printf("constructor function call\n");
	return; 
}

