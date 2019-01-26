
#include <iostream>

using std::cout;
using std::endl;


// 将友元函数声明为一个使用了模板类的普通函数
template<typename T>
class A
{
	int i ;
	friend void show(const A<T> &a) { cout << a.i << endl; }
public:
	A() { i = 5; }
};


// 将友元函数声明为一个使用了模板类的函数模板
template<typename T>
class A1
{
	int i ;
	template<typename T>
	friend void show1(const A1<T> &a) { cout << a.i << endl; }
public:
	A1() { i = 5; }
};

// 不管是将友元声明为普通函数还是函数模板，由于将友元函数直接定义在类模板体内
// 所以不会出现声明和定义之间的不一致


// 将友元函数声明为一个使用了模板类的函数模板,将模板的定义放在类模板体外
template<typename T>
class A2
{
	int i ;
	template<typename T>
	friend void show2(const A2<T> &a);
public:
	A2() { i = 5; }
};

template<typename T>
void show2(const A2<T> &a) { cout << a.i << endl; }


template<typename T>
class A3
{
	int i ;
	template<typename T1>
	friend void show3(const A3<T1> &a);
public:
	A3() { i = 5; }
};

template<typename T1>
void show3(const A3<T1> &a) { cout << a.i << endl; }


// 声明A4<T>为一个类模板
template<typename T> class A4;
// 提前将show4()声明为一个函数模板
template<typename T> void show4(const A<T>&);

template<typename T>
class A4
{
	T i;
	// 在类模板A4<T>中使用显示模板参数的语法对友元进行声明
	friend void show4<T>(const A4<T> &a);
public:
	A4() { i = T(5); }
};

template<typename T>
void show4(const A4<T> &a) { cout << a.i << endl; }


int main()
{
	// show()函数是模板类A<int>的友元函数
	A<int> a;
	show(a);

	// show1()调用不发生参数推演，产生模板函数show1<int>(),该函数
	// 是模板类A1<int>的友元函数
	A1<int> a1;
	show1(a1);

	// show2()调用时发送参数推演，并产生模板函数show2<int>(),该函数
	// 是模板类A2<int>的友元函数
	A2<int> a2;
	show2(a2);

	// show3()调用时发送参数推演，并产生模板函数show3<int>(),该函数
	// 是模板类A3<int>的友元函数
	A3<int> a3;
	show3(a3);

	// 类模板A4<T>在实例化为A4<int>的过程中，编译器会认为由函数模板show4<T>
	// 生成的模板函数show4<int>是模板类A4<int>的友元函数，从而调show4(a4)
	// 的时候启动函数模板show<T>的实例化
	A4<int> a4;
	show4(a4);

	system("pause");
	return 0;
}

