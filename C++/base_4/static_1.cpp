
#include <iostream>  

using namespace std;  

class A  
{
	int num;
public:  
	A() { cout << "A's Constructor Called " << endl;  }  
};  

class B  
{  
	static A a;  
public:  
	B() { cout << "B's Constructor Called " << endl; }  
	// 编译没有错误，链接出错unresolved external symbol "private: static class A B::a"
	// 这是因为在类B中a仅仅是声明，没有在类外部显示定义，这个要使用的话，当然找不到定义
	// 必须在类外显示定义；但是如果类A没有num这个成员(即类A是一个空类的话)，可以成功编译
	// 链接
	static A getA() { return a; }
};

A B::a;

class A1
{
public:  
	A1() { cout << "A1's Constructor Called " << endl;  }  
};  

class B1
{  
	static A1 a1;
public:  
	B1() { cout << "B1's Constructor Called " << endl; }  
};

//A1 B1::a1;		// 首先调用A1的构造函数初始化a1


int main()  
{  
	// 在这里仅仅会调用B的构造函数，因为静态变量a仅仅是声明，并没有在类B的
	// 外部定义a
	B b;
	A a = b.getA();

	// B1 b1;

	system("pause");
	return 0;  
}  