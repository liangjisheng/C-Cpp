
#include <iostream>

using std::cout;
using std::endl;

// sizeof��һ���ڱ����ǽ��е����㣬�����������޹أ����Ե�sizeof�Ĳ�����
// ��������ʽ�ǣ�sizeof�����������ĵ��Ǳ�������ʽ�����ͣ������Ǳ�����
// ���ʽ��ֵ������sizeof(i = 5)�ȼ���sizeof(int),Ҳ����˵���ڿ�ִ�д���
// �У���������i = 5������ʽ�������ڱ���׶ξͱ������ˣ��ڶ������i = 9

int main()
{
	int i = 9;
	cout << "i = " << i << endl;
	cout << "sizeof(i) = " << sizeof(i) << endl;
	cout << "sizeof(i = 5) = " << sizeof(i = 5) << endl;
	cout << "i = " << i << endl;			// i = 9
	
	system("pause");
	return 0;
}