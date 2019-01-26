
// 判断一个机器的操作系统是不是win7

#include <iostream>
#include <afx.h>
// #include <Windows.h>
#include <tchar.h>
#include <string>

using std::cout;
using std::endl;
using std::wcout;
using std::wstring;

bool IsWin7()
{
	OSVERSIONINFOEX osvi;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*)&osvi);


	cout << "osvi.dwBuildNumber = " << osvi.dwBuildNumber << endl;
	cout << "osvi.dwMajorVersion = " << osvi.dwMajorVersion << endl;
	cout << "osvi.dwMinorVersion = " << osvi.dwMinorVersion << endl;
	cout << "osvi.dwOSVersionInfoSize = " << osvi.dwOSVersionInfoSize << endl;
	cout << "osvi.dwPlatformId = " << osvi.dwPlatformId << endl;
	cout << "osvi.szCSDVersion = " << osvi.szCSDVersion << endl;
	cout << "osvi.wProductType = " << osvi.wProductType << endl;
	cout << "osvi.wReserved = " << osvi.wReserved << endl;
	cout << "osvi.wServicePackMajor = " << osvi.wServicePackMajor << endl;
	cout << "osvi.wServicePackMinor = " << osvi.wServicePackMinor << endl;
	cout << "osvi.wSuiteMask = " << osvi.wSuiteMask << endl;
	cout << endl;

	// win7的系统版本为NT6.1
	if(VER_PLATFORM_WIN32_NT == osvi.dwPlatformId 
		&& osvi.dwMajorVersion == 6
		&& osvi.dwMinorVersion == 1)
		return true;
	else
		return false;
}


