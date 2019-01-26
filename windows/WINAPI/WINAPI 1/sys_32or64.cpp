
// 此程序判读一个操作系统是32位还是64位的

#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

/**
 * Don't use the function IsWow64Process as a static function,
 * you should load it by function GetProcAddress, because
 * it is not available on all version of Windows.
 */
LPFN_ISWOW64PROCESS fnIsWow64Process = NULL;

bool GetWindowBit(bool &isWindow64bit)
{
#if _WIN64
	isWindow64bit = true;
	return true;
#elif _WIN32
	BOOL isWow64 = FALSE;
	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.
	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")),
		"IsWow64Process");
	if(fnIsWow64Process)
	{
		if(!fnIsWow64Process(GetCurrentProcess(), &isWow64))
			return false;
		if(isWow64)
			isWindow64bit = true;
		else
			isWindow64bit = false;
		return true;
	}
	else
		return false;
#else
	assert(0);
	return false;
#endif
}


int main()
{
	bool isWindow64 = false;
	GetWindowBit(isWindow64);
	if(isWindow64)
		cout << "64 bit operator system" << endl;
	else
		cout << "32 bit operator system" << endl;

	system("pause");
	return 0;
}