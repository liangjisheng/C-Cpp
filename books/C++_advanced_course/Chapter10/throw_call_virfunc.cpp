
// 采用传引用的方式捕捉异常时，还有可能发生虚函数调用

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void what() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
	virtual void what() { cout << "Derived" << endl; }
};

void f() { throw Derived(); }


int main()
{
	try{
		f();
	}
	catch(Base b){
		b.what();
	}

	try{
		f();
	}
	catch(Base &b){
		b.what();
	}

	system("pause");
	return 0;
}