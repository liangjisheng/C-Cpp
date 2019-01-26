// fileTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fileTest1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;


// GetFileAttributes(),判断文件是否存在较好的API
// 支持xp系统，可以直接区分文件和文件夹

// 判断文件是否存在
bool IsFileExist(const CString& csFile)
{
	DWORD dwAttrib = GetFileAttributes(csFile);
	return dwAttrib != INVALID_FILE_ATTRIBUTES && 0 ==(dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

// 判断文件夹是否存在
bool IsDirExist(const CString& csDir)
{
	DWORD dwAttrib = GetFileAttributes(csDir);
	return dwAttrib != INVALID_FILE_ATTRIBUTES && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

// 判断文件或文件夹是否存在
bool IsPathExist(const CString& csPath)
{
	DWORD dwAttrib = GetFileAttributes(csPath);
	return dwAttrib != INVALID_FILE_ATTRIBUTES;
}

// 扩展版
bool IsPathExistEx(const CString& csPath)
{
	WIN32_FILE_ATTRIBUTE_DATA attrs = {0};
	return 0 != GetFileAttributesEx(csPath, GetFileExInfoStandard, &attrs);
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			bool bExist = false;
			bExist = IsFileExist(_T("D:\\JPG\\0.jpg"));
			if(bExist)
				cout << "D:\\JPG\\0.jpg exist." << endl;
			else
				cout << "D:\\JPG\\0.jpg not exist." << endl;

			bExist = IsDirExist(_T("D:\\JPG"));
			if(bExist)
				cout << "D:\\JPG exist." << endl;
			else
				cout << "D:\\JPG not exist." << endl;

			bExist = IsPathExist(_T("D:\\JPG"));
			if(bExist)
				cout << "D:\\JPG exist." << endl;
			else
				cout << "D:\\JPG not exist." << endl;

			bExist = IsPathExist(_T("D:\\JPG\\0.jpg"));
			if(bExist)
				cout << "D:\\JPG\\0.jpg exist." << endl;
			else
				cout << "D:\\JPG\\0.jpg not exist." << endl;

			bExist = IsPathExistEx(_T("D:\\JPG"));
			if(bExist)
				cout << "D:\\JPG exist." << endl;
			else
				cout << "D:\\JPG not exist." << endl;

			bExist = IsPathExistEx(_T("D:\\JPG\\0.jpg"));
			if(bExist)
				cout << "D:\\JPG\\0.jpg exist." << endl;
			else
				cout << "D:\\JPG\\0.jpg not exist." << endl;
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
