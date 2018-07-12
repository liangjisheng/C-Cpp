void CMy01271Dlg::OnBnClickedButtonCreateprocess()
{
	DWORD dwReturn = 0;
	CString strApplication = _T("D:\\vs2010_projects\\0126-1\\Debug\\PassportReader32bitV6.7.5.2.exe");
	// CString strApplication = _T("C:\\Windows\\System32\\notepad.exe");
	// CString strApplication = _T("C:\\Windows\\explorer.exe");
	CString strLog = _T("123");
	CString strPwd = _T("123");
	CString strDomain = _T(".");

	// test1
	//myCreateProcessWithLogonW(strApplication, dwReturn, strLog, strDomain, strPwd);

	// test2
	CreateMyProcess(strApplication, dwReturn, strLog, strDomain, strPwd);

	// test3
	// BOOL bRet = CreateProcessLow(_T("C:\\Windows\\System32\\notepad.exe"));
	// BOOL bRet = CreateProcessLow(_T("C:\\Windows\\explorer.exe"));
	// BOOL bRet = CreatePorcessHigh(_T("C:\\Windows\\System32\\notepad.exe"));
	// BOOL bRet = CreateProcessLow(_T("D:\\Card Recognition System\\PassportReader32bitV6.7.5.1(未发布)-8\\SDK\\setup.exe"));
}

