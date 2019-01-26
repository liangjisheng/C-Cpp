
// explicit:��ֹ��ʽ������ĵ��������캯����ʵ���������������һ�ǽ�ֹ��ʽ
// ���ÿ������캯�������ǽ�ֹ�����֮�����ʽת���������֮�����ʽת��ֵ����
// һ���Ѿ����ڵ��������͵Ķ���������������¶��󣬶�����ʾ���ñ���Ĺ��캯��
// �������Ĺ��캯���б���Ϊת�����캯��

#include <iostream>

using std::cout;
using std::endl;


class A
{
	int num;
public:
	A();
	A(int num);
	A(const A& src);
	friend void Show(const A& src);
};

A::A()
{
	cout << "default constructor" << endl;
	num = 0;
}

A::A(int num)
{
	cout << "single parameter constructor" << endl;
	this->num = num;
}

A::A(const A& src)
{
	cout << "copy constructor" << endl;
	num = src.num;
}

void Show(const A& src)
{
	cout << src.num << endl;
}


// ����Ķ����У����κ�һ�����������캯��ǰ��explicit
// �Ϳ��Խ�ֹ�Ըù��캯������ʽ����
class B
{
	int num;
public:
	B();
	explicit B(int num);				// ��ֹ��ʽ����
	explicit B(const B& src);			// ��ֹ��ʽ����
	friend void Show1(const B& src);
};

B::B()
{
	cout << "defBult constructor" << endl;
	num = 0;
}

B::B(int num)
{
	cout << "single parameter constructor" << endl;
	this->num = num;
}

B::B(const B& src)
{
	cout << "copy constructor" << endl;
	num = src.num;
}

void Show1(const B& src)
{
	cout << src.num << endl;
}


int main()
{
	A a1 = 37;
	Show(a1);
	A a2 = a1;	
	Show(a2);
	Show(47);
	cout << endl;

	// ��ֹ��ʽ���û���������������������
	//B b1 = 37;			// error
	B b1(37);				// ok
	Show1(b1);
	//B b2 = b1;			// error
	B b2(b1);				// ok
	Show1(b2);
	//Show1(47);			// error
	Show1(B(47));			// ok

	system("pause");
	return 0;
}