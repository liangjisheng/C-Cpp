
// RTTI是Runtime Type Identification的缩写，是运行时类型识别的意思，RTTI
// 特性是C++语言加入较晚的特性之一，这与C++对性能的要求有关，动态类型识别
// 会在一定程度上造成运行效率的降低，所以除非确有必要，否则应尽量减少RTTI的使用

// typeid不是纯的运行是运算符，他也可以用于静态的确定变量或表达式的类型
// typeid可以静态的确定操作数的类型，也可以动态的确定操作数的类型，这取决于
// 操作数本身是否拥有虚函数,当typeid的操作数是一个基本数据类型的变量，或者
// 是一个不带虚函数的对象时，typeid的运算结果是在编译阶段确定的，是一种静态
// 的类型判断

#include <iostream>

using namespace std;

template<typename T>
void func(T a)
{
	if(typeid(T) == typeid(int))
		cout << "Instance with int" << endl;
	else if(typeid(T) == typeid(double))
		cout << "Instance with double" << endl;
}

// typeid更多的时候是在运行是用来动态的确定指针或引用所指向对象的类型
// 这时要求typeid所操作的对象一定要拥有虚函数

class A
{
public:
	virtual void func() {}
};

class B : public A{};

void reportA(A *pa)
{
	if(typeid(*pa) == typeid(A))
		cout << "Type of *pa is:A" << endl;
	else if(typeid(*pa) == typeid(B))
		cout << "Type of *pa is:B" << endl;
}

void reportB(B *pb)
{
	if(typeid(*pb) == typeid(A))
		cout << "Type of *pb is:A" << endl;
	else if(typeid(*pb) == typeid(B))
		cout << "Type of *pb is:B" << endl;
}

void func_1()
{
	// 如果将类A中func的virtual去掉，那么typeid(*pa)的结果永远是typeid(A)
	// typeid(*pb)的结果永远是typeid(B),typeid实际上变成了一种静态运算符
	A a, *pa;
	B b, *pb;
	pa = &a;
	reportA(pa);
	pa = &b;
	reportA(pa);

	pb = static_cast<B*>(&a);
	reportB(pb);
	pb = &b;
	reportB(pb);
}


int main()
{
	//func(1);
	//func(0.5);

	func_1();

	system("pause");
	return 0;
}

// C++中一切的动态机制，包括虚函数，RTTI等，都必须通过指针或者引用来实现
// 换句话说，指针所指的对象或者引用所绑定的对象，在运行阶段可能与声明指针
// 或引用时的类型不一致，如果不使用指针或引用，而是直接通过对象名访问对象
// 那么即使对象拥有动态信息(虚函数表)，对象的动态信息与静态声明对象时的信息
// 必然一致，就没有必要访问虚函数表，而如果对象不拥有虚函数，就没有虚函数
// 表存放动态信息，也就无法在运行时动态判读指针所指对象(或引用所绑定对象)
// 的实际类型
