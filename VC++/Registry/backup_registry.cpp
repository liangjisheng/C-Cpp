
// 备份注册表
// RegSaveKey(HKEY hkey,		// 要备份的键的句柄
//			LPCTSTR lpFile,		// 保存信息的文件名称
//			lpSecurityAttributes	// 文件安全属性
// );

// lpFile这个文件必须是不存在的，而且不能有扩展名

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

void main()
{
	TCHAR strKey[] = _T("SoftWare\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
	LPCTSTR szSaveFileName = _T("D:\\keyDate");
	HKEY hkey;
	// 申请备份权限
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if(!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return ;

	//申请SE_BACKUP_NAME权限
	LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

	//开始备份工作
	//注意文件不可存在否则无法成功
	long lResult;
	lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, strKey, 0, KEY_ALL_ACCESS, &hkey);
	if(ERROR_SUCCESS == lResult)
		RegSaveKey(hkey, szSaveFileName, NULL);

	RegCloseKey(hkey);

	printf("backup ok\n");
	getchar();
}