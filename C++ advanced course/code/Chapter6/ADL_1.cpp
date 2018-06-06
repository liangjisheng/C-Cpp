
// ADL是Argument Dependent Lookup的缩写，即参数相关查找，也称为Koenig查找，
// (以这种技术的发明人Andrew Koenig的名字命名，因此ADL有时也简称为KL).
// ADL是指编译器对无限定域的函数调用进行名字查找时所应用的一种查找规则。
// ADL的规则就是当编译器对无限定域的函数调用进行名字查找时，处理当前名字
// 空间域以外，也会把函数参数类型所处的名字空间加入查找范围

#include <iostream>
using namespace std;

namespace Koenig
{
	class OneClass
	{
	public:
		ostream& print(ostream &out) const 
		{ out << member << endl; return out; }
		OneClass(int mem = 5) : member(mem) {}
	private:
		int member;
	};

	inline ostream& operator<<(ostream &out, const OneClass &one)
	{ return one.print(out); }
}


int main()
{
	Koenig::OneClass one(10);
	// 编译器在解析main函数(全局域)里面的operator<<调用时，它能够正确定位到
	// Koenig名字空间里面的operator<<,这是因为根据Koenig查找规则，编译器需要
	// 把参数类型OneClass所在的名字空间Koenig也加入对operator<<调用的名字查找
	// 范围中
	cout << one;

	system("pause");
	return 0;
}
