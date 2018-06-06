
// 异常对象在被重新抛出时，有两种不同的选择

#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	stuff() { n = c = 0; }
	stuff(stuff &) { cout << "stuff's copy constructor invoked" << endl; }
};

void passAndThrow()
{
	stuff localStuff;
	throw localStuff;
}

void rethrow1()
{
	try{
		passAndThrow();
	}
	catch(stuff &w)
	{
		cout << &w << endl;
		// 重新抛出的是当前捕获的异常对象，因为没有发生拷贝构造函数的调用
		throw;
	}
}

void rethrow2()
{
	try{
		passAndThrow();
	}
	catch(stuff &w)
	{
		cout << &w << endl;
		// 重新抛出的是当前捕获异常的一个新的拷贝
		// 一般来说，应该用throw来重新抛出当前的异常，因为这样不会改变被传递
		// 出去的异常类型，而且更有效率，因为不用生成一个新拷贝
		throw w;
	}
}


int main()
{
	try{
		rethrow1();
	}
	catch(stuff &w)
	{
		cout << "catched rethrow1" << endl;
		cout << &w << endl;
	}

	cout << endl;
	try{
		rethrow2();
	}
	catch(stuff &w)
	{
		cout << "catched rethrow2" << endl;
		cout << &w << endl;
	}

	system("pause");
	return 0;
}