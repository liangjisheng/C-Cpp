
// ��������������ע����У�����ͨ����дע�����ʵ�ֶ�д��������
// ϵͳ���������洢������λ��: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment
// �û�������洢������λ��: HKEY_CURRENT_USER\Environment
// ����ʾ������������ϵͳ��������Path����������

#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

// Ϊϵͳ�����µ�Path����������������lpszPathValue
// �ɹ�����0�� ʧ�ܷ���-1
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

	// ��ȡע���ļ�ֵPath
	// 1.��ȡKeyValueData���ַ����Ĵ�С
	LPCSTR lpszKeyValueName = "Path";
	DWORD dwKeyValueType = REG_EXPAND_SZ;
	DWORD dwKeyValueDataSize = 0;
	
	lReturn = RegQueryValueExA(hKey, lpszKeyValueName, NULL, &dwKeyValueType,
		NULL, &dwKeyValueDataSize);
	if(ERROR_FILE_NOT_FOUND == lReturn)
	{
		// ������Path��������������һ��Path��������
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

	// 2.��ȡKeyValueData���ַ�����ֵ
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

	// ��ԭע���ֵ�Ļ����������ֵ
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
