
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * function: 十六进制的字符串转换成十进制整数
 * param: str:字符串
 * return: 转换后的十进制整数
*/
int HexToDec(const string &strHexs)
{
	int nRes = 0;
	int nLen = strHexs.length();
	int nWeight = 1;

	for (int i = nLen - 1; i >= 0; i--)
	{
		if (strHexs[i] >= 'A' && strHexs[i] <= 'F')
			nRes += (strHexs[i] - 'A' + 10) * nWeight;
		else if (strHexs[i] >= 'a' && strHexs[i] <= 'f')
			nRes += (strHexs[i] - 'a' + 10) * nWeight;
		else
			nRes += (strHexs[i] - '0') * nWeight;
		nWeight *= 16;
	}

	return nRes;
}
