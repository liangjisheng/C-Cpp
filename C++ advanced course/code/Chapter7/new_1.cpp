
// new操作申请空间，返回分配空间的首地址，编译器在处理new操作时，是分两步实现的:
// 第一步是分配空间，第二步是调用相关的构造函数，注意new操作符(new operator)和
// 操作符new(operator new)是两个不同的概念
// new操作符完成两件事，1分配内存，2调用构造函数，C++不允许已任何方式改变它的行为
// 程序员所能改变的是如何为对象分配内存，new操作符为分配内存所调用的函数的名字是
// operator new(操作符new): void* operator new(size_t size);程序员能增加额外的参数
// 重载函数operator new,但第一个参数类型必须是size_t
// 一般不直接调用operator new,但下面这样写是合法的，就想调用其它函数一样
// void* rawMemory = operator new(sizeof(string));

// 有两种形式的operator new()，一种是全局的operator new函数，另一种作为类的成员函数
// 存在，如果一个类没有定义operator new()那么动态分配时调用的是全局的operator new

#include <iostream>
#include <string>

using namespace std;

void* operator new(size_t size)
{
	cout << "global operator new" << endl;
	return malloc(size);
}

class A
{
public:
	void* operator new(size_t size)
	{
		cout << "local operator new" << endl;
		return malloc(size);
	}
};


int main()
{
	string *ps;
	ps = new string("test");		// global new
	delete ps;						// delete的时候也会进入global new

	A *p;
	p = new A;
	delete p;

	system("pause");
	return 0;
}

