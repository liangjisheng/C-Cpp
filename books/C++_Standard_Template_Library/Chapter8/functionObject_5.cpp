
// 可以编写自己的仿函数，但如果希望他们能够和函数配接器搭配使用，就必须满足某些条件
// 必须提供一些类型成员(type members)来反映其参数和返回值类型，C++标准程序库提供了
// 一些结构如下:
// template<class Arg, class Result>
//struct unary_function
//{
//	typedef Arg argument_type;
//	typedef Result result_type;
//};

//template<class Arg1, class Arg2, class Result>
//struct binary_function
//{
//	typedef Arg1 first_argument_type;
//	typedef Arg2 second_argument_type;
//	typedef Result result_type;
//};

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// 自定义仿函数
template<class T1, class T2>
struct fopow : public std::binary_function<T1, T2, T1>
{
	T1 operator()(T1 base, T2 exp) const { return std::pow(base, exp); }
};


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	//transform(coll.begin(), coll.end(),
	//	ostream_iterator<int>(cout, " "),
	//	bind2nd(fopow<int, int>(), 3));		// Error: ambiguous

	// print 3 raised to the power of all element
	transform(coll.begin(), coll.end(),		// source
		ostream_iterator<int>(cout, " "),	// destination
		bind1st(fopow<float, int>(), 3));	// operation
	cout << endl;

	// print all elements raised to the power of 3
	transform(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "),
		bind2nd(fopow<float, int>(), 3));
	cout << endl;

	system("pause");
	return 0;
}
