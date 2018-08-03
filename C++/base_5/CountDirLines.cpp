
/***********************************************************
 * @name: CountFiles.cpp
 * @brief: 统计指定目录下的文件个数和所有文件总共的行数
 * @author: 梁基圣
 * @date: 2018/8/1 11:29:44
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <fstream>
#include <io.h>
#include <string.h>
#include <string>

using namespace std;

int CountFileLines(const char* lpFileName)
{
	if (NULL == lpFileName)
		return 0;

	fstream fin(lpFileName, std::ios::in);
	if (!fin)
		return 0;

	char c;
	int nLineCounts = 0;
	while (fin.get(c))
	{
		if (c == '\n')
			nLineCounts++;
	}
	fin.close();
	return nLineCounts + 1;
}

void CountDirLines(const char* lpDirName, int& nAllFileLines)
{
	if (NULL == lpDirName)
		return ;

	_finddata_t fdata;				// 定义文件查找结构对象
	long done = 0;
	string strDir = string(lpDirName) + string("*.*");

	done = _findfirst(strDir.c_str(), &fdata);	// 开始查找文件
	if (-1 == done)
		return ;
	
	int ret = 0;
	while (ret != -1) 
	{
		if (fdata.attrib != _A_SUBDIR) 
		{
			if (strcmp(fdata.name, "...") != 0 &&
				strcmp(fdata.name, "..") != 0 &&
				strcmp(fdata.name, ".") != 0)	// 过滤
			{
				string strFile = string(lpDirName) + string(fdata.name);
				nAllFileLines += CountFileLines(strFile.c_str());
			}
		}
		ret = _findnext(done, &fdata);
		if (fdata.attrib == _A_SUBDIR && ret != -1)	// 判断文件属性，如果是目录，则递归调用
		{
			if (strcmp(fdata.name, "...") != 0 &&
				strcmp(fdata.name, "..") != 0 &&
				strcmp(fdata.name, ".") != 0)
			{
				string strDir = string(lpDirName) + string(fdata.name) + "\\";
				CountDirLines(strDir.c_str(), nAllFileLines);
			}
		}
	}
}


int main(int argc, char** argv)
{
	if (argc < 2)
		return 0;

	for (int i = 1; i < argc; ++i)
	{
		string strDir = argv[i];
		if (strDir[strDir.size() - 1] != '\\')
			strDir += "\\";

		int nLines = 0;
		CountDirLines(strDir.c_str(), nLines);
		cout << strDir << "目录下的所有文件总共有" << nLines << "行" << endl;
	}

	return 0;
}
