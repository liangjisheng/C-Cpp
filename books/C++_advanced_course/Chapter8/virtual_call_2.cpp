
// �ڹ��캯���е����麯�������麯���ĵ���ʵ������ʵ���ã������麯��
// ʵ���õ���һ�����ӣ��Ӹ�����˵����һ������Ĺ��캯���������֮ǰ
// �������û����ȫ�����������ڹ��캯���е����麯����ʵ���϶���ʵ����

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show() { cout << "in A" << endl; }
	A() { show(); }
};

class B : public A
{
public:
	virtual void show() { cout << "in B" << endl; }
};

int main()
{
	A a;
	B b;

	system("pause");
	return 0;
}