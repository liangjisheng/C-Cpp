
// 读取注册表获取计算机上已安装程序的信息
// 在windows系统中，安装程序的信息都可以在下面的注册表路径中找到
// 32bit: HKEY_LOCAL_MACHINE\SoftWare\Microsoft\Windows\CurrentVersion\Uninstall
// 63bit: HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall
// 获取安装程序的具体信息,并输出到文件

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

// 用于记录安装软件信息的结构体
struct ApplicationInfoA
{
	string strName;				// 计算机中表示的软件名
	string strDisplayName;		// 显示的软件名
	string strPublisher;		// 发布者
	string strVersion;			// 版本
	string strDisplayVersion;	// 显示的版本
	string strInstallLocation;	// 安装的位置

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

// 获取具体的程序的键值data，成功返回0，失败返回-1
int _GetAppInfoA(HKEY hKey, LPCSTR lpszAppName, LPCSTR lpszKeyValueName, string& strKeyValue)
{
	long lReturn;
	HKEY hInstallAppKey;

	// 打开已安装软件的注册表键
	lReturn = RegOpenKeyExA(hKey, lpszAppName, 0, KEY_ALL_ACCESS, &hInstallAppKey);
	if(ERROR_SUCCESS != lReturn)
		return -1;

	// 获取已安装软件的注册表键的键值
	DWORD dwKeyValueType = REG_SZ;
	DWORD dwKeyValueDataSize = 0;
	// 获取字符串大小(默认为字符串即REG_SZ)
	// dwKeyValueDataSize返回hInstallAppKey键值项的数据长度(因为倒数第二个参数为NULL)
	// dwKeyValueType返回此键值项数据的类型
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

	// 获取字符串值，如果不是字符串类型则返回，有的安装程序此项不为字符串而为其它类型，则忽略
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

// 获取已安装的程序信息并存储于参数vector中，成功返回0，失败返回-1
int GetAllInstalledAppInfoA(vector<ApplicationInfoA>& vecAppInfo)
{
	long lReturn;

	HKEY hKey;
	LPCSTR lpszSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
	lReturn = RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpszSubKey, 0, KEY_ALL_ACCESS, &hKey);
	if(lReturn != ERROR_SUCCESS)
		return -1;

	// 获取子键&键值信息
	DWORD dwSubKeysCnt;				// 子键数量
	DWORD dwMaxSubKeyNameLen;		// 子键名字的最大长度(不包括结尾的\0)
	DWORD dwKeyValueCnt;			// 键值的数量
	DWORD dwMaxKeyValueNameLen;		// 键值名字的最大长度(不包括结尾的\0)
	DWORD dwMaxKeyValueDataLen;		// 键值数据的最大长度(in Bytes)

	lReturn = RegQueryInfoKeyA(hKey, NULL, NULL, NULL, &dwSubKeysCnt, &dwMaxSubKeyNameLen,
		NULL, &dwKeyValueCnt, &dwMaxKeyValueNameLen, &dwMaxKeyValueDataLen, NULL, NULL);
	if(lReturn != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return -1;
	}

	// 枚举子键信息
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

		// 获取具体的程序的安装信息
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

	// 输出到文件
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

