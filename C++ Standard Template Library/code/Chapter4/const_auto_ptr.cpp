
// 左值(lvalue)代表locator value，也就是说，这个表达式通过名字和
// 引用值(pointer或reference)来指定一个对象.lvalue并非一定可被更改
// 例如：常数对象的名字就是一个不可被改动的lvalue.所有的非non-lvalues
// 对象，都是rvalue,尤其是显示生成(T())的临时对象和函数返回值都是rvalue

#include<iostream>
#include<memory>

using std::cout;
using std::endl;
using std::auto_ptr;
using std::ostream;

template<class T>
ostream& operator<<(ostream& out, const auto_ptr<T>& p)
{
	// does p own an object?
	if (NULL == p.get())
		out << "NULL";
	else
		out << *p;
	return out;
}

int main()
{
	// const auto_ptr其所有权不能被更改
	const auto_ptr<int> p(new int(42));
	const auto_ptr<int> q(new int(0));
	const auto_ptr<int> r;

	cout << "after initialization: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;

	*q = *p;
	// 对未指向任何对象的auto_ptr进行解引用(dereference)操作
	// C++标准规定，这会导致未定义行为，比如运行时崩溃
	// *r = *p;
	*p = -77;
	cout << "after assigning values: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;

	// q = p;		// error at compile time
	// r = p;		// error at compile time

	system("pause");
	return 0;
}