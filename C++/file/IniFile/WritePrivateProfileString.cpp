
// 写配置文件
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <string.h>

using std::cout;
using std::endl;

int main()
{
	char lpPath[MAX_PATH] = { 0 };
	int nLen = strlen("D:\\myIniFile.ini");		// 16
	nLen = strlen(lpPath);						// 0
	strcpy_s(lpPath, strlen("D:\\myIniFile.ini") + 1, "D:\\myIniFile.ini");

	WritePrivateProfileStringA(
		"LiMing",
		"Sex",
		"Man",
		lpPath);
	WritePrivateProfileStringA("LiMing", "Age", "20", lpPath);

	WritePrivateProfileStringA("Fangfang", "Sex", "Woman", lpPath);
	WritePrivateProfileStringA("Fangfang", "Age", "18", lpPath);

	cout << "success" << endl;


	cout << endl;
	// 读取配置文件
	cout << "LiMing personal information." << endl;
	char Sex[20] = { 0 };
	GetPrivateProfileStringA(
		"LiMing",		// 应用程序名，节名
		"Sex",			// 键名
		"",				// 默认返回值，如果没有获取到键值
		Sex,			// 获取返回键值
		6,				// 缓冲区大小
		lpPath);		// INI文件的路径

	cout << Sex << endl;
	int Age = 0;
	Age = GetPrivateProfileIntA(
		"LiMing",	// 应用程序名，节名
		"Age",		// 键名
		0,			// 默认返回值，如果没有获取到键值
		lpPath);	// INI文件的路径
	cout << Age << endl;

	cout << "Fangfang personal information." << endl;
	GetPrivateProfileStringA("Fangfang", "Sex", "", Sex, 6, lpPath);
	cout << Sex << endl;
	Age = 0;
	Age = GetPrivateProfileIntA("Fangfang", "Age", 0, lpPath);
	cout << Age << endl;

	system("pause");
	return 0;
}