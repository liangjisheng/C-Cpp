
// C++�ڿ⺯���ж�������Ӧ�Ĵ���Unicode�Ĵ���������
#include <iostream>
#include <cstring>

using std::cout;
using std::wcout;
using std::endl;


void test()
{
	char *p = NULL;
	wchar_t s[] = L"ABC";				// ռ8���ֽ�
	char name[] = "����";				// ռ5���ֽ�
	wchar_t wname[] = L"����";			// ռ6���ֽ�
	cout << sizeof(wchar_t) << endl;
	cout << sizeof(s) << endl;
	p = (char *)s;
	for(int i = 0; i < sizeof(s); i++)
		cout << (int)p[i] << " ";
	cout << endl;

	cout << s << " ";
	wcout << s << endl;
	// char���͵��ַ����У�һ�������ַ��������ֽڱ�ʾ���������ֽڵ����λ����1
	// ���Ե����ֽ����ʱ���������Ľ����������Ǹ���
	for(int i = 0; i < sizeof(name); i++)
		cout << (int)name[i] << " ";
	cout << endl;

	p = (char *)wname;
	// wchar_t���͵��ַ�����ÿ���ַ�(���������ַ�)������˫�ֽڱ�ʾ���ַ������
	// Ϊ��û��ҪΪ1�ˣ��������������������
	for(int i = 0; i < sizeof(wname); i++)
		cout << (int)p[i] << " ";
	cout << endl;

	cout << name << endl;
	// �������仰��û������������������ABCȷ��ȷ��ʾ�����ǿ���̨�����е�һ��
	// ���������̨��ȱʡ���Ի����������йأ�Ϊ���ܹ����õ�֧�ֶ������Է��ŵ�
	// ��ʾ��IO���������һ��locale��Ķ������������Ի�����Ϊ���ܹ���ʾ���֣�����
	// ������̨���Ի������ó���ʾ����
	wcout.imbue(std::locale("chs"));
	wcout << wname << endl;

	// ���ó�����֮�󣬻�������������ַ�
	cout << "test" << endl;
}


int main()
{
	test();

	system("pause");
	return 0;
}