
// ��ȡע����ȡ��������Ѱ�װ�������Ϣ
// ��windowsϵͳ�У���װ�������Ϣ�������������ע���·�����ҵ�
// 32bit: HKEY_LOCAL_MACHINE\SoftWare\Microsoft\Windows\CurrentVersion\Uninstall
// 63bit: HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall
// ��ȡ��װ����ľ�����Ϣ,��������ļ�

#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;

// ���ڼ�¼��װ�����Ϣ�Ľṹ��
struct ApplicationInfoA
{
	string strName;				// ������б�ʾ�������
	string strDisplayName;		// ��ʾ�������
	string strPublisher;		// ������
	string strVersion;			// �汾
	string strDisplayVersion;	// ��ʾ�İ汾
	string strInstallLocation;	// ��װ��λ��

	ApplicationInfoA()
	{
		strName = "";
		strDisplayName = "";
		strPublisher = "";
		strVersion = "";
		strDisplayVersion = "";
		strInstallLocation = "";
	}
};

// ��ȡ����ĳ���ļ�ֵdata���ɹ�����0��ʧ�ܷ���-1
int _GetAppInfoA(HKEY hKey, LPCSTR lpszAppName, LPCSTR lpszKeyValueName, string& strKeyValue)
{
	long lReturn;
	HKEY hInstallAppKey;

	// ���Ѱ�װ�����ע����
	lReturn = RegOpenKeyExA(hKey, lpszAppName, 0, KEY_ALL_ACCESS, &hInstallAppKey);
	if(ERROR_SUCCESS != lReturn)
		return -1;

	// ��ȡ�Ѱ�װ�����ע�����ļ�ֵ
	DWORD dwKeyValueType = REG_SZ;
	DWORD dwKeyValueDataSize = 0;
	// ��ȡ�ַ�����С(Ĭ��Ϊ�ַ�����REG_SZ)
	// dwKeyValueDataSize����hInstallAppKey��ֵ������ݳ���(��Ϊ�����ڶ�������ΪNULL)
	// dwKeyValueType���ش˼�ֵ�����ݵ�����
	lReturn = RegQueryValueExA(hInstallAppKey, lpszKeyValueName, 
		NULL, &dwKeyValueType, NULL, &dwKeyValueDataSize);
	if(ERROR_FILE_NOT_FOUND == lReturn)
	{
		RegCloseKey(hInstallAppKey);
		return 0;
	}
	else if(lReturn != ERROR_SUCCESS)
	{
		RegCloseKey(hInstallAppKey);
		return -1;
	}

	// ��ȡ�ַ���ֵ����������ַ��������򷵻أ��еİ�װ������Ϊ�ַ�����Ϊ�������ͣ������
	if(dwKeyValueType != REG_SZ)
	{
		RegCloseKey(hInstallAppKey);
		return 0;
	}

	LPSTR lpszKeyValueData = new char[dwKeyValueDataSize + 1];
	memset(lpszKeyValueData, 0, dwKeyValueDataSize + 1);
	lReturn = RegQueryValueExA(hInstallAppKey, lpszKeyValueName, NULL, 
		&dwKeyValueType, (LPBYTE)lpszKeyValueData, &dwKeyValueDataSize);

	if(lReturn != ERROR_SUCCESS)
	{
		delete [] lpszKeyValueData;
		RegCloseKey(hInstallAppKey);
		return -1;
	}

	strKeyValue = lpszKeyValueData;
	delete [] lpszKeyValueData;

	RegCloseKey(hInstallAppKey);

	return 0;
}

// ��ȡ�Ѱ�װ�ĳ�����Ϣ���洢�ڲ���vector�У��ɹ�����0��ʧ�ܷ���-1
int GetAllInstalledAppInfoA(vector<ApplicationInfoA>& vecAppInfo)
{
	long lReturn;

	HKEY hKey;
	LPCSTR lpszSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
	lReturn = RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpszSubKey, 0, KEY_ALL_ACCESS, &hKey);
	if(lReturn != ERROR_SUCCESS)
		return -1;

	// ��ȡ�Ӽ�&��ֵ��Ϣ
	DWORD dwSubKeysCnt;				// �Ӽ�����
	DWORD dwMaxSubKeyNameLen;		// �Ӽ����ֵ���󳤶�(��������β��\0)
	DWORD dwKeyValueCnt;			// ��ֵ������
	DWORD dwMaxKeyValueNameLen;		// ��ֵ���ֵ���󳤶�(��������β��\0)
	DWORD dwMaxKeyValueDataLen;		// ��ֵ���ݵ���󳤶�(in Bytes)

	lReturn = RegQueryInfoKeyA(hKey, NULL, NULL, NULL, &dwSubKeysCnt, &dwMaxSubKeyNameLen,
		NULL, &dwKeyValueCnt, &dwMaxKeyValueNameLen, &dwMaxKeyValueDataLen, NULL, NULL);
	if(lReturn != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return -1;
	}

	// ö���Ӽ���Ϣ
	DWORD dwIndex;
	LPSTR lpszSubKeyName = new char[dwMaxSubKeyNameLen + 1];
	DWORD dwNameLen = dwMaxSubKeyNameLen + 1;

	for (dwIndex = 0; dwIndex < dwSubKeysCnt; ++dwIndex)
	{
		dwNameLen = dwMaxSubKeyNameLen + 1;
		memset(lpszSubKeyName, 0, dwMaxSubKeyNameLen + 1);

		lReturn = RegEnumKeyExA(hKey, dwIndex, lpszSubKeyName, &dwNameLen, 
			NULL, NULL, NULL, NULL);
		if(lReturn != ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			delete [] lpszSubKeyName;
			return -1;
		}

		// ��ȡ����ĳ���İ�װ��Ϣ
		ApplicationInfoA appInfo;
		appInfo.strName = lpszSubKeyName;
		_GetAppInfoA(hKey, lpszSubKeyName, "DisplayName", appInfo.strDisplayName);
		_GetAppInfoA(hKey, lpszSubKeyName, "Publisher", appInfo.strPublisher);
		_GetAppInfoA(hKey, lpszSubKeyName, "Version", appInfo.strVersion);
		_GetAppInfoA(hKey, lpszSubKeyName, "DisplayVersion", appInfo.strDisplayVersion);
		_GetAppInfoA(hKey, lpszSubKeyName, "InstallLocation", appInfo.strInstallLocation);
		vecAppInfo.push_back(appInfo);
	}

	delete [] lpszSubKeyName;
	RegCloseKey(hKey);

	return 0;
}


int main()
{
	cout << "Reg Demo Test" << endl;
	vector<ApplicationInfoA> vecAppInfo;
	cout << GetAllInstalledAppInfoA(vecAppInfo) << endl;

	// ������ļ�
	ofstream ofs("InstalledAppInfo.txt", std::ios_base::app);
	vector<ApplicationInfoA>::iterator iter = vecAppInfo.begin();
	while(iter != vecAppInfo.end())
	{
		ofs << "Name: " << iter->strName << endl
			<< "DisplayName: " << iter->strDisplayName << endl
			<< "Publisher: " << iter->strPublisher << endl
			<< "Version: " << iter->strVersion << endl
			<< "DisplayVersion: " << iter->strDisplayVersion << endl
			<< "InstallLocation: " << iter->strInstallLocation << endl;
		ofs << endl;
		++iter;
	}
	ofs.close();

	system("pause");
	return 0;
}

