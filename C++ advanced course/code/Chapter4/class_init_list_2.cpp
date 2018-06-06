
// �����Ͽ����кܶ���Ĺ��캯������û��ʹ�ó�ʼ���б���ʵ���ϣ��Ժ�д���ݲ���
// ��û����ʾд����ʼ���б������ǿ�мӽ�ȥ����Щ���ݰ�����
// 1�����������ĳ����������࣬��ô����ֱ�ӻ���Ĺ��캯��һ��Ҫ�����ڳ�ʼ���б�
// �У�Ҫô�ǳ���Ա��ʾ���ڳ�ʼ���б��е���ֱ�ӻ���Ĺ��캯���������������ֱ��
// �����Ĭ�Ϲ��캯�����뵽��ʼ���б���
// 2������������������Ķ�����Ϊ���ݳ�Ա����ô��Щ����ĳ�ʼ������Ҳһ��Ҫ��
// ��ʼ���б�����ɡ�Ҫô�ǳ���Ա��ʾ���ڳ�ʼ�����б��и�������Ĺ�����ʽ������
// ���������ڳ�ʼ���б��е�����Щ�����Ĭ�Ϲ��캯������ɳ�ʼ��

#include <iostream>

using std::cout;
using std::endl;

class A
{
	int num;
public:
	A() { cout << "In default constructor" << endl; }
	A(int i) { cout << "In user-defined constructor" << endl; num = i; }
	A& operator= (const A& a)
	{
		cout << "Using assignment" << endl;
		num = a.num;
		return *this;
	}
	void show() { cout << num << endl; }
};


class B
{
	A a;
public:
	B(int i);
	void show() { a.show(); }
};

// �ȵ���A(int)����һ�����������ٵ��ø�ֵ�����
B::B(int i) { a = A(i); }


class B1
{
	A a;
public:
	B1(int i);
	void show() { a.show(); }
};

// �ȵ���A(int)����һ�����������ٵ��ø�ֵ�����
B1::B1(int i) : a(i) {}


int main()
{
	B b(1);
	b.show();

	B1 b1(1);
	b1.show();

	system("pause");
	return 0;
}

