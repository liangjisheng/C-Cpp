
// 判断一个exe是否运行在Windows x64下，使用Windows	API函数
// IsWow64Process()

/**
 *   This program test if this application is a x64 program or
 *   is a x86 program running under Windows x64.
 */

#include <windows.h>
#include <tchar.h>
// #include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
using std::wcout;

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

/**
 * Don't use the function IsWow64Process as a static function,
 * you should load it by function GetProcAddress, because
 * it is not available on all version of Windows.
 */
LPFN_ISWOW64PROCESS fnIsWow64Process = NULL;

// This function tells if your application is a x64 program.
BOOL Isx64Application() 
{ return (sizeof(LPFN_ISWOW64PROCESS) == 8) ? TRUE : FALSE; }

// This function tells if you're under Windows x64.
BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;
	if(!fnIsWow64Process)
		fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")),
		"IsWow64Process");

	if(fnIsWow64Process)
		if(!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
			return FALSE;

	return bIsWow64;
}


int main()
{
	if(Isx64Application())
		wcout << TEXT("The application is a x64 program.") << endl;
	else
	{
		if(!IsWow64())
			wcout << TEXT("The application is running under Windows x86") << endl;
		else
			wcout << TEXT("The application is a x86 program running under Windows x64") << endl;
	}

	system("pause");
	return 0;
}