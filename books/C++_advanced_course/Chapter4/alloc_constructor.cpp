
// 下面三次输出对象b的地址都是一样的，对象a的构造函数在对象b的构造函数之前执行
// 而此时对象b的地址已经确定了。在调用b的构造函数时，和在构造函数调用完成之后，
// b的地址都没有发生变化，因此如下结论：
// 1、为对象分配空间和调用对象的构造函数是两个不同的工作，构造函数不是用来为对象
// 分配空间的，而是对数据成员进行初始化，使得他们首次获得有意义的值，进入对象的
// 构造函数时，对象分配空间的工作已经完成，因此在构造函数中可以自由访问对象的
// 数据成员和调用成员函数
// 2、一般情况下，为对象分配空间和调用构造函数总是紧接着进行的，这是编译器精心
// 组织代码的结果。但也有例外，如在函数体内定义的静态对象，其空间是在程序执行
// 之初就已经分配(与全局变量同在一个存储区)，而该对象的构造函数却是当控制流
// 第一次到达该定义出才执行的

#include <iostream>

using std::cout;
using std::endl;

class B;

class A
{
public:
	A(B &obj) 
	{
		cout << "Before constructor,b's address is:" << &obj << endl; 
	}
};

class B
{
	int num;
public:
	B(){ cout << "In constructor,b's address is:" << this << endl; show(); }
	void show() { cout << "B's member function, num = " << num << endl; }
};


extern B b;
A a(b);
B b;

int main()
{
	cout << "After constructor,b's address is:" << &b << endl;

	system("pause");
	return 0;
}

