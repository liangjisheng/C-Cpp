
// 链式操作特点是在一条语句中出现两个或者两个以上相同的操作符
// 链式赋值操作符满足右结合律即a = b = c;解释为a = (b = c);
// 而链式输出操作满足左结合律，即cout << a << b 解释为(cout << a) << b;
// 如果要进行类类型的链式操作，操作符的重载函数一定不能返回void类型
// 返回void阻止了链式操作的可能性
// 如果返回类对象，那么链式操作还要借助于复制构造函数，不但开销大，
// 还有编写正确的复制构造函数

#include <iostream>

using namespace std;

class MyComplex
{
	double real;
	double image;
public:
	MyComplex(double r = 0.0, double i = 0.0)
	{
		real = r;
		image = i;
	}
	MyComplex(const MyComplex& src)
	{
		cout << "Copy Constructor" << endl;
		real = src.real;
		image = src.image;
	}
	void Show() const
	{
		cout << real << " + " << image << "i" << endl;
	}

	MyComplex operator = (const MyComplex& src);
};


MyComplex MyComplex::operator=(const MyComplex& src)
{
	real = src.real;
	image = src.image;
	return src;					// 返回是生成临时对象，会调用复制构造函数，造成较大开销
}


// 如果赋值运算符返回对象的引用，就不会调用类的复制构造函数了
class MyComplex_ref
{
	double real;
	double image;
public:
	MyComplex_ref(double r = 0.0, double i = 0.0)
	{
		real = r;
		image = i;
	}
	MyComplex_ref(const MyComplex_ref& src)
	{
		cout << "Copy Constructor" << endl;
		real = src.real;
		image = src.image;
	}
	void Show() const
	{
		cout << real << " + " << image << "i" << endl;
	}

	MyComplex_ref& operator = (const MyComplex_ref& src);
};


MyComplex_ref& MyComplex_ref::operator=(const MyComplex_ref& src)
{
	real = src.real;
	image = src.image;

	// 返回是生成临时对象，会调用复制构造函数，造成较大开销
	//return src;		// 不能这样写，这样会返回对象本身

	// 返回当前对象的引用,表示引用当前对象
	return *this;
}


// 为了对类类型实现链式输入输出操作，一律采用如下的函数原型
// istream& operator>>(istream&, className&);
// ostream& operator<<(ostream&, const className&);


int main()
{
	// 共调了2次复制构造函数，第一次是在c2 = c1的时候，函数的返回值(临时对象)
	// 是由c1构造的，第二次发生在为c3赋值的时候，c2调用复制构造函数构造了临时对象
	MyComplex c1(2.3, 4.5), c2, c3;
	c1.Show();
	c3 = c2 = c1;
	c2.Show();
	c3.Show();

	// 返回引用不调用复制构造函数
	cout << endl;
	MyComplex_ref r1(2.3, 4.5), r2, r3;
	r1.Show();
	r3 = r2 = r1;
	r2.Show();
	r3.Show();

	system("pause");
	return 0;
}
