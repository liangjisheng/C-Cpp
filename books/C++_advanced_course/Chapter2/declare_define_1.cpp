
// һ������£�����ͨ���ı��ඨ���λ�ã����Ա�����ǰ�������࣬
// ���Ⲣ�����κ�ʱ���е�ͨ��

#include <iostream>

using std::cout;
using std::endl;


class A;

class B
{
public:
	void show(const A& src);
};

class A
{
private:
	int i;
public:
	A(int in) { i = in; }
	friend void B::show(const A& src);
};

void B::show(const A& src) { cout << src.i << endl; }


void test()
{
	int i = 5;
	double d = 6.6;
	typedef int* ptr;
	ptr p1 = &i;
	cout << *p1 << endl;

	// typedef��C++�б�����������䣬ԭ���������������µ���������
	// ʹ��typedefʱҪ��ֹ��ͬһ����ʾ�������͵ı�ʶ��������ͬ�Ľ���
	// typedef double* ptr;
	// ptr p2 = &d;
	// cout << *p2 << endl;
}


int main()
{
	A a(5);
	B b;
	b.show(a);

	test();

	system("pause");
	return 0;
}

