
// �麯��һ�㱻����Ϊ���еģ�����ʵ���麯�����û�ȽϷ��㣬��C++���Բ�û��
// Ҫ���麯�������ǹ��еģ����麯�����ó�˽�к��ܱ����Ĳ��������麯��֮��
// �ĸ��Ǻ��麯������

#include <iostream>

using namespace std;

class A
{
	virtual void f1() { cout << "A's f1()" << endl; }
public:
	void func() { f1(); }
};

class B : public A
{
public:
	void f1() { cout << "B's f1()" << endl; }
};


int main()
{
	A a;
	B b;
	A *pa;
	B *pb;

	pa = &a;
	pa->func();
	pa = &b;
	pa->func();
	pb = &b;
	pb->f1();

	system("pause");
	return 0;
}

