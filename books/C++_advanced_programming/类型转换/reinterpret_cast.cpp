#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	int m_a;
};

class B
{
public:
	int m_b;
};

class C : public A, public B
{

};

int main()
{
	C c;
	cout << &c << endl
		<< reinterpret_cast<B*>(&c) << endl
		<< static_cast<B*>(&c) << endl;

	//ǰ���������ֵ����ͬ�ģ����һ�������ԭ������ƫ��4���ֽڣ�
	//������Ϊstatic_cast�����˸�����ָ��ת����ƫ������
	//����֮ת������ȷ�ĵ�ַ��c������m_a,m_b��ת��ΪB*ָ���ָ��m_b������
	//��reinterpret_castȴ��������һ��ת����

	system("pause");
	return 0;
}