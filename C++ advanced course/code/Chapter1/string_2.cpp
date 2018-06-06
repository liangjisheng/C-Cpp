
#include <string>
#include <iostream>

using namespace std;

void test()
{
	char chs[] = "Hello";
	string s1(chs);
	cout << s1 << endl;

	string s2("World");
	s1 = "some";
	cout << s1 << endl;
	s1.assign("another");
	cout << s1 << endl;
	s1.assign("looking", 5);
	cout << s1 << endl;
	s1.swap(s2);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	
	s2 += "ng";
	cout << s2 << endl;
	s2.append(" at");
	cout << s2 << endl;
	s2.push_back('k');
	cout << s2 << endl;
	// ������8��ʼ3���ֽڵ��ַ��滻��"at me"
	s2.replace(8, 3, "at me");
	cout << s2 << endl;
	s2.insert(0, "You are ");
	cout << s2 << endl;
	s2.insert(s2.size(), " now");
	cout << s2 << endl;

	s2.erase(0, 4);
	cout << s2 << endl;
	s2.replace(0, 4, "");		// �滻�ɿյģ�������ɾ��
	cout << s2 << endl;

	s1.clear();
	cout << "s1 = " << s1 << endl;
	s1 = "World";
	s1.erase(0, s1.length());		// ɾ��ȫ���ַ���
	cout << "s1 = " << s1 << endl;
	s1 = "World";
	s1.replace(0, s1.length(), "");
	cout << "s1 = " << s1 << endl;
}


void test_1()
{
	string s1 = "abcdefg";
	string s2 = "abcdefg";
	if(s1 == s2)
		cout << "s1 == s2" << endl;
	else
		cout << "s1 != s2" << endl;

	if(s1 != s2)
		cout << "s1 != s2" << endl;
	else
		cout << "s1 == s2" << endl;

	if(s1 > s2)
		cout << "s1 > s2" << endl;
	else
		cout << "s1 <= s2" << endl;

	if(s1 < s2)
		cout << "s1 < s2" << endl;
	else
		cout << "s1 >= s2" << endl;
}


void test_2()
{
	int i = 0;
	string s = "abcdefg1111";
	cout << "use[]:" << endl;
	for(i = 0; i < s.length(); i++)
		cout << s[i];
	cout << endl;

	cout << "use at(): " << endl;
	for(i = 0; i < s.length(); i++)
		cout << s.at(i);
	cout << endl;

	s[s.length() - 1] = '2';
	cout << s << endl;

	const char* chs1 = s.c_str();
	const char* chs2 = s.data();
	// c_str()���ص���C�����ַ�����Ҳ����˵���һ���ַ���'\0',��
	// data()�򷵻�һ���ַ�������׵�ַ��������֤��������а���Ԫ��'\0'
	// ����const char*,ֻ��ͨ�����ص�ָ������ȡ�ַ������������޸��ַ���
	cout << "c_str(): " << chs1 << endl;
	cout << "data(): " << chs2 << endl;

	string str = s.substr(5, 3);
	cout << str << endl;

	string pattern = "fg";
	string::size_type pos;
	// ������0��ʼ�����ҵ�һ�γ���"fg"������ֵ
	pos = s.find(pattern, 0);
	cout << pos << endl;
	if(pos != string::npos)
	{
		string str1 = s.substr(pos, pattern.size());
		cout << str1 << endl;
	}

	for(string::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << *iter;
	cout << endl;
}


int main()
{
	// test();
	// test_1();
	test_2();

	system("pause");
	return 0;
}

