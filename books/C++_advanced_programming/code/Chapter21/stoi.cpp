
// stoi函数默认要求输入的参数字符串是符合int范围的[-2147483648, 2147483647]，
// 否则会runtime error。
// atoi函数则不做范围检查，若超过int范围，则显示 - 2147483648（溢出下界）
// 或者2147483647（溢出上界）。

#include <iostream>
#include <string>		// for stoi, C++函数
#include <cstdlib>		// for atoi, C函数

using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1 = "343533434", s2 = "-343533434";
	char *s3 = "123456778987665642343", *s4 = "-123456778987665642343";

	cout << stoi(s1) << endl;
	cout << stoi(s2) << endl;

	// s3的数值超过了32位int所能表示的值，runtime error
	// cout << stoi(string(s3)) << endl;

	cout << atoi(s3) << endl;
	cout << atoi(s4) << endl;

	system("pause");
	return 0;
}