
// ��ĳ���������߱��ʽ���������ã�����������ת������һ�������������

#include <iostream>

using std::cout;
using std::endl;

int test_max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	char c = 'a';
	const int &rc = c;					// �����÷�����ʽ����ת��
	cout << (void*)&c << endl;
	// ������������ڴ��ַ��ͬ��˵��rc���õ���ת���������������
	// ��rc����洢�������������ĵ�ַ��������c�ĵ�ַ
	cout << (void*)&rc << endl;

	int i = 7;
	const int& ri = i;
	cout << (void*)&i << endl;
	cout << (void*)&ri << endl;

	// �Ƚ�5.5ת����������int���ͱ�����Ȼ���ڽ����Ը����������ĳ�����
	cout << test_max(rc, 5.5) << endl;

	system("pause");
	return 0;
}