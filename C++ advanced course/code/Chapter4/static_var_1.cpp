
// ���﷨�ϣ���ľ�̬��Ա����Ҳ���Լ̳У�����ͨ������������������ʻ�����
// �����ľ�̬���������ǲ�����ͨ�����������ʻ���ͨ�������������ʣ�����ָ��ͬ��
// �ı���

#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	static int num;
};

int A::num = 10;

class B : public A
{
public:
	static void change() { num = 12; }
};

// int B::num = 14;				// ���󣬲��ܺ��γ�ʼ����̬����


class A1
{
public:
	static int num;
};

int A1::num = 10;

class B1 : public A1
{
public:
	static double num;
	static void change() { num = 12; }
};

double B1::num = 14;


int main()
{
	cout << B::num << endl;
	B::change();
	cout << A::num << endl;
	cout << B::num << endl;

	cout << endl;
	cout << B1::num << endl;
	B1::change();
	cout << A1::num << endl;
	cout << B1::num << endl;

	system("pause");
	return 0;
}