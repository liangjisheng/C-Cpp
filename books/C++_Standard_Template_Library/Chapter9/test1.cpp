
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char szStr[30] = "T220001293640812";
	int n = strlen(szStr);
	string strMRZ("T22000129364081251010318");
	strMRZ = strMRZ.substr(0, 16);
	char ch = (char)0;
	szStr[16] = 0;
	szStr[17] = ch;
	szStr[18] = (char)3;
	szStr[19] = '3';

	int n1 = strlen(szStr);

	int nlen = strMRZ.length();
	strMRZ.push_back('0');
	strMRZ.push_back(char(0));
	strMRZ.push_back(char(0));
	strMRZ.push_back(char(3));

	int nlen1 = strMRZ.length();


	system("pause");
	return 0;
}