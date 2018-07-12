#include"iostream"
using namespace std;
class Fraction{        //Fraction类表示分数
public:
	//默认参数构造函数
	Fraction(int n=0,int d=1):nume(n),deno(d){simplify();}
	//double类转换为Fraction类
	Fraction(double d);
	//string类转换为Fraction类
	Fraction(const string &str);
	//复制构造函数
	Fraction(const Fraction &f):nume(f.nume),deno(f.deno){}
	//显示分数
	void display();
	//化简
	void simplify();
	//加法函数
	Fraction Add(const Fraction &a,const Fraction &b);
	//加法双目运算符重载
    Fraction operator+(const Fraction &b);
	//减法双目运算符重载
	Fraction operator-(const Fraction &b);
	//乘法双目运算符重载
	Fraction operator*(const Fraction &b);
	//除法双目运算符重载
	Fraction operator/(const Fraction &b);
	//==双目运算符重载
	bool operator==(const Fraction &b);
	//重载!=
	bool operator!=(const Fraction &b);
	//重载>
	bool operator>(const Fraction &b);
	//重载>=
	bool operator>=(const Fraction &b);
	//重载<
	bool operator<(const Fraction &b);
	//重载<=
	bool operator<=(const Fraction &b);
	//重载前置++
	Fraction operator++();
	//重载前置--
	Fraction operator--();
	//重载后置++
	Fraction operator++(int);
	//重载后置--
	Fraction operator--(int);
	//重载-
	Fraction operator-();
	//重载+=
	Fraction operator+=(const Fraction &b);
	//重载-=,其他的符合复制运算符可相应的在Fraction.h头文件中声明，
	//在Fraction.cpp源文件中实现，在此不一一叙述.
	Fraction operator-=(const Fraction &b);
	//重载流插入运算符<<   友元函数实现不了？？？？？
	//friend ostream & operator<<(ostream &os,const Fraction &a); //os<<a
	//重载流提取运算符>>
	//重载类型转换运算符
	operator double();
	operator float();
private:
	int nume,deno;        //分子numerator,分母denominator
};