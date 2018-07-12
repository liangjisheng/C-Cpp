#include"Fraction.h"
//double类转换为Fraction类
Fraction::Fraction(double d):nume(d),deno(1)
{
	d=d-nume;
	while(int(d*10)!=0)
		nume=nume*10+int(d*10),deno=deno*10,d=d*10-int(d*10);
	simplify();
}
//string类转换为Fraction类
Fraction::Fraction(const string &str):nume(0),deno(1)
{                 //字符串"2/3"转换为Fraction类
	char buf[200];
	int i=str.find('/'),j=str.length()-i-1;
	if(i>=0){
		str.copy(buf,i,0);buf[i]=0;nume=atoi(buf);//前面子串转换为分子
		str.copy(buf,j,i+1);buf[j]=0;deno=atoi(buf);//后面子串转换为分母
	}
	simplify();
}
//化简
void Fraction::simplify()
{
	int m,n,r,s=1;
	if(nume!=0&&deno!=0){
		if(deno<0)s=-s,deno=-deno;
		if(nume<0)s=-s,nume=-nume;
		m=nume,n=deno;
		while(n!=0)r=m%n,m=n,n=r;
		if(m!=0)
			nume=s*nume/m,deno=deno/m;
	}
	else nume=0,deno=1;
}
//输出显示
void Fraction::display()
{
	if(deno!=0&&deno!=1&&nume!=deno)cout<<nume<<"/"<<deno<<endl;
	//当出现nume/0、nume/1或nume/nume是，只显示nume
	else cout<<"nume="<<nume<<endl;
}
//加法函数实现类相加
Fraction Fraction::Add(const Fraction &a,const Fraction &b)
{
	return Fraction(a.nume*b.deno+a.deno*b.nume,a.deno*b.deno);
}
//加法双目运算符重载
Fraction Fraction::operator+(const Fraction &b)
{
	return Fraction(this->nume*b.deno+this->deno*b.nume,this->deno*b.deno);
}
//减法双目运算符重载
Fraction Fraction::operator-(const Fraction &b)
{
	return Fraction(this->nume*b.deno-this->deno*b.nume,this->deno*b.deno);
}
//乘法双目运算符重载
Fraction Fraction::operator*(const Fraction &b)
{
	return Fraction(this->nume*b.nume,this->deno*b.deno);
}
//除法双目运算符重载
Fraction Fraction::operator/(const Fraction &b)
{
	return Fraction(this->nume*b.deno,this->deno*b.nume);
}
//==双目运算符重载
bool Fraction::operator==(const Fraction &b)
{
	return this->nume*b.deno==this->deno*b.nume;
}
//重载>
bool Fraction::operator >(const Fraction &b)
{
	return this->nume*b.deno>this->deno*b.nume;
}
//重载!=
bool Fraction::operator !=(const Fraction &b)
{
	return this->nume*b.deno!=this->deno*b.nume;
}
//重载>=
bool Fraction::operator >=(const Fraction &b)
{
	return this->nume*b.deno>=this->deno*b.nume;
}
//重载<
bool Fraction::operator <(const Fraction &b)
{
	return this->nume*b.deno<this->deno*b.nume;
}
//重载<=
bool Fraction::operator <=(const Fraction &b)
{
	return this->nume*b.deno<=this->deno*b.nume;
}
//重载前置++
Fraction Fraction::operator ++()
{
	nume=nume+deno;simplify();
	return *this;
}
//重载前置--
Fraction Fraction::operator --()
{
	nume=nume-deno;simplify();
	return *this;
}
//重载后置++
Fraction Fraction::operator ++(int)
{
	Fraction old(*this);
	nume=nume+deno;simplify();
	return old;
}
//重载后置--
Fraction Fraction::operator --(int)
{
	Fraction old(*this);
	nume=nume-deno;simplify();
	return old;
}
//重载-
Fraction Fraction::operator -()
{
	return Fraction(-nume,deno);
}
//重载+=
Fraction Fraction::operator +=(const Fraction &b)
{
	nume=nume*b.deno+deno*b.nume;
	deno=deno*b.deno;
	simplify();
	return *this;
}
//重载-=
Fraction Fraction::operator -=(const Fraction &b)
{
	nume=nume*b.deno-deno*b.nume;
	deno=deno*b.deno;
	simplify();
	return *this;
}
//重载流插入运算符<<
/*ostream & operator<<(ostream & os,const Fraction &a)
{
	if(a.deno!=0&&a.deno!=1&&a.nume!=a.deno)
		os<<a.nume<<"/"<<a.deno;
	else os<<a.nume;
	return os;
}*/
//重载类型转换运算符
Fraction::operator double()
{
	return (double)nume/deno;
}
Fraction::operator float()
{
	return (float)nume/deno;
}