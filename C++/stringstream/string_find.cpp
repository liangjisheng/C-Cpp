
#include <iostream>
#include <vector>
#include <string>
#include <tchar.h>
#include <string.h>

using namespace std;

/************************************************************************/
/*	查找一个字符在一个字符串中第n次出现的位置
	first parameter str: source string
	second parameter c: find char
	third parameter n: Nst show
	return : index of c in str*/
/************************************************************************/
int FindNstPosition(const char* str, char c, int n)
{
	// ASSERT(str);
	if(!str || c == '\0')
		return -1;
	
	const char * p = str;
	int nIndex = 0;
	int nCount = 0;

	while(*p != '\0')
	{
		if(*p == c)
		{
			nCount++;
			if(nCount == n)
				return nIndex;
			else
			{
				nIndex++;
				p++;
			}
		}
		else
		{
			nIndex++;
			p++;
		}
	}
	return -1;
}


/************************************************************************/
/*	以指定的分割符分割字符串，并将分割后的字符串放到vector<string>中
	src: source string
	separator : separator string
	dest : dest vector string
*/
/************************************************************************/
void mySplit(const string& src, const string& separator, vector<string>& dest)
{
	string str = src;
	string substring = "";
	string::size_type start = 0, nIndex = 0;

	do 
	{
		nIndex = str.find_first_of(separator, start);
		if(nIndex != string::npos)
		{
			substring = str.substr(start, nIndex - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, nIndex);
			if(start == string::npos)
				return;
		}
	} while (nIndex != string::npos);

	// the last token
	substring = str.substr(start);
	dest.push_back(substring);
}


int main()
{
	vector<string> vecStr;
	vecStr.push_back("test1&test2&test3&test4&test5&test6");

	cout << vecStr[0] << endl;
	cout << "sizeof(vecStr[0]) = " << sizeof(vecStr[0]) << endl;
	cout << "strlen(vecStr[0]) = " << strlen(vecStr[0].c_str()) << endl;

	int nIndex = FindNstPosition(vecStr[0].c_str(), 'e', 5);
	cout << nIndex << endl;
	
	cout << endl;
	vector<string> strDest;
	string separator = "&";
	mySplit(vecStr[0], separator, strDest);

	for(size_t i = 0; i < strDest.size(); i++)
		cout << strDest[i] << endl;

	system("pause");
	return 0;
}