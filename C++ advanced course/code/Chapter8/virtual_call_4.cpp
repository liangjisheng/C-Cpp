
// ��ʵ��Ӧ���У��������������õ�ȷ�ǽ�����ָ�������ʵ�ֵ�
// �����Ⲣ��˵��������ʽ��һ������ʵ�������

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show() { cout << "in A" << endl; }
	void callfunc() { show(); }
};

class B : public A
{
public:
	virtual void show() { cout << "in B" << endl; }
};

int main()
{
	B b;
	// ��������b.callfunc()����ʵ��ִ�е���A::callfunc()��show()��һ���麯��
	// ���һ������ã�����������ʱ�ž���ʹ���������е��麯�����ǻ����е��麯��
	b.callfunc();

	system("pause");
	return 0;
}