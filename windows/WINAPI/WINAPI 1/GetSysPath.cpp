
#include <iostream>
#include <afx.h>				// for CString
#include <string>
#include <ShlObj.h>
#include <Shlwapi.h>			//PathAppendW  

#pragma comment (lib, "shlwapi.lib")   

using std::cout;
using std::wcout;
using std::endl;
using std::wstring;


/************************************************************************/
/* Get System Directory                                                 */
/************************************************************************/
CString GetSysFolder()
{  
	TCHAR szPath[MAX_PATH] = {0};  
	GetSystemDirectory(szPath, MAX_PATH);
	return CString(szPath);
}


/************************************************************************/
/* Get Windows Path                                                     */
/************************************************************************/
CString GetWindowsFolder()  
{  
	TCHAR szPath[MAX_PATH] = {0};  
	GetWindowsDirectory(szPath, MAX_PATH);
	return CString(szPath);
}


/************************************************************************/
/* 获取exe文件所在的目录                                                */
/************************************************************************/
CString GetModuleFolder(HMODULE hModule = NULL)
{
	TCHAR   szPath[MAX_PATH] = {0};
	GetModuleFileName(hModule, szPath, MAX_PATH);
	ZeroMemory(_tcsrchr(szPath,_T('\\')), _tcslen(_tcsrchr(szPath,_T('\\') ) ) * sizeof(TCHAR));
	return CString(szPath);
}


/************************************************************************/
/* GetUserAppDataDir用户应用程序数据目录
	C:\Users\GetUserAppDataDir\AppData\Roaming  */
/************************************************************************/
wstring GetUserAppDataDir()
{
	wstring wstrAppDataPath = L"";
	wchar_t buffer[MAX_PATH] = {0};
    ::ZeroMemory(buffer, MAX_PATH * sizeof(wchar_t));
    if (::SHGetSpecialFolderPath(NULL, buffer, CSIDL_APPDATA, NULL))  
        wstrAppDataPath = buffer;  
  
    wchar_t szTmp [MAX_PATH] = {0};
    wcscpy_s(szTmp, wstrAppDataPath.c_str());  
    ::PathAppendW(szTmp, L"0728-1.exe");
      
    return szTmp;  
}


/************************************************************************/
/* C:\Users\GetUserAppDataDir\AppData\Local                             */
/************************************************************************/
wstring GetLocalAppDataPath()  
{  
	wstring wsValue = L"";
	wchar_t wzLacalAppData[MAX_PATH] = {0};  
	if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, SHGFP_TYPE_CURRENT, wzLacalAppData)))  
		wsValue = wzLacalAppData;     
	return wsValue;  
}  

/************************************************************************/
/* BOOL SHGetSpecialFolderPath(HWND hWndOwner, LPTSTR lpszPath, int nFolder,BOOL fCreate);
	hWndOwner: 如果在对话框或者messagebox上显示，表示用到的窗口句柄;如果
	只是单纯的获取路径，一般为NULL
	lpszPath:接受路径的字符串
	nFolder:微软定义好的一个标志，用于代表要获取那种目录,常见如下
	CSIDL_BITBUCKET   回收站       
	CSIDL_CONTROLS   控制面板       
	CSIDL_DESKTOP   Windows   桌面Desktop       
	CSIDL_DESKTOPDIRECTORY   Desktop的目录       
	CSIDL_DRIVES   我的电脑       
	CSIDL_FONTS   字体目录       
	CSIDL_NETHOOD   网上邻居       
	CSIDL_NETWORK   网上邻居虚拟目录       
	CSIDL_PERSONAL   我的文档       
	CSIDL_PRINTERS   打印机       
	CSIDL_PROGRAMS   程序组       
	CSIDL_RECENT   最近打开的文档       
	CSIDL_SENDTO   “发送到”菜单项       
	CSIDL_STARTMENU   任务条启动菜单项       
	CSIDL_STARTUP   启动目录       
	CSIDL_TEMPLATES   文档模板   
	具体内容可以参照 shlobj.h 。
	fCreate: 如果文件夹不存在，是否创建它。一般不更改系统文件夹，设为FALSE
*/
/************************************************************************/


// UINT WINAPI GetSystemWow64Directory(_Out_ LPTSTR lpBuffer, _In_  UINT   uSize);


int main()
{
	CString strPath = GetSysFolder();
	wcout << strPath.GetString() << endl;
	wcout << strPath.GetBuffer(0) << endl;
	strPath.ReleaseBuffer();
	cout << endl;

	strPath = GetWindowsFolder();
	wcout << strPath.GetString() << endl;
	wcout << strPath.GetBuffer(0) << endl;
	strPath.ReleaseBuffer();
	cout << endl;

	strPath = GetModuleFolder();
	wcout << strPath.GetString() << endl;
	wcout << strPath.GetBuffer(0) << endl;
	strPath.ReleaseBuffer();
	cout << endl;

	TCHAR szPath[MAX_PATH] = {0};
	SHGetSpecialFolderPath(NULL, szPath, CSIDL_DESKTOP, FALSE);
	wcout << szPath << endl;
	memset(szPath, 0, sizeof(szPath));
	SHGetSpecialFolderPath(NULL, szPath, CSIDL_DESKTOPDIRECTORY, FALSE);
	wcout << szPath << endl;
	memset(szPath, 0, sizeof(szPath));
	cout << endl;

	TCHAR *lpwszWow64Path = NULL;
	int nRetCount = GetSystemWow64Directory(lpwszWow64Path, 0);
	lpwszWow64Path = new TCHAR[nRetCount];
	memset(lpwszWow64Path, 0, nRetCount);
	nRetCount = GetSystemWow64Directory(lpwszWow64Path, nRetCount);
	wcout << lpwszWow64Path << endl;
	delete [] lpwszWow64Path;
	lpwszWow64Path = NULL;
	cout << endl;

	wcout << L"GetUserAppDataDir: " << GetUserAppDataDir() << endl;
	wcout << L"GetLocalAppDataPath : " << GetLocalAppDataPath() << endl;

	system("pause");
	return 0;
}