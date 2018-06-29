
#include <iostream>
// #include <strstream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::stringstream;
using std::string;

void int2str(string &strdest, const int src)
{
	stringstream stream;
	stream << src;
	// 也可以使用stream >> strdest;
	strdest = stream.str();
}

void str2int(int &numdest, const string &strsrc)
{
	stringstream stream(strsrc);
	stream >> numdest;
}

void int2str_C(string &strnum, const int num)
{
	char s[15] = {0};		// 设定15位对于存储32位int值足够了
	itoa(num, s, 13);
	strnum = s;
}


int main()
{
	int num = 4;
	string strnum = "";
	int2str(strnum, num);
	cout << strnum << endl;

	num = 0;
	str2int(num, strnum);
	cout << num << endl;

	strnum = "";
	int2str_C(strnum, num);
	cout << strnum << endl;

	system("pause");
	return 0;
}