
/*
 name: variable_argument4.cpp
 func: 可变模版参数函数
*/

#include <iostream>
#include <initializer_list>

using namespace std;

template<class ...T>
void f(T... args)
{
	// 打印变参的个数
	cout << sizeof...(args) << endl;
}

// 展开可变模版参数函数的方法一般有两种：一种是通过递归函数来展开参数包，
// 另外一种是通过逗号表达式来展开参数包
//
// 递归终止函数
void print() { cout << "empty" << endl; }

// 展开函数
template<class T, class ...Args>
void print(T head, Args... rest)
{
	cout << "parameter " << head << endl;
	print(rest...);
}

// 可变模板参数函数求和
template<typename T>
T sum(T t) { return t; }

template<typename T, typename ...Types>
T sum(T first, Types... rest) { return first + sum<T>(rest...); }

// 其实还有一种方法可以不通过递归方式来展开参数包，这种方式需要借助
// 逗号表达式和初始化列表。比如前面print的例子可以改成这样
template<typename T>
void printarg(T t) { cout << t << endl; }

template<typename ...Args>
void expand(Args ...args)
{
	int arr[] = { (printarg(args), 0)... };
}

// 我们可以把上面的例子再进一步改进一下，将函数作为参数
// 就可以支持lambda表达式了，从而可以少写一个递归终止函数了
template<typename F, class ...Args>
void expand1(const F& f, Args&&... args)
{
	initializer_list<int>{ (f(forward<Args>(args)), 0)... };
}


int main()
{
	f();
	f(1, 2);
	f(1, 2, "");

	// 展开参数包的函数有两个，一个是递归函数，另外一个是递归终止函数，参数包Args...
	// 在展开的过程中递归调用自己，每调用一次参数包中的参数就会少一个，直到所有的参数
	// 都展开为止，当没有参数时，则调用非模板函数print终止递归过程
	print(1, 2, 3, 4, "test");
	cout << sum(1, 2, 3, 4) << endl;
	cout << endl;

	// expand函数中的逗号表达式：(printarg(args), 0)，也是按照这个执行顺序，
	// 先执行printarg(args)，再得到逗号表达式的结果0。同时还用到了C++11的另外一个特性
	// ——初始化列表，通过初始化列表来初始化一个变长数组, { (printarg(args), 0)... }
	// 将会展开成((printarg(arg1), 0), (printarg(arg2), 0), (printarg(arg3), 0), etc...)
	// 最终会创建一个元素值都为0的数组int arr[sizeof...(Args)]。由于是逗号表达式，
	// 在创建数组的过程中会先执行逗号表达式前面的部分printarg(args)打印出参数，也就是说
	// 在构造int数组的过程中就将参数包展开了，这个数组的目的纯粹是为了在数组构造的过
	// 程展开参数包
	expand(1, 2, 3, 4);
	cout << endl;

	expand1([](int i) { cout << i + 2 << endl; }, 1, 2, 3);

	getchar();
	return 0;
}
