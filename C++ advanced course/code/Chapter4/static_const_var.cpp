
// ���ֻ����̬���ݳ�Ա�ĳ�ʼ�������������ڲ����У�Ҳ�����������ⲿ���С�
// ���Ƿǳ������һ�ֳ�ʼ����ʽ����ΪC++�﷨��Ϊ�����е��������ǶԱ���
// �����������Ƕ��壬һ������£��������������ڲ�ָ����Ա�����ĳ�ֵ
// �������ڲ�����Ա������ֵ�������﷨��ǿ����ľ�̬�������ݳ�Ա�ǽ�������
// ��ص�����

#include <iostream>

using std::cout;
using std::endl;


class A
{
public:
	static const int i;
	// ֻ��ʹ�ñ���ʱ��������ľ�ֻ̬����Ա��ֵ������ʹ�ñ������ߺ����ķ���ֵ��
	static const int j = 5;			// ok
	// const int k = 6;				// error
};

const int A::i = 4;


int main()
{
	cout << A::i << endl;
	cout << A::j << endl;

	system("pause");
	return 0;
}
