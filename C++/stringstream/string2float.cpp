
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void str2float(float &f, const string &strsrc)
{
	f = atof(strsrc.c_str());
}

int main()
{
	string str = "123.456";
	float f = 0.0;
	str2float(f, str);
	cout << f << endl;

	system("pause");
	return 0;
}