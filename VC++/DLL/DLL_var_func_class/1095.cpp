// 1095.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "1095.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			printf("DLL_PROCESS_ATTACH\n");
			nMy1095=100;
			break;
		case DLL_THREAD_ATTACH:
			printf("DLL_THREAD_ATTACH\n");
			break;
		case DLL_THREAD_DETACH:
			printf("DLL_THREAD_DETACH\n");
			break;
		case DLL_PROCESS_DETACH:
			printf("DLL_PROCESS_DETACH\n");
			break;
    }
    return TRUE;
}


// This is an example of an exported variable
MY1095_API int nMy1095=0;

// This is an example of an exported function.
MY1095_API int fnMy1095(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see 1095.h for the class definition
CMy1095::CMy1095()
{ 
	printf("constructor function\n");
	return; 
}