// 通过系统版本来判断操作系统名称
CString GetSystemName()
{
	SYSTEM_INFO info;							// 用SYSTEM_INFO结构判断64位AMD处理器
	GetSystemInfo(&info);
	OSVERSIONINFOEX os;
	// 在调用函数前必须用sizeof(OSVERSIONINFOEX)填充这个成员
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if(GetVersionEx((OSVERSIONINFO*)&os))
	{
		CString vname = _T("");
		// 根据版本信息判断操作系统名称
		switch(os.dwMajorVersion)				// 主版本号
		{
		case 4:
			switch(os.dwMinorVersion)			// 副版本号
			{
			case 0:
				if(os.dwPlatformId == VER_PLATFORM_WIN32_NT)
					vname = _T("Microsoft Windows NT 4.0");				// 1996年7月发布
				else if(os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
					vname = _T("Microsoft Windows 95");
				break;
			case 10:
				vname = _T("Microsoft Windows 98");
				break;
			case 90:
				vname = _T("Microsoft Windows Me");
				break;
			}
			break;

		case 5:
			switch(os.dwMinorVersion)
			{
			case 0:
				vname = _T("Microsoft Windows 2000");			// 1999年12月发布
				break;
			case 1:
				vname = _T("Microsoft Windows XP");				// 2001年8月发布
				break;
			case 2:
				if(os.wProductType == VER_NT_WORKSTATION
					&& info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
					vname = _T("Microsoft Windows XP Professional x64 Edition");
				else if(GetSystemMetrics(SM_SERVERR2) == 0)
					vname = _T("Microsoft Windows Server 2003");		// 2003年3月发布
				else if(GetSystemMetrics(SM_SERVERR2) != 0)
					vname=_T("Microsoft Windows Server 2003 R2");
				break;
			}
			break;

		case 6:
			 switch(os.dwMinorVersion)
			 { 
			 case 0: 
				// VER_NT_WORKSTATION是桌面系统
                if(os.wProductType == VER_NT_WORKSTATION)
                    vname = _T("Microsoft Windows Vista");
                else 
                    vname = _T("Microsoft Windows Server 2008");          //服务器版本
                break; 
             case 1: 
                if(os.wProductType == VER_NT_WORKSTATION)
                    vname = _T("Microsoft Windows 7");
                else 
                    vname = _T("Microsoft Windows Server 2008 R2");
                break;
			  }
              break;
			  
		default:
			vname = _T("未知操作系统");
			break;
		}

		return vname;
	}
	else
		return _T("");
}


// 下面这个函数返回具体的版本名称
CString GetVersionMark()
{
	OSVERSIONINFOEX os; 
    os.dwOSVersionInfoSize=sizeof(OSVERSIONINFOEX); 
    if(GetVersionEx((OSVERSIONINFO *)&os)){ 
        CString vmark;

        switch(os.dwMajorVersion)		//先判断操作系统版本
		{                
        case 5: 
			switch(os.dwMinorVersion)
			{ 
			case 0:                  //Windows 2000 
				if(os.wSuiteMask==VER_SUITE_ENTERPRISE) 
					vmark=_T("Advanced Server"); 
				break; 
			case 1:                  //Windows XP 
				if(os.wSuiteMask==VER_SUITE_EMBEDDEDNT) 
					vmark=_T("Embedded"); 
				else if(os.wSuiteMask==VER_SUITE_PERSONAL) 
					vmark=_T("Home Edition"); 
				else 
					vmark=_T("Professional"); 
				break; 
			case 2: 
				if(GetSystemMetrics(SM_SERVERR2)==0 &&
					os.wSuiteMask==VER_SUITE_BLADE)  //Windows Server 2003
					vmark=_T("Web Edition"); 
				else if(GetSystemMetrics(SM_SERVERR2)==0 &&
					os.wSuiteMask==VER_SUITE_COMPUTE_SERVER) 
					vmark=_T("Compute Cluster Edition"); 
				else if(GetSystemMetrics(SM_SERVERR2)==0 &&
					os.wSuiteMask==VER_SUITE_STORAGE_SERVER) 
					vmark=_T("Storage Server"); 
				else if(GetSystemMetrics(SM_SERVERR2)==0 &&
					os.wSuiteMask==VER_SUITE_DATACENTER) 
					vmark=_T("Datacenter Edition"); 
				else if(GetSystemMetrics(SM_SERVERR2)==0 &&
					os.wSuiteMask==VER_SUITE_ENTERPRISE) 
					vmark=_T("Enterprise Edition"); 
				else if(GetSystemMetrics(SM_SERVERR2)!=0 && 
					os.wSuiteMask==VER_SUITE_STORAGE_SERVER)  /*Windows Server 2003 R2*/
					vmark=_T("Storage Server"); 
				break; 
			} 
			break; 

        case 6: 
			switch(os.dwMinorVersion)
			{ 
			case 0: 
				if(os.wProductType!=VER_NT_WORKSTATION &&
					os.wSuiteMask==VER_SUITE_DATACENTER)  /*Windows Server 2008*/ 
					vmark=_T("Datacenter Server"); 
				else if(os.wProductType!=VER_NT_WORKSTATION && 
					os.wSuiteMask==VER_SUITE_ENTERPRISE) 
					vmark=_T("Enterprise"); 
				else if(os.wProductType==VER_NT_WORKSTATION &&
					os.wSuiteMask==VER_SUITE_PERSONAL)  //Windows Vista
					vmark=_T("Home"); 
				break; 
			} 
			break; 

        default: 
            vmark=_T(""); 
        } 
        return vmark; 
    } 
    else 
        return _T("");

}


// EnumWindows:函数功能 该函数枚举所有屏幕上的顶层窗口，并将窗口句柄
// 传送给应用程序定义的回调函数。回调函数返回FALSE将停止枚举，
// 否则EnumWindows函数继续到所有顶层窗口枚举完为止。 
// 函数原型 BOOL EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
// 参数： lpEnumFunc：指向一个应用程序定义的回调函数指针，
// 请参看EnumWindowsProc. lPararm:指定一个传递给回调函数的应用程序定义值
// 回调函数原型 BOOL CALLBACK EnumWindowsP

CString strBufs[1024];
size_t n;

BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{
	TCHAR str[100] = {0};
	::GetWindowText(hwnd, str, sizeof(str));
	strBufs[n++] = str;
	return 1;
}


void testEnumWindows()
{
	EnumWindows(lpEnumFunc, NULL);
	for(int i = 0; i < n; i++)
		if(!strBufs[i].IsEmpty())
			wcout << (LPCTSTR)strBufs[i] << endl;
}


int main()
{
	bool bWin7 = IsWin7();
	if(bWin7)
		cout << "The system is win7" << endl;
	else
		cout << "The system is not win7" << endl;
	cout << endl;

	CString strSysName = GetSystemName();
	wcout << (LPCTSTR)strSysName << endl;
	cout << endl;
	
	CString strVerMark = GetVersionMark();
	wcout << (LPCTSTR)strVerMark << endl;
	cout << endl;

	testEnumWindows();
	cout << endl;

	system("pause");
	return 0;
}
