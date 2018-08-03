
/***********************************************************
 * @name: CountLines.cpp
 * @brief: 计算文件的行数
 * @author: 梁基圣
 * @date: 2018/7/26 16:56:47
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int CountLines(const char* lpFileName)
{
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


int main(int argc, char** argv)
{
	int nAllFileLines = 0;
	for (int i = 1; i < argc; ++i)
		nAllFileLines += CountLines(argv[i]);

	std::cout << nAllFileLines << std::endl;
	
	return 0;
}

