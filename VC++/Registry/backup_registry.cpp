
// ����ע���
// RegSaveKey(HKEY hkey,		// Ҫ���ݵļ��ľ��
//			LPCTSTR lpFile,		// ������Ϣ���ļ�����
//			lpSecurityAttributes	// �ļ���ȫ����
// );

// lpFile����ļ������ǲ����ڵģ����Ҳ�������չ��

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

void main()
{
	TCHAR strKey[] = _T("SoftWare\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
	LPCTSTR szSaveFileName = _T("D:\\keyDate");
	HKEY hkey;
	// ���뱸��Ȩ��
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if(!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return ;

	//����SE_BACKUP_NAMEȨ��
	LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

	//��ʼ���ݹ���
	//ע���ļ����ɴ��ڷ����޷��ɹ�
	long lResult;
	lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, strKey, 0, KEY_ALL_ACCESS, &hkey);
	if(ERROR_SUCCESS == lResult)
		RegSaveKey(hkey, szSaveFileName, NULL);

	RegCloseKey(hkey);

	printf("backup ok\n");
	getchar();
}