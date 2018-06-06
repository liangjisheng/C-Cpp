// 判断目录是否存在
#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

bool FolderExist(const char* szPath)
{
	WIN32_FIND_DATAA wfd;
	bool bExist = false;
	HANDLE hFind = FindFirstFileA(szPath, &wfd);
	if(hFind != INVALID_HANDLE_VALUE 
		&& (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
		bExist = true;

	FindClose(hFind);
	return bExist;
}

int main()
{
	// 不能加路径分割符，加上的话即使目录存在，这个句柄也打不开
	char szPath[] = "D:\\JPG";
	bool bExist = FolderExist(szPath);
	if(bExist)
		cout << "folder exist." << endl;
	else
		cout << "folder not exist." << endl;

	system("pause");
	return 0;
}