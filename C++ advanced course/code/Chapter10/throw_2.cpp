
// 当异常对象被拷贝时，拷贝操作是由对象的拷贝构造函数完成的，该拷贝构造函数是
// 对象的静态类型(static type)所对应类的拷贝构造函数，而不是对象的动态类型
// (dynamic type)对应的类的拷贝构造函数

#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	stuff() { n = c = 0; }
	stuff(stuff&)
	{
		cout << "stuff's copy constructor invoked" << endl;
		cout << this << endl;
	}
};

class SpecialStuff : public stuff
{
	double d;
public:
	SpecialStuff() { d = 0; }
	SpecialStuff(SpecialStuff&)
	{
		cout << "SpecialStuff's copy constructor invoked" << endl;
		Addr();
	}
	void Addr() { cout << this << endl; }
};

void passAndThrow()
{
	SpecialStuff localStuff;
	localStuff.Addr();
	stuff &sf = localStuff;
	cout << &sf << endl;
	// 抛出stuff类型的异常,调用stuff类的拷贝构造函数，即使sf引用的是
	// 一个SpecialStuff类型的对象，编译器会根据被抛出对象(这里是sf)的
	// 静态类型(static type)stuff，而不是SpecialStuff来创建相应的异常对象
	throw sf;
}


int main()
{
	try{
		passAndThrow();
	}
	catch(stuff &w){
		cout << "catched" << endl;
		// w引用的就是异常对象,所以它的地址和异常对象的地址是一样的
		cout << &w << endl;
	}

	cout << endl;
	try{
		passAndThrow();
	}
	// stuff的拷贝构造函数被调用了两次,这是因为localStuff通过拷贝构造函数
	// 传递给异常对象，而异常对象又通过拷贝构造函数传递给catch子句中的对象w
	// 实际上，抛出异常是生成的异常对象是一个临时对象，它以一种程序员不可见
	// 的方式在发挥作用
	catch(stuff w){
		cout << "catched" << endl;
		cout << &w << endl;
	}

	system("pause");
	return 0;
}

