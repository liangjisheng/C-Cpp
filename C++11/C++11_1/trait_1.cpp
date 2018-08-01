
#include <iostream>
#include <type_traits>
#include <string>

using namespace std;


// 下面两个函数模板的第二个参数为无名参数，仅用于函数重载解析
template<typename T>
void process_helper(const T& t, true_type)
{
	cout << t << " is an integral type." << endl;
}


template<typename T>
void process_helper(const T& t, false_type)
{
	cout << t << " is not an integral type." << endl;
}


template<typename T>
void process(const T& t)
{
	process_helper(t, typename is_integral<T>::type());
}



// is_same(),is_same()类型trait特性判断两个给定的参数是否类型相同
template<typename T1, typename T2>
void same(const T1& t1, const T2& t2)
{
	bool areTypesTheSame = is_same<T1, T2>::value;
	cout << "'" << t1 << "' and '" << t2 << "' are ";
	cout << (areTypesTheSame ? "the same types." : "different types.") << endl;
}


// 替换失败不是错误(Substitution Failure Is Not An Error, SFINAE)，
// 这是C++中一个复杂晦涩的特性，如果有一组重载函数，就可以使用enable_if
// 根据某些类型特性有选择的禁用某些重载。enable_if通常用于重载函数组的
// 返回类型。enable_if接受两个模板类型参数，第一个是bool，第二个是默认为
// void的类型，如果第一个是true，enable_if类就有一个可以使用::type接受的
// 嵌套类型，这个嵌套类型有第二个模板类型参数给定，如果第一个是false，
// 就没有嵌套类型。
// 如果不希望check_type()返回任何内容，可以删除enable_if的第二个模板类型参数
// 或者用void替换了，下面是实现的功能和same()函数模板相同

template<typename T1, typename T2>
typename enable_if < is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2)
{
	cout << "'" << t1 << "' and '" << t2 << "'";
	cout << " are the same types." << endl;
	return true;
}


template<typename T1, typename T2>
typename enable_if <!is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2)
{
	cout << "'" << t1 << "' and '" << t2 << "'";
	cout << " are different types." << endl;
	return false;
}



int main()
{
	if (is_integral<int>::value)
		cout << "int is integeral" << endl;
	else
		cout << "int is not integeral" << endl;

	cout << endl;
	process(123);
	process(2.2);
	process(string("test"));


	cout << endl;
	same(1, 2);
	same(1, 1.1);
	same(3.01, string("test"));


	cout << endl;
	check_type(1, 2);
	check_type(1, 1.1);
	check_type(3.01, string("test"));

	system("pause");
	return 0;
}

