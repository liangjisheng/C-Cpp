
// 在构造函数中抛出异常，在概念上将被视为该对象没有被构造完成，因此当前对象的
// 析构函数不会被调用，同时由于构造函数本身也是一个函数，在函数体内抛出异常将
// 导致当前函数运行的结束，并释放已经构造的局部对象.构造对象时先要执行其直接
// 基类的构造函数和它的成员对象的构造函数，构造函数中抛出异常将导致销毁当前对
// 象的动作，也就是说，要执行其基类和成员对象的析构函数

#include <iostream>

using namespace std;

class C
{
	int m;
public:
	C() { cout << "in C constructor" << endl; }
	~C() { cout << "in C destructor" << endl; }
};

class A
{
public:
	A() { cout << "in A constructor" << endl; }
	~A() { cout << "in A destructor" << endl; }
};

class B : public A
{
public:
	C c;
	B() { cout << "in B constructor" << endl; throw -1; } 
	~B() { cout << "in B destructor" << endl; }
};


int main()
{
	try{
		B b;
	}
	catch(int){
		cout << "catched" << endl;
	}

	system("pause");
	return 0;
}