
#include <iostream>
#include <string>

using namespace std;

void test()
{
	string s1, s2;

	cout << (s1 == s2) << endl;
	cout << (s1 < "hello") << endl;
	cout << (string("aaaa") < string("bbbb")) << endl;
	cout << (string("aaaa") < string("abba")) << endl;
	cout << (string("aaaa") < string("aaaaaa")) << endl;
	cout << endl;

	// compare()��Ա������ȷ���0�� С��0��ʾС�ڣ�����0��ʾ����
	string s("abcd");
	cout << s.compare("abcd") << endl;
	cout << s.compare("dcba") << endl;
	cout << s.compare("ab") << endl;

	cout << s.compare(s) << endl;
	cout << s.compare(0, 2, s, 2, 2) << endl;	// return a value < 0("ab" is less than "cd")
	cout << s.compare(1, 2, "bcx", 2) << endl;	// return 0 ("bc" is equal to "bc")
}

int main()
{
	test();

	system("pause");
	return 0;
}