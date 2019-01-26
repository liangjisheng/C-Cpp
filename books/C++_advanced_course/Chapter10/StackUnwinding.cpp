
// 堆栈展开(Stack Unwinding)是指，如果在一个函数内部抛出异常，而此异常并未在该函数
// 内部被捕捉，就将导致该函数的运行在抛出异常出结束，所有已经分配在栈上的局部变量
// 都要被释放，如果被释放的变量中有指针，而该指针此前已经用new申请了空间，就有可能、
// 导致内存泄露，因为堆栈展开的时候并不会自动对该指针变量执行delete(delete[])操作
// 使用智能指针auto_ptr来防止内存泄露

#include <iostream>
#include <memory>		// auto_ptr

using std::cout;
using std::endl;
using std::auto_ptr;

class A
{
	int num;
public:
	A(int i) : num(i) 
	{ cout << "this is A's constructor,num = " << num << endl; }
	~A() { cout << "this is A's destructor, num = " << num  << endl; }
	void show() { cout << num << endl; }
};

void AutoPtr_test1()
{
	A *pa = new A(1);
	throw 1;
	// 由于throw，下面这句话无法执行，导致内存泄露
	delete pa;
}

void AutoPtr_test2()
{
	// 堆栈展开过程中auto_ptr<T>对象会被释放，从而导致auto_ptr<T>对象的析构
	// 函数被调用，不会发生内存泄露
	auto_ptr<A> pa(new A(2));
	pa->show();
	throw 2;
}


int main()
{
	try{
		AutoPtr_test1();
	}
	catch(int){
		cout << "there is no destructor invoked" << endl;
	}

	cout << endl;
	try{
		AutoPtr_test2();
	}
	catch(int){
		cout << "A's destructor does be invoked" << endl;
	}

	system("pause");
	return 0;
}