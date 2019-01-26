
// 在catch子句中进行异常匹配时可以进行两种类型转换:第一种是子类与基类间的转换
// 一个用来捕获基类的catch子句也可以处理派生类类型的异常，这种转换可以用于传值、
// 引用以及指针上.第二种是允许从一个类型化指针(typed pointer)转变为无类型指针
// (untyped pointer),所以带有const void*指针的catch子句能捕获任何类型的指针异常

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
	SpecialStuff() { d = 0.0; }
	SpecialStuff(SpecialStuff&)
	{
		cout << "SpecialStuff's copy constructor invoked" << endl;
		// cout << this << endl;
		Addr();
	}
	void Addr() { cout << this << endl; }
};

void passAndThrow()
{
	SpecialStuff localStuff;
	localStuff.Addr();
	throw localStuff;
}

void throwPointer()
{
	static int i = 4;
	throw &i;
}


int main()
{
	try{
		passAndThrow();
	}
	catch(stuff &w){
		cout << "catched" << endl;
		cout << &w << endl;
	}

	cout << endl;
	try{
		throwPointer();
	}
	catch(void *p){
		cout << "catched pointer is " << p << endl;
	}

	system("pause");
	return 0;
}