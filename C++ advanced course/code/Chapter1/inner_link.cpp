
#include <iostream>

using namespace std;

template<char* p>
class Exmaple
{
public:
	void display() { cout << *p << endl; }
};

static char c = 'a';


namespace { char c1 = 'a'; }


int main()
{
	// static ���εı���(����)�����ڲ��������ԣ��������ڲ��������Եı�����
	// ��������ʵ����һ��ģ��ķ����Ͳ������������ֱ������
	// Exmaple<&c> a;
	// a.display();

	// ����Ĵ�������������벢������ɴ˿����������������ֿռ��е�ȫ�ֱ���(����)
	// �����ⲿ�������ԣ�����static���εı������ߺ��������ڲ��������ԣ�
	Exmaple<&c1> a1;
	a1.display();

	system("pause");
	return 0;
}