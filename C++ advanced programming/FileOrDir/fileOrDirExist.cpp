
// 判断文件或者文件夹是否存在
#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

// 判断文件是否存在
bool IsFileExist(const char* szFile)
{
	WIN32_FIND_DATAA wfd;
	bool bExist = false;
	HANDLE hFind = FindFirstFileA(szFile, &wfd);
	if(hFind == INVALID_HANDLE_VALUE)
		return false;
	FindClose(hFind);
	
	return 0 == (FILE_ATTRIBUTE_DIRECTORY & wfd.dwFileAttributes);
}

// 判断文件夹是否存在
bool IsDirExist(const char* szDir)
{
	WIN32_FIND_DATAA wfd;
	bool bExist = false;
	HANDLE hFind = FindFirstFileA(szDir, &wfd);
	if(hFind == INVALID_HANDLE_VALUE)
		return false;
	FindClose(hFind);
	
	return 0 != (FILE_ATTRIBUTE_DIRECTORY & wfd.dwFileAttributes);
}

// 判断文件或文件夹是否存在
bool FileOrDirExist(const char* szPath)
{
	WIN32_FIND_DATAA wfd;
	bool bExist = false;
	HANDLE hFind = FindFirstFileA(szPath, &wfd);
	if(hFind != INVALID_HANDLE_VALUE)
		bExist = true;
	FindClose(hFind);
	return bExist;
}

int main()
{
	// 判断是否为目录时，最后不能添加路径分割符
	// 否则，即使存在，也会判断成不存在
	char szPath[] = "D:\\test\\test";
	char szPath1[] = "D:\\JPG";

	bool bExist = FileOrDirExist(szPath);
	bool bExist1 = FileOrDirExist(szPath1);

	if(bExist)
		cout << "directory exist." << endl;
	else
		cout << "directory not exist." << endl;

	if(bExist1)
		cout << "directory exist." << endl;
	else
		cout << "directory not exist." << endl;


	char szFile[] = "D:\\JPG\\0.jpg";
	bool bFileExist = FileOrDirExist(szFile);
	if(bFileExist)
		cout << "file exist" << endl;
	else
		cout << "file not exist" << endl;

	char szFile1[] = "D:\\JPG\\100.jpg";
	bool bFileExist1 = FileOrDirExist(szFile1);
	if(bFileExist1)
		cout << "file exist" << endl;
	else
		cout << "file not exist" << endl;

	system("pause");
	return 0;
}