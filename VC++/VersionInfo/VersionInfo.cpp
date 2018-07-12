
/*
The following code shows how to get FILEINFO value from resource file.

These WIN32 functions will be used:

* GetFileVersionInfo
* GetFileVersionInfoSize
* VerQueryValue
* GetModuleFileName
*/

#include <Windows.h>
#include <tchar.h>
#include <string>
#include <iostream>

#pragma comment(lib, "version.lib")
using namespace std;

bool GetFileVersion(HMODULE hModule, WORD *pBuffer)
{
	TCHAR filename[MAX_PATH] = {0};
	VS_FIXEDFILEINFO *pVi;
	DWORD dwHandle;
	string str = "";

	if(::GetModuleFileName(hModule, filename, MAX_PATH))
	{
		int size = GetFileVersionInfoSize(filename, &dwHandle);
		if(size > 0)
		{
			BYTE *buffer = new BYTE[size];
			if(GetFileVersionInfo(filename, dwHandle, size, buffer))
			{
				if(VerQueryValue(buffer, (LPCTSTR)_T('\\'), (LPVOID*)&pVi, (PUINT)&size))
				{
					pBuffer[0] = HIWORD(pVi->dwFileVersionMS);
					pBuffer[1] = LOWORD(pVi->dwFileVersionMS);
					pBuffer[2] = HIWORD(pVi->dwFileVersionLS);
					pBuffer[3] = LOWORD(pVi->dwFileVersionLS);

					delete [] buffer;
					buffer = NULL;
					return true;
				}
			}
			delete [] buffer;
			buffer = NULL;
		}
	}
	return false;
}

string GetFileVersion(HMODULE hModule)
{
	string str = "";
	WORD buffer[4] = {0};
	if(GetFileVersion(hModule, buffer))
	{
		char str2[32] = {0};
		for(int i = 0; i < sizeof(buffer)/ sizeof(WORD); i++)
		{
			itoa(buffer[i], str2, 10);
			str += str2;
			if(i != sizeof(buffer)/ sizeof(WORD) - 1)
				str += ".";
		}
	}

	return str;
}


int main()
{
	cout << "Current version is: " << GetFileVersion(::GetModuleHandle(NULL)) << endl;

	system("pause");
	return 0;
}