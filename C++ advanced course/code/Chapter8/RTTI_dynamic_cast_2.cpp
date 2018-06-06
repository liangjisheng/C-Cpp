
// 交叉转换(crosscast)是在两个平行的类对象之间进行，本来他们没什么关系，从其中
// 的一种转换为另一种是不可行的，但是，如果类A和类B都是某个派生类C的基类，而指针
// 所指的对象本身就是一个类C的对象，那么该对象既可以被视为类A的对象，也可以被视为
// 类B的对象，类型A*(A&)和B*(B&)之间的转换就成为可能

#include <iostream>

using namespace std;

class A
{
public:
	int num;
	A() { num = 4; }
	virtual void funcA() {}
};

class B
{
public:
	int num;
	B() { num = 5; }
	virtual void funcB() {}
};

class C : public A, public B{};


int main()
{
	C c;
	A *pa;
	B *pb;
	
	pa = &c;
	cout << pa->num << endl;
	pb = dynamic_cast<B*>(pa);
	// 如果将dynamic_cast替换成static_cast，程序将无法编译，这是编译程序会
	// 认为类A和类B是两个无关的类
	// pb = static_cast<B*>(pa);
	// pa和pb相差8个字节，正好是class A的大小，
	cout << "pa = " << pa << endl;
	if(pb)
	{
		cout << "pb = " << pb  << endl;
		cout << "Convertion succeed" << endl;
		cout << pb->num << endl;
	}
	else
		cout << "Convertion failed" << endl;

	system("pause");
	return 0;
}

