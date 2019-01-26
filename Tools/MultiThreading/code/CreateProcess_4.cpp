
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <atlbase.h>
#include <TlHelp32.h>


/**
 * function: 提升进程权限
 * param: name:进程名
 * return: TRUE:提升成功，FALSE:失败
*/
BOOL EnablePrivilege(LPCTSTR name)
{
	BOOL bRet = FALSE;
	// 获得指定的权限值
	TOKEN_PRIVILEGES priv = { 1, { 0, 0, SE_PRIVILEGE_ENABLED } };
	BOOL bLookup = LookupPrivilegeValue(NULL, name, &priv.Privileges[0].Luid);
	if (!bLookup)
	{
		printf("查找指定权限值失败\n");
		return bRet;
	}

	// 打开进程访问标记
	HANDLE hToken = NULL;
	HANDLE hProcess = NULL;
	hProcess = GetCurrentProcess();
	BOOL bOpenToken = OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
	if (!bOpenToken)
	{
		printf("打开进程的访问标记失败\n");
		return bRet;
	}

	// 调整权限
	BOOL bAdjustPriv = AdjustTokenPrivileges(hToken, FALSE, &priv, sizeof(priv), 0, 0);
	if (!bAdjustPriv)
	{
		printf("调整权限失败\n");
		CloseHandle(hToken);
		return bRet;
	}

	CloseHandle(hToken);
	return TRUE;
}

/**
 * function: 通过进程名获得进程ID
 * param: lpszProcessName: 进程名
 * return: 0:获取失败
*/
DWORD FindProcessIDByProcessName(LPCTSTR lpszProcessName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (NULL == hSnapshot)
		return 0;

	int nStrlen = _tcslen(lpszProcessName);
	PROCESSENTRY32 stProcessEntry32 = {0};
	stProcessEntry32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &stProcessEntry32);
	BOOL bFind = FALSE;

	do {
		if (_tcsicmp(stProcessEntry32.szExeFile, lpszProcessName) == 0)
		{
			bFind = TRUE;
			break;
		}
	} while (Process32Next(hSnapshot, &stProcessEntry32));

	CloseHandle(hSnapshot);

	if (bFind)
		return stProcessEntry32.th32ProcessID;
	return 0;
}

int main()
{
	BOOL bRet = EnablePrivilege(SE_SECURITY_NAME);
	PROCESS_INFORMATION pi = {0};
	STARTUPINFOEX si = { sizeof(STARTUPINFOEX) };
	SIZE_T cbAListSize = 0;

	InitializeProcThreadAttributeList(NULL, 1, 0, &cbAListSize);
	PPROC_THREAD_ATTRIBUTE_LIST pAList = 
		(PPROC_THREAD_ATTRIBUTE_LIST)HeapAlloc(GetProcessHeap(), 0, cbAListSize);
	InitializeProcThreadAttributeList(pAList, 1, 0, &cbAListSize);

	HANDLE hParent = OpenProcess(PROCESS_ALL_ACCESS, FALSE,
		FindProcessIDByProcessName(TEXT("explorer.exe")));	// 要设置为父进程的句柄
	UpdateProcThreadAttribute(pAList, 0, PROC_THREAD_ATTRIBUTE_PARENT_PROCESS, 
		&hParent, sizeof(HANDLE), NULL, NULL);

	si.lpAttributeList = pAList;
	TCHAR szPorcess[] = TEXT("notepad.exe");
	CreateProcess(NULL, szPorcess, NULL, NULL, FALSE, 
		EXTENDED_STARTUPINFO_PRESENT, NULL, NULL, &si.StartupInfo, &pi);

	DeleteProcThreadAttributeList(pAList);
	HeapFree(GetProcessHeap(), 0, pAList);
	
	system("pause");
	return 0;
}

