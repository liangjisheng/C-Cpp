
// 临时对象一般出现下列两种情况：接受函数的返回值、用于实现隐式的类型转换
// const A &ra = 5; 由于5是一个文字常量，无法寻址，所以必须先由5转换成一个
// A类的临时对象，再用临时对象初始化引用ra

#include <iostream>

using std::cout;
using std::endl;

class X
{
	static  int order;
	char ch;
	int n;
public:
	X(char c)
	{
		order++;
		n = order;
		ch = c;
		cout << "Constructing object" << n << endl;
	}
	~X() { cout << "Destructing object" << n << endl; }
	X(X& x)
	{
		order++;
		n = order;
		ch = x.ch;
		cout << "Constructing object " << n << " by copying" << endl;
	}
	X& operator=(const X& x)
	{
		cout << "operator=" << n << endl;
		ch = x.ch; 
		return *this; 
	}
};


int X::order;

X makewho()
{
	X B('B');
	return B;
}

// 如果某被调函数返回一个类对象，且在return语句中直接调用类的构造函数，则
// 传入该构造函数的this指针一定来自主调函数，即主调函数中预备接受返回值的
// 那片空间的首地址
X makewho_1() {	return X('B'); }


int main()
{
	X A('A');
	// 在主调函数中生成了一个临时对象，临时对象的空间是主调函数(main)在调用
	// makewho()之前就分配了
	A = makewho();

	cout << endl;
	X A1 = makewho_1();

	system("pause");
	return 0;
}