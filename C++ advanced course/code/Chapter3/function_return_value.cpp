
// �����ķ���ֵӦ�÷���ʲô�ط��ˣ��Ӹ�����˵�������ķ���ֵӦ�÷��ڱ����ú���������
// ����֮����������������Ч���ʵĵط������һ�������ķ���ֵӦ���Ǵ��������������
// ���ٵ�ջ�ռ��ϡ����ż����Ӳ���ķ�չ��CPU��ͨ�üĴ������ֳ������ӣ�����Ҳ������
// ��ˣ������Ĳ������ݣ���������ֵ�Ĵ��ݵȹ������ںܶ�����¶�����ͨ���Ĵ������
// ����һ��Ҫ�����ڼ�����Ĵ洢��

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

struct LittleStruct
{
	int num1;
	int num2;
};

int gvar;

char ReturnChar() 
{
	char c = 'c';
	return c;
}

short ReturnShort()
{
	short h = 6;
	return h;
}


int ReturnInt()
{
	int i = 9;
	return i;
}


double ReturnDouble()
{
	double d = 5.7;
	return d;
}


int* ReturnPtr() { return &gvar; }

LittleStruct ReturnLitter()
{
	LittleStruct a = {12, 34};
	return a;
}


class A
{
	char c;
	int i;
	double d;
public:
	A() { c = '0'; i = 1; d = 2.3; }
};


A ReturnObject()
{
	A a;
	return a;
}


int main()
{
	char c;
	short h;
	int i, *p;
	double d;
	LittleStruct s;

	c = ReturnChar();
	h = ReturnShort();
	i = ReturnInt();
	d = ReturnDouble();
	p = ReturnPtr();
	s = ReturnLitter();

	cout << c << endl
		<< h << endl
		<< i << endl
		<< d << endl
		<< *p << endl
		<< s.num1 << endl
		<< s.num2 << endl;

	cout << endl;
	cout << sizeof(A) << endl;
	A a;
	a = ReturnObject();

	getchar();
	return 0;
}