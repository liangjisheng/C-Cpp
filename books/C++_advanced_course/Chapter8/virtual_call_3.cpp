
// �����������ͨ����ѯ��������ʵ�ֵģ���ӵ���麯���Ķ��󶼿��Է��ʵ�������
// ���麯�������Ծ��ܲ�����������ȷ����ʵ��������ʽ������ã�ͨ��ָ������
// ������ָ����û��������麯������ͨ���������������õ��û��������麯��

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show() { cout << "in A" << endl; }
};

class B : public A
{
public:
	virtual void show() { cout << "in B" << endl; }
};

int main()
{
	A a;
	B &rb = static_cast<B&>(a);
	rb.show();

	system("pause");
	return 0;
}