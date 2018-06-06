
// 函数的返回值应该放在什么地方了？从概念上说，函数的返回值应该放在被调用函数的运行
// 结束之后，主调函数可以有效访问的地方，因此一个函数的返回值应该是存放在由主调函数
// 开辟的栈空间上。随着计算机硬件的发展，CPU的通用寄存器的字长在增加，个数也在增多
// 因此，像函数的参数传递，函数返回值的传递等工作，在很多情况下都可以通过寄存器完成
// 并非一定要借助于计算机的存储器

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