BOOL CMy01271Dlg::CreateMyProcess(CString strCommand, DWORD& dwReturn, CString& strLog, CString strDomain, CString strPwd)
{
	HANDLE hToken;
	dwReturn = -1;

	// 尝试登陆123账户
	// 123账户的令牌权限要小于任务栏所在进程的令牌权限
	//if(!LogonUser(strLog,
	//	strDomain,
	//	strPwd,
	//	LOGON32_LOGON_INTERACTIVE,
	//	LOGON32_PROVIDER_DEFAULT,
	//	&hToken
	//	))
	//{
	//	dwReturn = GetLastError();
	//	strLog.Format(_T("Error OnLogonUserW(),errorcode is %d."), dwInitError);
	//	return FALSE;
	//}

	hToken = DupExplorerToken();

	//BOOL blResult = FALSE;
	//SECURITY_ATTRIBUTES sa;
	//HANDLE hRead, hWrite;
	//sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	//sa.lpSecurityDescriptor = NULL;
	//sa.bInheritHandle = TRUE;				//创建管道
	//if(!CreatePipe(&hRead, &hWrite, &sa, 0))
	//{
	//	strLog = _T("ErrorOnCreatePipe()");
	//	return FALSE;
	//}

	//将cb成员初始化为sizeof(si)，其他成员初始化为0
	STARTUPINFO si = { sizeof(si) };
	//::GetStartupInfo(&si);
	//si.hStdError = hWrite;
	//si.hStdOutput = hWrite;
	//si.wShowWindow = SW_SHOWNORMAL;
	//si.dwFlags = STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
	PROCESS_INFORMATION pi = {0};

	if (!CreateProcessAsUser(hToken,
		strCommand,
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{
		dwReturn = GetLastError();	// 1314表示权限不够
		strLog.Format(_T("Error OnCreateProcessWithLogonW(),errorcodeis%d."), dwReturn);
		//CloseHandle(hWrite);
		//CloseHandle(hRead);
		return FALSE;
	}
	//CloseHandle(hWrite);

	//char buffer[4096]={0};
	//DWORD bytesRead=0;//读取回传值
	//while(true)
	//{
	//	if(ReadFile(hRead,buffer,4095,&bytesRead,NULL)==NULL)break;//获取了回传值，处理回传值
	//	Sleep(100);
	//}

	//CloseHandle(hRead);
	CloseHandle(hToken);
	//WaitForSingleObject(pi.hProcess,INFINITE);
	//GetExitCodeProcess(pi.hProcess,&dwReturn);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return TRUE;
}

BOOL CMy01271Dlg::myCreateProcessWithLogonW(CString strApplication, DWORD& dwReturn, 
	CString& strLog, CString strDomain, CString strPwd)
{
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi = {0};

	if(!CreateProcessWithLogonW(strLog,
		strDomain,
		strPwd,
		LOGON_WITH_PROFILE,
		strApplication,
		NULL,
		CREATE_UNICODE_ENVIRONMENT,
		NULL,
		NULL,
		&si,
		&pi))
	{
		dwReturn = GetLastError();
		strLog.Format(_T("Error OnCreateProcessWithLogonW(),errorcodeis%d."), dwReturn);
		return FALSE;
	}
	else
		return TRUE;
}


BOOL CMy01271Dlg::CreateProcessLow(TCHAR* lpApplicationName, TCHAR* lpCommandLine /* = NULL */,
	TCHAR* lpDirectory /* = NULL */, UINT nShow /* = SW_SHOWNORMAL */)
{
	if (!IsVistaOrLater() || !IsAdminPrivilege())
	{
		HINSTANCE hRet = ShellExecute(NULL, _T("open"), lpApplicationName, 
			lpCommandLine, lpDirectory, nShow);
		return (int)hRet > 32;
	}

	HANDLE hToken = DupExplorerToken();
	if (NULL == hToken)
		return FALSE;

	static HMODULE hDll = LoadLibrary(_T("ADVAPI32.dll"));
	if (!hDll)
	{
		CloseHandle(hToken);
		return FALSE;
	}

	F_CreateProcessWithTokenW pfn = 
		(F_CreateProcessWithTokenW)GetProcAddress(hDll, "CreateProcessWithTokenW");
	if (!pfn)
	{
		CloseHandle(hToken);
		return FALSE;
	}

	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi = {0};
	BOOL bRet = pfn(hToken,
		LOGON_WITH_PROFILE,
		lpApplicationName,
		lpCommandLine,
		NORMAL_PRIORITY_CLASS,
		NULL,
		lpDirectory,
		&si,
		&pi);

	if (bRet)
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	CloseHandle(hToken);
	return bRet;
}

BOOL CMy01271Dlg::CreatePorcessHigh(TCHAR* lpApplicationName, TCHAR* lpCommandLine /* = NULL */, 
	TCHAR* lpDirectory /* = NULL */, UINT nShow /* = SW_SHOWNORMAL */)
{
#ifdef _UNICODE
	wstring command;
#else
	string command;
#endif

	if (lpCommandLine)
		command = lpCommandLine;

	if (IsVistaOrLater() && !IsAdminPrivilege())
		command += _T(" -Admin");

	HINSTANCE hRet = ShellExecute(NULL, _T("runas"), lpApplicationName, command.c_str(),
		lpDirectory, nShow);
	return (int)hRet > 32;
}

HANDLE CMy01271Dlg::DupExplorerToken()
{
	DWORD dwPid = 0;
	// 通过指定类名查找窗口句柄,获取任务栏窗口
	HWND hwnd = ::FindWindow(_T("Shell_TrayWnd"), NULL);
	if (NULL == hwnd)
		return NULL;

	// 通过窗口句柄获得进程ID
	GetWindowThreadProcessId(hwnd, &dwPid);
	if (0 == dwPid)
		return NULL;

	// 通过进程ID打开进程，返回进程句柄
	HANDLE hExplorer = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwPid);
	if (NULL == hExplorer)
		return NULL;

	HANDLE hToken = NULL;
	// 通过进程句柄获取进程令牌
	OpenProcessToken(hExplorer, TOKEN_DUPLICATE, &hToken);
	CloseHandle(hExplorer);

	HANDLE hNewToken = NULL;
	// 复制进程令牌
	DuplicateTokenEx(hToken, TOKEN_ALL_ACCESS, NULL, SecurityImpersonation,
		TokenPrimary, &hNewToken);
	CloseHandle(hToken);

	return hNewToken;
}

BOOL CMy01271Dlg::IsVistaOrLater()
{
	OSVERSIONINFOEX version = { sizeof(OSVERSIONINFOEX) };
	if (!GetVersionEx((LPOSVERSIONINFO)&version))
	{
		version.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		if (!GetVersionEx((LPOSVERSIONINFO)&version))
			return FALSE;
	}

	return version.dwMajorVersion >= 6;
}

BOOL CMy01271Dlg::IsAdminPrivilege()
{
	BOOL bIsAdmin = FALSE;
	BOOL bRet = FALSE;
	SID_IDENTIFIER_AUTHORITY identifier = SECURITY_NT_AUTHORITY;
	PSID pAdministratorGroup;

	if (AllocateAndInitializeSid(
		&identifier, 2, SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&pAdministratorGroup))
	{
		if (!CheckTokenMembership(NULL, pAdministratorGroup, &bRet))
			bIsAdmin = FALSE;
	}

	if (bRet)
		bIsAdmin = TRUE;

	FreeSid(pAdministratorGroup);

	return bIsAdmin;
}



void CMy01271Dlg::OnBnClickedButtonCreateprocessasuser()
{
	HANDLE hPtoken = NULL;
	DWORD dwRet = 0;
	// hPtoken = DupExplorerToken();
	dwRet = INTER_GetExplorerToken(&hPtoken);
	PROCESS_INFORMATION pi;
	STARTUPINFO si = { sizeof(STARTUPINFO), NULL, _T(""), NULL, 
		0, 0, 0, 0, 0, 0, 0, STARTF_USESHOWWINDOW, 0, 0, NULL, 0, 0, 0 };
	si.wShowWindow = SW_SHOW;
	si.lpDesktop = NULL;
	ZeroMemory(&pi, sizeof(pi));

	if (0 == dwRet && hPtoken)
	{
		CreateProcessAsUser(hPtoken, _T("C:\\Windows\\System32\\notepad.exe"), NULL, NULL, NULL, FALSE,
			NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

		// Sleep(1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

DWORD __stdcall CMy01271Dlg::INTER_GetExplorerToken(OUT PHANDLE phExplorerToken)
{
	DWORD dwStatus = ERROR_FILE_NOT_FOUND;
	BOOL bRet = FALSE;
	HANDLE hProcess = NULL;
	HANDLE hProcessSnap = NULL;
	TCHAR szExplorerPath[MAX_PATH] = {0};
	char szFileName[MAX_PATH] = {0};
	PROCESSENTRY32 pe32 = {0};
	// PROCESS_HEAP_ENTRY pe32 = {0};

	try{
		GetWindowsDirectory(szExplorerPath, MAX_PATH);
		_tcscat(szExplorerPath, _T("\\explorer.exe"));
		hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE)
		{
			dwStatus = GetLastError();
			throw -1;
		}

		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (!Process32First(hProcessSnap, &pe32))
		{
			dwStatus = GetLastError();
			throw -2;
		}

		do {
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
			if (NULL != hProcess)
			{
				DWORD (_stdcall *GMFNE)(HANDLE hProcess,
					HMODULE hModule,
					LPSTR lpFileName,
					DWORD nSize);

				HMODULE hPsapi = LoadLibrary(_T("PSAPI"));
				if (!hPsapi)
				{
					dwStatus = GetLastError();
					break;
				}

				GMFNE = (DWORD (__stdcall *) (HANDLE, HMODULE,LPSTR,DWORD))
					GetProcAddress(hPsapi, "GetModuleFileNameExA");
				if (GMFNE && GMFNE(hProcess, NULL, szFileName, MAX_PATH))
				{
					wstring strExplorerPath(szExplorerPath);
					wstring strFileName = s2ws(string(szFileName));

					if (strExplorerPath == strFileName)
					//if (!_tcsicmp(szFileName, szExplorerPath))
					{
						HANDLE hToken;
						// if (OpenProcessToken(hProcess, TOKEN_DUPLICATE, &hToken))
						BOOL bOpen = OpenProcessToken(hProcess, TOKEN_ALL_ACCESS, &hToken);
						if (bOpen)
						{
							*phExplorerToken = hToken;
							dwStatus = 0;
						}
						break;
					}
				}

				CloseHandle(hProcess);
				hProcess = NULL;
			}
		} while (Process32Next(hProcessSnap, &pe32));
	}
	catch(DWORD d)
	{
		CString str;
		str.Format(_T("%d"), d);
		AfxMessageBox(str);
	}

	return dwStatus;
}

const std::wstring CMy01271Dlg::s2ws(const std::string &s)
{
	locale old_loc = locale::global(locale(""));

	const char* src_str = s.c_str();
	const size_t buffer_size = s.size() + 1;
	wchar_t* dst_wstr = new wchar_t[buffer_size];
	wmemset(dst_wstr, 0, buffer_size);
	mbstowcs(dst_wstr, src_str, buffer_size);
	wstring result = dst_wstr;
	delete []dst_wstr;
	dst_wstr = NULL;

	locale::global(old_loc);
	return result;
}

// 这里考虑转换空间缓存大小的策略正好相反，在最极端的情况下
// 所有的wchar_t都需要4个char来表示，所以最大的可能就是4倍加1
const std::string CMy01271Dlg::ws2s(const std::wstring& ws)
{
	locale old_loc = locale::global(locale(""));

	const wchar_t* src_wstr = ws.c_str();
	size_t buffer_size = ws.size() * 4 + 1;
	char* dst_src = new char[buffer_size];
	memset(dst_src, 0, buffer_size);
	wcstombs(dst_src, src_wstr, buffer_size);
	string result = dst_src;
	delete [] dst_src;
	dst_src = NULL;

	locale::global(old_loc);
	return result;
}


int CMy01271Dlg::myCreateProcessAsUser()
{
	HANDLE hTokenThis = NULL;
	HANDLE hTokenDup = NULL;

	HANDLE hThisProcess = NULL;
	hThisProcess = GetCurrentProcess();
	DWORD dwRes = GetLastError();
	if (NULL == hThisProcess)
		return -1;

	OpenProcessToken(hThisProcess, TOKEN_ALL_ACCESS, &hTokenThis);
	if (NULL == hTokenThis)
		return -2;

	//DuplicateTokenEx(hTokenThis, MAXIMUM_ALLOWED, NULL, SecurityIdentification,
	//	TokenPrimary, &hTokenDup);
	//if (NULL == hTokenDup)
	//	return -3;

	//DWORD dwSessionId = WTSGetActiveConsoleSessionId();  
	//SetTokenInformation(hTokenDup, TokenSessionId, &dwSessionId, sizeof(DWORD));  

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi = {0};

	CreateProcess(
		TEXT("C:\\Windows\\System32\\notepad.exe"),
		// _T("C:\\Windows\\explorer.exe"),
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);

	//ZeroMemory(&si, 0, sizeof(STARTUPINFO));
	//si.cb = sizeof(STARTUPINFO);
	//ZeroMemory(&pi, 0, sizeof(PROCESS_INFORMATION));

	//LPVOID pEnv = NULL;
	//DWORD dwCreateFlag = NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE;
	//CreateEnvironmentBlock(&pEnv, hTokenDup, FALSE);

	CreateProcessAsUser(hTokenThis,
		_T("C:\\Windows\\explorer.exe"),
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);

	return 0;
}

int CMy01271Dlg::myCreateProcessAsUser1()
{
	//if (!IsVistaOrLater() || !IsAdminPrivilege())
	//{
	//	HINSTANCE hRet = ShellExecute(NULL, _T("open"), lpApplicationName, 
	//		lpCommandLine, lpDirectory, nShow);
	//	return (int)hRet > 32;
	//}

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi = {0};
	//ZeroMemory(&si, 0, sizeof(STARTUPINFO));
	//ZeroMemory(&pi, 0, sizeof(PROCESS_INFORMATION));
	//si.cb = sizeof(STARTUPINFO);
	//si.dwFlags = STARTF_USESHOWWINDOW;
	//si.wShowWindow = TRUE;

	HANDLE hToken = DupExplorerToken();
	if (NULL == hToken)
		return FALSE;

	BOOL bRet = CreateProcessAsUser(hToken,
		TEXT("C:\\Windows\\System32\\notepad.exe"),
		// TEXT("C:\\Windows\\explorer.exe"),
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);

	if (bRet)
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	CloseHandle(hToken);
	return bRet;
}

void CMy01271Dlg::OnBnClickedButtonCreateprocessasuser2()
{
	// myCreateProcessAsUser();
	myCreateProcessAsUser1();
}



void CMy01271Dlg::OnBnClickedButtonAdministrator()
{
	if (IsAdminPrivilege())
		MessageBox(_T("管理员权限"), _T("title"), MB_OKCANCEL);
	else
		MessageBox(_T("非管理员权限"), _T("title"), MB_OKCANCEL);
}
