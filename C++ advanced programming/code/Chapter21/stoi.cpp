
// stoi����Ĭ��Ҫ������Ĳ����ַ����Ƿ���int��Χ��[-2147483648, 2147483647]��
// �����runtime error��
// atoi����������Χ��飬������int��Χ������ʾ - 2147483648������½磩
// ����2147483647������Ͻ磩��

#include <iostream>
#include <string>		// for stoi, C++����
#include <cstdlib>		// for atoi, C����

using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1 = "343533434", s2 = "-343533434";
	char *s3 = "123456778987665642343", *s4 = "-123456778987665642343";

	cout << stoi(s1) << endl;
	cout << stoi(s2) << endl;

	// s3����ֵ������32λint���ܱ�ʾ��ֵ��runtime error
	// cout << stoi(string(s3)) << endl;

	cout << atoi(s3) << endl;
	cout << atoi(s4) << endl;

	system("pause");
	return 0;
}