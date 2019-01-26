
#include <iostream>
#include <string>
#include <Windows.h>

#include <ShlObj.h>
#pragma comment(lib, "shell32.lib")

using std::cout;
using std::endl;
using std::wcout;
using std::string;
using std::wstring;

// 获取当前用户登录的名字
void dir_1()
{
	char szBuffer[256] = {0};
	DWORD dwSize = 256;
	if(GetUserNameA(szBuffer, &dwSize))
		cout << "当前用户名:" << szBuffer << " size is " << dwSize << endl;
	else
		cout << "获取当前用户名错误" << endl;

	wchar_t szwBuffer[256] = {0};
	dwSize = 256;
	if(GetUserNameW(szwBuffer, &dwSize))
	{
		cout << "当前用户名:";
		wcout << szwBuffer << " size is " << dwSize << endl;
	}
	else
		cout << "获取当前用户名错误" << endl;
}

// 获取用户AppData\Local路径
wstring GetLocalAppDataPath()
{
	wchar_t szwBuf[256] = {0};
	wchar_t szDocument[256] = {0};

	LPITEMIDLIST pidl = NULL;
	SHGetSpecialFolderLocation(NULL, CSIDL_LOCAL_APPDATA, &pidl);
	if(pidl && SHGetPathFromIDList(pidl, szDocument))
		GetShortPathName(szDocument, szwBuf, 256);
	wstring wstr = szwBuf;
	return wstr;
}

wstring GetLocalAppDataPath(wstring appName)
{
	wstring wpath = GetLocalAppDataPath();
	wpath.append(L"\\");
	wpath.append(appName);

	if(_waccess(wpath.c_str(), 0) == -1)
	{
		_wmkdir(wpath.c_str());
		wcout << L"Create directory succeed" << endl;
	}
	return wpath;
}


int main()
{
	// dir_1();
	// wcout << GetLocalAppDataPath() << endl;

	// wcout << GetLocalAppDataPath(L"Temp\\chinaidcard") << endl;
	wcout << GetLocalAppDataPath(L"Temp\\0826-1") << endl;

	system("pause");
	return 0;
}