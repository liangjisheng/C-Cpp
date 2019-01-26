
// Ŀǰ�㷺ʹ�õı���ģʽ��3�֣���Ӧ��3���ַ�����
// ��һ���ǵ��ֽ��ַ���(single-byte character set or SBCS).������ģʽ������
// �ַ���ֻ��һ���ֽڱ�ʾ��ASCII��SBCS��
// �ڶ����Ƕ��ֽ��ַ���(multi-byte character set or MBCS).һ��MBCS�������
// һЩһ���ֽڳ����ַ���������һЩ�ַ�����һ���ֽڵĳ��ȡ�����windows���
// MBCS���������ַ����ͣ����ֽ��ַ���˫�ֽ��ַ�������windows��ʹ�õĶ��ֽ�
// �ַ����󲿷ֶ��������ֽڳ�������MBCS����DBCS����
// ��������Unicode���롣Unicode��һ�����е��ַ���ʹ�������ֽڱ���ı���ģʽ��


#include <iostream>
#include <string>

using namespace std;

int main()
{
	char chs[] = "Hello";
	string s0("");
	string s1(chs);
	string s2("World");
	string s3(chs, 1, 3);
	string s4(s2);
	string s5(chs, 3);
	string s6(10, 'k');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	cout << "sizeof s1 is " << s1.size() << endl;
	cout << "length of s1 is " << s1.length() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	cout << "max_size of s1 is " << s1.max_size() << endl;
	cout << "length of s0 is " << s0.length() << endl;
	cout << "capacity of s0 is " << s0.capacity() << endl;

	if(s0.empty())
		cout << "s0 is empty" << endl;

	system("pause");
	return 0;
}

