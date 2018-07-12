
// 环境变量配置中注册表中，可以通过读写注册表来实现读写环境变量
// 系统环境变量存储在如下位置: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment
// 用户变量则存储在如下位置: HKEY_CURRENT_USER\Environment
// 下面示例程序用于向系统环境变量Path中增加内容

#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

// 为系统变量下的Path环境变量增加内容lpszPathValue
// 成功返回0， 失败返回-1
int AddPathEnvValue(LPCSTR lpszPathValue)
{
	long lReturn;
	HKEY hKey;
	LPCSTR lpszSubKey = "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment";

	lReturn = RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpszSubKey, 0, KEY_ALL_ACCESS, &hKey);
	if(ERROR_SUCCESS != lReturn)
	{
		cout << "RegOpenKeyExA(): Error" << endl;
		return -1;
	}

	// 读取注册表的键值Path
	// 1.获取KeyValueData即字符串的大小
	LPCSTR lpszKeyValueName = "Path";
	DWORD dwKeyValueType = REG_EXPAND_SZ;
	DWORD dwKeyValueDataSize = 0;
	
	lReturn = RegQueryValueExA(hKey, lpszKeyValueName, NULL, &dwKeyValueType,
		NULL, &dwKeyValueDataSize);
	if(ERROR_FILE_NOT_FOUND == lReturn)
	{
		// 不存在Path环境变量则新增一个Path环境变量
		lReturn = RegSetValueExA(hKey, lpszKeyValueName, 0, dwKeyValueType, (const BYTE *)"", 1);
		if(lReturn != ERROR_SUCCESS)
		{
			cout << "RegSetValueExA(): Error" << endl;
			RegCloseKey(hKey);
			return -1;
		}
	}
	else if(lReturn != ERROR_SUCCESS)
	{
		cout << "RegQueryValueExA(): Error" << endl;
		RegCloseKey(hKey);
		return -1;		
	}
	else if(dwKeyValueType != REG_EXPAND_SZ)
	{
		cout << "It is impossible" << endl;
		cout << dwKeyValueType << endl;
		RegCloseKey(hKey);
		return -1;
	}

	// 2.获取KeyValueData即字符串的值
	char* lpszKeyValueData = new char[dwKeyValueDataSize + 1];
	memset(lpszKeyValueData, 0, dwKeyValueDataSize + 1);
	lReturn = RegQueryValueExA(hKey, lpszKeyValueName, NULL, 
		&dwKeyValueType, (LPBYTE)lpszKeyValueData, &dwKeyValueDataSize);
	if(lReturn != ERROR_SUCCESS)
	{
		cout << "RegQueryValueExA(): Error" << endl;
		RegCloseKey(hKey);
		delete [] lpszKeyValueData;
		return -1;
	}

	// 在原注册表值的基础上添加新值
	unsigned int nLen = strlen(lpszPathValue);
	nLen += strlen(lpszKeyValueData);
	char* lpszKeyValueData_New = new char[nLen + 1];
	memset(lpszKeyValueData_New, 0, nLen + 1);
	sprintf(lpszKeyValueData_New, "%s%s", lpszKeyValueData, lpszPathValue);

	unsigned int nLen1 = strlen(lpszKeyValueData_New) + 1;
	lReturn = RegSetValueExA(hKey, lpszKeyValueName, 0, 
		dwKeyValueType, (const BYTE *)lpszKeyValueData_New, nLen);
	if(ERROR_SUCCESS != lReturn)
	{
		cout << "RegSetValueExA(): Error" << endl;
		RegCloseKey(hKey);
		delete [] lpszKeyValueData;
		delete [] lpszKeyValueData_New;
		return -1;
	}

	delete [] lpszKeyValueData;
	delete [] lpszKeyValueData_New;

	RegCloseKey(hKey);

	return 0;
}


int main()
{
	cout << AddPathEnvValue(";test111") << endl;

	system("pause");
	return 0;
}
