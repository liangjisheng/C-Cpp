
/*
 name: variable_argument3.cpp
 func: 可变参数模板
*/

// 一个可变参数模板(variadic template)就是一个接受可变数目参数的模板函数或模板类
// 可变数目的参数被称为参数包(parameter packet).存在两种参数包：模板参数包
// (表示零个或多个模板参数)和函数参数包(表示零个或多个函数参数)
// 可变参数函数模板通常是递归的。第一步调用处理包中的第一个实参，然后用剩余的实参
// 调用自身.为了终止递归，我们还需要定义一个非可变参数的函数模板

#include <iostream>

using namespace std;

// 用来终止递归并处理包中最后一个元素
template<typename T>
void print(const T& t) { cout << t; }

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template<typename T, typename...Args>
void print(const T& t, const Args&... rest)
{
	cout << t << " ";	// 打印第一个实参
	print(rest...);		// 递归调用，打印其他实参
}


int main()
{
	print("string1", 2, 3.14, "string2", 42);
	cout << endl;

	getchar();
	return 0;
}
