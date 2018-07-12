
// C++中引入了ostringstream, istringstream, stringstream在头文件
// sstream中，istringstream类是从istream和stringstreambase派生而来
// ostringstream是从ostream和stringstreambase派生而来，
// stringstream是从stream和stringstreambase派生而来

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


void test_1()
{
	istringstream istr;
	istr.str("1 56.7");
	// 上述两句话也可以这么写istringstream istr("1 56.7");

	cout << istr.str() << endl;	// 返回string字符串
	int a = 0;
	float b = 0.0;
	istr >> a;
	cout << a << endl;
	istr >> b;
	cout << b << endl;


	cout << endl;
	// ostreamstring
	ostringstream ostr;
	ostr.put('d');
	ostr.put('e');
	ostr << "fg";

	string str = ostr.str();
	cout << str << endl;
}


// 函数模板，将其他类型转换为字符串
template<class T>
string to_string(const T &t)
{
	ostringstream ostr;
	ostr << t;
	return ostr.str();
}

void test_2()
{
	string str = "";
	int n = 1;
	float f = 1.1;
	double d = 2.2;

	str = to_string(n);
	cout << str << endl;
	str.clear();

	str = to_string(f);
	cout << str << endl;
	str.clear();

	str = to_string(d);
	cout << str << endl;
	str.clear();
}


// 可以定义一个通用的转换模板，用于任意类型之间的转换
template<class out_type, class in_type>
out_type convert(const in_type &t)
{
	stringstream stream;
	stream << t;
	out_type res;
	stream >> res;
	return res;
}

void test_convert()
{
	double d = 1.1;
	string str = "";
	string s = "12.56";
	d = convert<double>(s);
	cout << d << endl;
	str = convert<string>(9000.0);
	cout << str << endl;
}


int main()
{
	// test_1();
	// test_2();
	test_convert();

	system("pause");
	return 0;
}