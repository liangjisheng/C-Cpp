
// thisָ���ڶ���Ĺ��캯���оͿ���ʹ���ˣ����캯�����ڶ������ڴ�ռ��
// �Գ�Ա�������г�ʼ���Ĺ��̣�����ʹ��һ��ȫ��ָ������²�����ĳ�������
// ������Ķ���

#include <iostream>

using std::cout;
using std::endl;

extern class A *pA;		// ��������pA

class A
{
public:
	A() { pA = this; }
	virtual void show() { cout << "in A" << endl; }
};

class B : public A
{
	int i;
public:
	B() { i = 5; }
	void show()
	{
		cout << "in B" << endl;
		cout << "i = " << i << endl;
	}
};

A *pA;			// �������pA


int main()
{
	B b;
	pA = &b;
	pA->show();

	system("pause");
	return 0;
}