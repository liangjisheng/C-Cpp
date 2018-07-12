
// 时程序需要保持和某个指定网络的连通，有人的情况下我们直接用ping命令查看即可，
// 然而程序自身检测会稍微麻烦一点
// 实现思路如下:
// 用程序打开控制台->运行ping命令，并指定控制台返回值写入到文件中->分析文件，
// 得到ping命令返回状态->得到网络连通情况

#include <Windows.h>
#include <stdio.h>
#include <string>

using namespace std;


bool AnalysisFile()
{
	FILE* file = NULL;
	char ln[80] = {0};
	char* szFileName = "C:\\Users\\Public\\returnpingdata.txt";
	fopen_s(&file, szFileName, "r");

	if (file)
	{
		fgets(ln, 80, file);	// 读入空行舍弃
		memset(ln, 0, 80);
		fgets(ln, 80, file);	// 读入ping信息，舍弃
		memset(ln, 0, 80);
		fgets(ln, 80, file);	// 读入ping对象返回值，用来分析

		string data = ln;
		if (data != "")
		{
			int ipos = data.find("=");
			if (ipos != string::npos)
			{
				data = data.substr(ipos + 1, 3);	// 截取字符串返回字节数
				int n = atoi(data.c_str());
				fclose(file);
				remove(szFileName);
				return n > 0;
			}
			else
			{
				fclose(file);
				remove(szFileName);
				return false;
			}
		}
		else
		{
			fclose(file);
			remove(szFileName);
			return false;
		}
	}
	else
		return false;
}

int main()
{
	// -n 1 指定发送1位数据
	// -w 1000 指定超过1000ms为超时
	// > returnpingdata.txt将命令行返回值输出到returnpingdata.txt文件中
	char *cmdstr = "cmd /c ping www.baidu.com -n 1 -w 1000 > C:\\Users\\Public\\returnpingdata.txt";
	WinExec(cmdstr, SW_HIDE);
	Sleep(800);

	// 分析命令行返回文件，得到网络连接情况
	bool bOnline = AnalysisFile();
	if (bOnline)
		printf("ok online\n");
	else
		printf("failed outline");

	getchar();
	return 0;
}