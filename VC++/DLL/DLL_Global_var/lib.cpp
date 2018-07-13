#include"lib.h"
#include"windows.h"
int dllGlobalVar;

BOOL APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call,
					  LPVOID lpReserved)
{
	switch(ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		dllGlobalVar=100;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return true;
}