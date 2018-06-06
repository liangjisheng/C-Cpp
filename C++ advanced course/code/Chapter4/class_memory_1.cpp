
#include <iostream>

using std::cout;
using std::endl;

class A
{
	int num;
public:
	A() { num = 5; }
	void show() { cout << this << endl; cout << num << endl; }
};

class B : public A
{
	double dig;
public:
	virtual void f() {}
	void showAddr() { cout << this << endl; } 
};


int main()
{
	B b;
	cout << &b << endl;
	cout << (void*)&b << endl;
	b.showAddr();					// ��ʾ����b���׵�ַ

	cout << "\n\nBase class address:";
	A *p = &b;
	// ��ʾ���ǻ�����׵�ַ����b���׵�ַ�ǲ�һ���ģ��Ұ�����b���׵�ַ��
	cout << p << endl;
	p->show();			// ��ʾ����ĵ�ַ
	b.show();			// ��ʾ��Ҳ�ǻ���ĵ�ַ


	system("pause");
	return 0;
}