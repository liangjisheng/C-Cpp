
// dynamic_cast是一个纯动态操作符，因此它只能用于指针或引用间的转换，而且
// dynamic_cast运算符所操作的指针(或引用),指针所指的对象(或引用所绑定的对象)
// 必须拥有虚函数成员，否则会出现编译错误
// dynamic_cast可以进行如下的转换：在指向基类的指针(引用)与指向派生类的指针
// (引用)之间进行转换；在多重继承的情况下，在派生类的多个基类之间进行转换
// (称为交叉转换:crosscast)
// 某些编译器中，认为将派生类的指针转换为指向基类的指针总是安全的，这时根本
// 没有必要使用dynamic_cast，就算用了，它也不会"认真工作",见下面的例子

#include <iostream>

using namespace std;

class A
{
public:
	int i;
	virtual void show() { cout << "class A" << endl; }
	A() { i = 1; }
};

class B : public A
{
public:
	int j;
	// 类B中的show也是虚函数，不加virtual也行，但最好加上
	virtual void show() { cout << "class B" << endl; }
	B() { j = 2; }
};

class C : public B
{
public:
	int k;
	virtual void show() { cout << "class C" << endl; }
	C() { k = 3; }
};

void test_1()
{
	A a;
	B *pb = NULL;
	C *pc = NULL;

	// 静态类型转换将基类指针转换为派生类指针,static_cast不会对指针做类型检查
	pc = static_cast<C*>(&a);

	// dynamic_cast的目的是检查指针所指的对象能否安全的转换为class B类型,但是
	// 由于C++编译器认为从派生类指针转为基类指针总是安全的，所以实际上这里的
	// dynamic_cast并没有发挥动态检查的作用，最后导致输出的结果没有意义，所以
	// dynamic_cast用来作向下转换(由基类指针指向派生类指针)的安全性检查总是有效
	// 的，作向上转换(upcast)时是否有效要看具体的编译器实现，因此做向上转换时
	// 可考虑采用其他方式,而不使用dynamic_cast
	pb = dynamic_cast<B*>(pc);
	if(pb)
	{
		pb->show();
		cout << pb->j << endl;
	}
	else
		cout << "Convertion failed" << endl;
}


void test_2()
{
	// dynamic_cast在向下转换是(downcast)时，会认真检查指针所指的对象的实际
	// 类型，从而决定转换是否成功
	A *pa = NULL;
	B b, *pb;
	C *pc;

	pb = dynamic_cast<B*>(pa);
	if(!pb)
		cout << "Result is NULL" << endl;

	pa = &b;
	pb = dynamic_cast<B*>(pa);
	if(pb)
	{
		pb->show();
		cout << pb->j << endl;
	}
	else
		cout << "Convertion failed" << endl;

	pc = dynamic_cast<C*>(pa);
	if(pc)
	{
		pc->show();
		cout << pc->k << endl;
	}
	else
		cout << "Convertion failed" << endl;
}


class Other
{
	virtual void func(){}
};


void test_3()
{
	// 指针转换失败与否，是由返回值是否为NULL来进行判断，但C++中不存在
	// 空引用，所以引用的装换失败要借助异常来表示
	A a, *pa;
	C c;
	Other o;
	bool bad;

	// try to set reference from Other& to B&
	try{
		bad = false;
		B &rb = dynamic_cast<B&>(o);
	}
	catch(bad_cast e){
		cout << e.what() << endl;
		cout << "Reference failed from Other& to B&" << endl;
		bad = true;
	}
	if(!bad)
	{
		B &rb = dynamic_cast<B&>(o);
		rb.show();
	}

	// try to set reference from A& to B&
	pa = &a;
	try{
		bad = false;
		B &rb = dynamic_cast<B&>(*pa);
	}
	catch(bad_cast e){
		cout << e.what() << endl;
		cout << "Reference failed from A& to B&" << endl;
		bad = true;
	}
	if(!bad)
	{
		B &rb = dynamic_cast<B&>(*pa);
		rb.show();
	}

	// try to set reference from C& to B&
	try{
		bad = false;
		B &rb = dynamic_cast<B&>(c);
	}
	catch(bad_cast e){
		cout << e.what() << endl;
		cout << "Reference failed from C& to B&" << endl;
		bad = true;
	}
	if(!bad)
	{
		B &rb = dynamic_cast<B&>(c);
		rb.show();
	}
}


int main()
{
	// test_1();
	// test_2();
	test_3();

	system("pause");
	return 0;
}