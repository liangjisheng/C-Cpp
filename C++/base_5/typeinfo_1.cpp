
/***********************************************************
 * @name: typeinfo_1.cpp
 * @brief: typeinfo
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:29:48
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

/*template<typename T>
inline T max(T a,T b)
{
return a<b?b:a;
}
int main(int argc,char *argv[])
{
string s;
::max("apple","peach");
::max("apple","tomato");
//	::max("apple",s);
return 0;
}*/
template<typename T>
void ref(T const& x)
{
	cout << "x in ref(T const&):" << typeid(x).name() << endl;
}

template<typename T>
void nonref(T x)
{
	cout << "x in nonref(T):" << typeid(x).name() << endl;
}

int main(int argc, char *argv[])
{
	ref("hello");
	nonref("hello");
	return 0;
}

//name()是返回类型的可读文本，为一个字符串，清楚的表示传递给typeid的参数（或表达式）的类型，
//有些字符串可能不是可读的文本，但存在一个文本转换器，可以把它转换成可读的文本
