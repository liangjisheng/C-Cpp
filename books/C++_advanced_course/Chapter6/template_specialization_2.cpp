
#include <iostream>

using std::cout;
using std::endl;

// const T &v1 和 T const &v1在写法上是等价的


template<typename T>
void func(const T &t1, const T &t2) { cout << "template" << endl; }

// template1
template<> void func<char*> (char* const &v1, char* const &v2)
{
	cout << "Specialization: char*" << endl;
}

// template2
template<> void func<const char*>(const char* const &v1, const char* const &v2)
{
	cout << "Specialization: const char*" << endl;
}

// template3，此版本的实例化过程是这样的
// template<typename T> void func(const T &t1, const T &t2) -> T = const char[6]
// template<const char[6]> void func(const const char(&v1)[6], const const char(&v2)[6]) ->等价于
// template<const char[6]> void func(const char(&v1)[6], const char(&v2)[6]) ->等价于
// template<const char[6]> void func(char const(&v1)[6], char const(&v2)[6])
template<> void func<const char[6]> (char const (&v1)[6], char const (&v2)[6])
{
	cout << "Specialization: const char[6]" << endl;
}

// template4,这个版本的参数和template3的版本的函数参数完全相同
template<> void func<char [6]>(char const(&v1)[6], char const (&v2)[6])
{
	cout << "Specialization: char[6]" << endl;
}


int main()
{
	char *p1 = "hello";
	char *p2 = "world";
	func(p1, p2);						// char*

	char * const p3 = "hello";
	char * const p4 = "world";
	func(p3, p4);						// char*

	const char *p5 = "hello";
	const char *p6 = "world";
	func(p5, p6);						// const char*

	const char * const p7 = "hello";
	const char * const p8 = "hello";
	func(p7, p8);						// const char*

	char a1[6] = "hello";
	char a2[6] = "world";
	func(a1, a2);

	const char a3[6] = "hello";
	const char a4[6] = "world";
	func(a3, a4);

	system("pause");
	return 0;
}

