
#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;
using std::wcout;


void test_1()
{
	// 获取环境变量
	// WINDIR:                 //系统目录 - C:\WINDOWS  
	// SYSTEMROOT:             //系统目录 - C:\WINDOWS  
	// SYSTEMDRIVE:            //系统根目录 - C:  
	// HOMEDRIVE:              //当前用户根目录 - C:  
	// USERPROFILE:            //当前用户目录 - C:\Users\Kandy  
	// HOMEPATH:               //当前用户路径 - \Users\Kandy  
	// TMP:                    //当前用户临时文件夹 - C:\Users\Kandy\AppData\Local\Temp  
	// TEMP:                   //当前用户临时文件夹 - C:\Users\Kandy\AppData\Local\Temp  
	// APPDATA:                //当前用户数据文件夹 - C:\Users\Kandy\AppData\Roaming  
	// PROGRAMFILES:           //程序默认安装目录 - C:\Program Files (x86)  
	// COMMONPROGRAMFILES:     //文件通用目录 - C:\Program Files (x86)\Common Files  
	// USERNAME:               //当前用户名 - Kandy  
	// ALLUSERSPROFILE:        //所有用户文件目录 - C:\ProgramData  
	// OS:                     //操作系统名 - Windows_NT  
	// COMPUTERNAME:           //计算机名 - KANDY-PC  
	// NUMBER_OF_PROCESSORS:   //处理器个数 - 4  
	// PROCESSOR_ARCHITECTURE: //处理器芯片架构 - x86  
	// PROCESSOR_LEVEL:        //处理器型号 - 6  
	// PROCESSOR_REVISION:     //处理器修订号 - 3c03  
	// USERDOMAIN:             //包含用户帐号的域 - KANDY-PC  
	// COMSPEC:                //C:\WINDOWS\system32\cmd.exe  
	// PATHEXT:                //执行文件类型 - .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC  
	// PATH:                   //搜索路径  

	wchar_t buffer[MAX_PATH] = {0};  
	DWORD code = GetEnvironmentVariable(L"WINDIR", buffer, MAX_PATH);  
	std::wcout << L"WINDIR:\t\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"SYSTEMROOT", buffer, MAX_PATH);  
	std::wcout << L"SYSTEMROOT:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"SYSTEMDRIVE", buffer, MAX_PATH);  
	std::wcout << L"SYSTEMDRIVE:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"HOMEDRIVE", buffer, MAX_PATH);  
	std::wcout << L"HOMEDRIVE:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"USERPROFILE", buffer, MAX_PATH);  
	std::wcout << L"USERPROFILE:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"HOMEPATH", buffer, MAX_PATH);  
	std::wcout << L"HOMEPATH:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"TMP", buffer, MAX_PATH);  
	std::wcout << L"TMP:\t\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"TEMP", buffer, MAX_PATH);  
	std::wcout << L"TEMP:\t\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"APPDATA", buffer, MAX_PATH);  
	std::wcout << L"APPDATA:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"PROGRAMFILES", buffer, MAX_PATH);  
	std::wcout << L"PROGRAMFILES:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"COMMONPROGRAMFILES", buffer, MAX_PATH);  
	std::wcout << L"COMMONPROGRAMFILES:\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"USERNAME", buffer, MAX_PATH);  
	std::wcout << L"USERNAME:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"ALLUSERSPROFILE", buffer, MAX_PATH);  
	std::wcout << L"ALLUSERSPROFILE:\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"OS", buffer, MAX_PATH);  
	std::wcout << L"OS:\t\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"COMPUTERNAME", buffer, MAX_PATH);  
	std::wcout << L"COMPUTERNAME:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"NUMBER_OF_PROCESSORS", buffer, MAX_PATH);  
	std::wcout << L"NUMBER_OF_PROCESSORS:\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"PROCESSOR_ARCHITECTURE", buffer, MAX_PATH);  
	std::wcout << L"PROCESSOR_ARCHITECTURE:\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"PROCESSOR_LEVEL", buffer, MAX_PATH);  
	std::wcout << L"PROCESSOR_LEVEL:\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"PROCESSOR_REVISION", buffer, MAX_PATH);  
	std::wcout << L"PROCESSOR_REVISION:\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"USERDOMAIN", buffer, MAX_PATH);  
	std::wcout << L"USERDOMAIN:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"COMSPEC", buffer, MAX_PATH);  
	std::wcout << L"COMSPEC:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"PATHEXT", buffer, MAX_PATH);  
	std::wcout << L"PATHEXT:\t\t" << buffer << std::endl;  

	GetEnvironmentVariable(L"PATH", buffer, MAX_PATH);  
	std::wcout << L"PATH:\t\t" << buffer << std::endl;  
}

void test_2()
{
	DWORD dwSize = 0, dwRet = 0;
	TCHAR szBuffer[MAX_PATH] = {0};
	dwRet = GetTempPath(MAX_PATH, szBuffer);
	wcout << szBuffer << endl;
	wcout << L"dwSize = " << dwSize << endl;
	wcout << L"dwRet = " << dwRet << endl;
}


int main()  
{  
	// test_1();
	test_2();

	system("pause");  
	return 0;  
}  
