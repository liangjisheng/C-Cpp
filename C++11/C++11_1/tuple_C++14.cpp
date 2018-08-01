#include <iostream>
#include <tuple>		// for tuple
#include <functional>	// for ref(),cref()
#include <string>

using namespace std;

int main()
{
	// std::make_tuple()用实际值创建tuple,在编译时自动推导类型，
	// 所以不能通过&来指定引用，需要用ref()和cref()指定非常量和
	// 常量引用
	double d = 3.14;
	string str1 = "test";
	auto t2 = make_tuple(16, ref(d), ref(str1), cref(str1));

	cout << "d = " << d << endl;
	get<1>(t2) *= 2;
	cout << "d = " << d << endl;

	cout << "str1 = " << str1 << endl;
	get<2>(t2) = "hello";
	cout << "str1 = " << str1 << endl;

	// std::tie()生成一个引用的tuple，
	tuple<int, string, bool> t1(16, "test", true);
	int i = 0;
	string str = "";
	bool b = false;
	cout << "before: i = " << i << ", str = \"" << str << "\", b = "
		<< b << endl;
	tie(i, str, b) = t1;
	cout << "after: i = " << i << ", str = \"" << str << "\", b = "
		<< b << endl;


	tuple<double, string> t3(3.14, "string");
	auto t4 = tuple_cat(t1, t3);

	tuple<int, string> t5(123, "def");
	tuple<int, string> t6(123, "abc");
	if (t5 < t6)
		cout << "t5 < t6" << endl;
	else
		cout << "t5 >= t6" << endl;

	// 不能用循环，执行类似于get<i>(tuple)这样的调用，应为i的值必须在
	// 编译时确定，一种方法是使用模板元编程

	system("pause");
	return 0;
}