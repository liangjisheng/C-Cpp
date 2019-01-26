
// 只能将operator<<()声明为someClass类的友元形式，这时的输出操作符是下述三种形式之一
// ostream& operator<<(ostream&, const someClass&);
// ostream& operator<<(ostream&, someClass&);
// ostream& operator<<(ostream&, someClass);
// 第一种最好，也最常用，这种函数重载既安全有高效
// 输入操作符重载也只能以友元函数重载
// istream& operator>>(istream&, someClass&);

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
	friend ostream& operator<<(ostream&, const MyComplex&);
	friend istream& operator>>(istream&, MyComplex&);
};


ostream& operator<<(ostream& os, const MyComplex& src)
{
	os << src.real << "+" << src.image << "i";
	return os;
}

istream& operator>>(istream& in, MyComplex& dest)
{
	// 格式化输入要复杂一些，因为输入的内容事先是未知的，用户在输入数据的
	// 过程中可能会存在违反约定的行为，所以在格式化输入函数中通常要加入
	// 一些容错的处理
	bool success = false;
	char ch = '\0';
	while(!success)
	{
		cout << "Please input a complex:";
		in >> dest.real;
		in >> ch;
		if(ch != '+')
			continue;
		in >> dest.image;
		in >> ch;
		if(ch != 'i')
			continue;
		else
			success = true;
	}

	return in;
}

int main()
{
	MyComplex c;
	cin >> c;
	cout << c << endl;

	system("pause");
	return 0;
}
