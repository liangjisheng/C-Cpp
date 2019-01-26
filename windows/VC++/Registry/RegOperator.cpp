
#include <iostream>
#include <Windows.h>
#include <tchar.h>

using std::cout;
using std::endl;


// 创建子键
void CreateSubKey()
{
	LPCTSTR lpSubKey = _T("testKey");
	HKEY hSubKey;
	DWORD dwPos;

	long lResult = RegCreateKeyEx(HKEY_CURRENT_USER, lpSubKey, 0, NULL,
		0, KEY_ALL_ACCESS, NULL, &hSubKey, &dwPos);

	if(ERROR_SUCCESS == lResult)
	{
		LPCTSTR lpKeyName = _T("Language");
		DWORD dwValue = 1033;
		DWORD cbSize = sizeof(DWORD);
		lResult = RegSetValueEx(hSubKey, lpKeyName, 0, REG_DWORD,
			(const BYTE *)&dwValue, cbSize);
		if(ERROR_SUCCESS == lResult)
			cout << "Write ok" << endl;
		else
			cout << "Write failed" << endl;
	}
	else
		cout << "Create SubKey failed" << endl;

	if(hSubKey)
		RegCloseKey(hSubKey);
}

void CreateSubKey_1()
{
	HKEY hAppKey = NULL;
	HKEY hSoftKey = NULL;
	HKEY hCompanyKey = NULL;

	// 打开HKEY_CURRENT_USER\"SoftWare"
	long lReturn;
	lReturn = RegOpenKeyEx(HKEY_CURRENT_USER, _T("SoftWare"), 0, 
		KEY_WRITE | KEY_READ, &hSoftKey);
	if(ERROR_SUCCESS == lReturn)
	{
		DWORD cbSize;
		// 创建并打开键HKEY_CURRENT_USER\SoftWare\liangjisheng
		lReturn = RegCreateKeyEx(hSoftKey, _T("liangjisheng"), 0, REG_NONE,
			REG_OPTION_NON_VOLATILE, KEY_READ | KEY_WRITE, 
			NULL, &hCompanyKey, &cbSize);
		if(ERROR_SUCCESS == lReturn)
		{
			// 创建并打开键HKEY_CURRENT_USER\SoftWare\liangjisheng\test
			lReturn = RegCreateKeyEx(hCompanyKey, _T("test"), 0, REG_NONE, 
				REG_OPTION_NON_VOLATILE, KEY_READ | KEY_WRITE, NULL,
				&hAppKey, &cbSize);
			if(ERROR_SUCCESS == lReturn)
				cout << "create ok" << endl;
			else
				cout << "Create failed return value: " << lReturn << endl;
		}
		else
			cout << "Create key failed return value: " << lReturn << endl;
	}
	else
		cout << "open HKEY_CURRENT_USER\\SoftWare failed return value: " << lReturn << endl;

	if(hAppKey)
		RegCloseKey(hAppKey);
	if(hCompanyKey)
		RegCloseKey(hCompanyKey);
	if(hSoftKey)
		RegCloseKey(hSoftKey);
}

int main()
{
	CreateSubKey();
	// CreateSubKey_1();

	system("pause");
	return 0;
}