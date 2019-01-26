
#include <Windows.h>
#include <string>
#include <tchar.h>
#include <fstream>
using namespace std;

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	TCHAR szPath[1024] = {0};
	GetModuleFileName(NULL, szPath, MAX_PATH);
	(_tcsrchr(szPath, _T('\\')))[1] = 0;

	TCHAR wstrInstallFilePath[] = _T("PassportReader32bitV6.7.5.2.exe");
	_tcscat(szPath, wstrInstallFilePath);
	MessageBox(NULL, szPath, _T("title"), MB_OKCANCEL);

	//	BOOL bSucceed = false;
	//#ifdef _UNICODE
	//	wstring command;
	//#else
	//	string command;
	//#endif
	//
	//	command = _T(" -Admin");

	//(int)hRet > 32;
	//bSucceed = CreateProcess(wstrInstallFilePath,		// module name(no use command line)
	//	NULL,				// No command line
	//	NULL,				// Process handle not inheritable
	//	NULL,				// Thread handle not inheritable
	//	FALSE,				// Set handle inheritable to FALSE
	//	0,					// No creation flags
	//	NULL,				// Use parent's environment block
	//	NULL,				// Use parent's starting directory
	//	&si,				// Pointer to STARTUPINFO structure
	//	&pi					// Pointer to PROCESS_INFORMATION structure
	//	);

	HINSTANCE hRet = ShellExecute(NULL, _T("open"), szPath, 
		NULL, NULL, SW_SHOWNORMAL);

	if (int(hRet) > 32)
		MessageBox(NULL, _T("success"), _T("title"), MB_OKCANCEL);
	else
	{
		MessageBox(NULL, _T("failed"), _T("title"), MB_OKCANCEL);
		DWORD dwerr = GetLastError();
		ofstream ofs("res.txt");
		ofs << dwerr << endl;
		ofs.close();
	}

	system("pause");
	return 0;
}