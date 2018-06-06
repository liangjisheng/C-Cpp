
#include <iostream>

using std::cout;
using std::endl;

template<class T> class B;		// 声明B为一个类模板

template<class T> 
class A
{
	T i;
public:
	A() { i = 5; }
	// 类模板B的实例化依赖于类模板A的参数T，对于一个特定的模板类A<t>来说
	// 只有一个B的实例B<t>是它的友元类
	friend class B<T>;			// 如果想这么写的话，必须有之前的声明
};

template<class T>
class B
{
public:
	static void show(const A<T> &a) { cout << a.i << endl; }
};



template<class T> 
class A1
{
	T i;
public:
	A1() { i = 5; }
	// 对于一个特定的类模板A<t>类来说，B的任何实例B<u>都是它的友元类
	template<class T1> friend class B1;
};

template<class T>
class B1
{
public:
	// 显示实例化类模板A1<T>
	static void show(const A1<int> &a) 
	{
		cout << "int" << endl;
		cout << a.i << endl; 
	}
	static void show(const A1<double> &a) 
	{
		cout << "double" << endl;
		cout << a.i << endl; 
	}
};


int main()
{
	A<int> a;
	B<int>::show(a);

	A1<int> a1;
	A1<double> d1;
	B1<int>::show(a1);
	B1<double>::show(a1);
	B1<int>::show(d1);
	B1<double>::show(d1);

	system("pause");
	return 0;
}

