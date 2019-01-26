
#include <stdio.h>


class A
{
	char c;
	int i;
	double d;
public:
	A () { c = '0'; i = 1; d = 2.3; }
};


A ReturnObject()
{
	A a;
	return a;
}

int ReturnInt () 
{
	printf("in ReturnInt\n");
	return 1; 
}

typedef void(*Ptr)();


int main()
{
	Ptr p;
	p = reinterpret_cast<Ptr>(ReturnObject);
	// 调用ReturnObject返回的是一个体积较大的对象，所以主调函数为接受这个
	// 对象会在栈上创建一个临时对象(或者经过优化之后利用一个已经存在的对象
	// 接受返回值)，但p所代表的函数，其返回值类型是void，因此主调函数main()
	// 在通过p实现函数调用时，并没有为函数调用准备接受返回值的空间，在
	// ReturnObject内，当执行到return a;时会发送运行是错误，返回值被非法
	// 地写入到其它变量占据的空间，使程序运行处于未知状态。
	//p();
	p = reinterpret_cast<Ptr>(ReturnInt);

	// 这个函数指针实现的函数调用是安全的，返回值会写入寄存器eax中，如果在
	// 主调函数main()中不使用eax的值，对函数的运行不会造成任何影响
	p();

	getchar();
	return 0;
}