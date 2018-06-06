
// 简单的说，模板的实例化就是由函数模板(类模板)生成模板函数(模板类)的过程。
// 对函数模板而言，实例化后，就会产生一个真正的函数(该函数经过编译之后产生
// 可执行的二进制代码)，而类模板经过实例化后，只是完成了类类型的定义，模板
// 类的成员函数要到调用的时候才会被实例化

// 隐式实例化针对函数模板，发生在直接调用函数模板的时候。还有就是间接调用函数
// 的情形，间接调用指将函数的入口地址传递给一个指针，通过函数指针完成函数调用


#include <iostream>

using std::cout;
using std::endl;

template<typename T>
void func(T t) { cout << t << endl; }

template<typename T>
class A
{
	T num;
public:
	A() { num = T(6.8); }
	void invoke(void(*p)(T)) { p(num); }
};


template<typename T>
T myMax(const T &t1, const T &t2)
{ return t1 > t2 ? t1 : t2; }


int main()
{
	A<int> a1;
	a1.invoke(func);	// func实例化为func<int>

	A<double> a2;
	a2.invoke(func);	// func实例化为func<double>

	int i = 5;
	// i和'a'是两个不同的数据类型，无法从这两个参数中进行类型推演
	// cout << myMax(i, 'a') << endl;		// error
	cout << myMax<int>(i, 'a') << endl;		// ok

	system("pause");
	return 0;
}


// 显示实例化，也称为外部实例化，其含义是在不发生函数调用的时候将函数模板实例化
// 或者不使用模板类的时候将类模板实例化:template void func<int>(const int&);
// 而对于类模板而言，不管是否生成一个模板类对象，都可以直接通过显示实例化声明
// 将类模板实例化:template class theclass<int>;类模板中的所有成员函数模板会同时
// 被实例化(只要在同一个源文件中提供其定义)

