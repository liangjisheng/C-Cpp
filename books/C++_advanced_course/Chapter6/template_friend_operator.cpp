
// 由于友元函数常用来做操作符重载，利用函数模板进行操作符重载时，一定要注意
// 友元声明对函数模板实例化的屏蔽问题

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;


template<typename T>
class UseOutputOverload
{
	T var;
public:
	UseOutputOverload(T t) { var = t; }
	template<typename T>		// 如果把这行去掉，意味着operator<<是某个模板类
	// 的友元函数，仅仅是个普通函数，这样做会发送友元函数的声明读操作符重载函数
	// 模板实例化的屏蔽，出现编译错误
	friend ostream& operator<<(ostream&, const UseOutputOverload<T>&);

	//
};

template<typename T>
ostream& operator<<(ostream& out, const UseOutputOverload<T>& obj)
{
	out << obj.var;
	return out;
}


template<typename T>
class UseOutputOverload1
{
	T var;
public:
	UseOutputOverload1(T t) { var = t; }
	// 在函数名operator<<之后加上<T>，表示用类型参数T显示实例化函数模板
	// operator<<,从而实现操作符重载
	friend ostream& operator<< <T>(ostream&, const UseOutputOverload1<T>&);
};

template<typename T>
ostream& operator<<(ostream &out, const UseOutputOverload1<T> &obj)
{
	out << obj.var;
	return out;
}


int main()
{
	UseOutputOverload<int> o(3);
	// 此处不但进行参数推演，而且将函数模板实例化
	cout << o << endl;

	UseOutputOverload<double> s(7.8);
	// 此处不但进行参数推演，而且将函数模板实例化
	cout << s << endl;

	UseOutputOverload1<int> t1(3);
	cout << t1 << endl;

	system("pause");
	return 0;
}

