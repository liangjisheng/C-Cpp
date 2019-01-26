
// 判断Window系统和进程是32还是64位

#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;


BOOL Is64BitOS()
{
	typedef void (WINAPI *LPFN_GetNativeSystemInfo)(__out LPSYSTEM_INFO lpSystemInfo);
	LPFN_GetNativeSystemInfo fnGetNativeSystemInfo = (LPFN_GetNativeSystemInfo)
		GetProcAddress(GetModuleHandle(TEXT("kernel32")), "GetNativeSystemInfo");
	if(fnGetNativeSystemInfo)
	{
		SYSTEM_INFO stInfo = {0};
		fnGetNativeSystemInfo(&stInfo);
		if(stInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64		// Inten奔腾系列
			|| stInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			return TRUE;
	}
	return FALSE;
}

// 判断一个进程是32位还是64位，此函数只能在64位系统上调用
// 参数表示进程ID
BOOL Is64BitProcess(DWORD dwProcessID)
{
	if(!Is64BitOS())
		return FALSE;
	else
	{
		// 通过进程ID获得进程句柄
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwProcessID);
		if(hProcess)
		{
			typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
			LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)
				GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
			if(NULL != fnIsWow64Process)
			{
				BOOL bIsWow64 = FALSE;
				fnIsWow64Process(hProcess, &bIsWow64);
				CloseHandle(hProcess);

				if(bIsWow64)
					return TRUE;
				else
					return FALSE;
			}
		}
	}

	return FALSE;
}

// 判断一个进程是32位还是64位，此函数只能在64位系统上调用
// 参数表示进程句柄
BOOL Is64BitProcess(HANDLE hProcess)
{
	if(!Is64BitOS())
		return FALSE;
	else
	{
		if(hProcess)
		{
			typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
			LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)
				GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
			if(NULL != fnIsWow64Process)
			{
				BOOL bIsWow64 = FALSE;
				fnIsWow64Process(hProcess, &bIsWow64);
				CloseHandle(hProcess);

				if(bIsWow64)
					return TRUE;
				else
					return FALSE;
			}
		}
	}
}


int main()
{
	BOOL is64bitos = Is64BitOS();
	if(is64bitos)
		cout << "64 bit operator system" << endl;
	else
		cout << "32 bit operator system" << endl;

	// 64位的操作系统上运行着64位的进程
	BOOL is64Porcess = Is64BitProcess(GetCurrentProcess());
	if(is64Porcess)
		cout << "64 bit process" << endl;
	else
		cout << "32 bit process" << endl;

	system("pause");
	return 0;
}