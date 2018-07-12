#include"iostream"
#include"Fraction.h"
#include"cstring"
#include"string"
using namespace std;
int main(int argc,char *argv[])
{
	Fraction a,a1(1,4),b1(1,2),c1,d1,a2;
	Fraction b(2),a3;
	Fraction c(4,6);
	Fraction d(0.25);
	Fraction e("2/3");
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	c1=a1.Add(a1,b1);c1.display();//函数实现两个分数相加
    d1=a1+b1;d1.display();//运算符重载实现两个分数相加
	a2=d1-d;a2.display();
	a2=a1*b1;a2.display();
	//bool check=(a1==b1);
	cout<<boolalpha<<"a1==b1 is "<<(a1==b1)<<endl;
	a3=b1/a1;a3.display();
	c=a1+b1;c.display();
	c=a1-b1;c.display();
	c=a1*b1;c.display();
	c=a1/b1;c.display();
	//分数比较
	cout<<boolalpha<<(a==b)<<","<<(a!=b)<<","<<(a>=b)<<","<<(a<=b)<<endl;
	d=++d;d.display();
	d=--d;d.display();
	d=-c;d.display();
	cout<<"c=";c.display();
	d+=d;d.display();
    //cout<<"d="<<d<<endl;
	Fraction e1,e2;
	//cout<<"input two Fraction:";
	e=0.125; //double类型转换为Fraction类型
	(e+d).display();
	double x=(double)(e+d);//Fraction类型转换为double类型
	cout<<"x="<<x<<endl;
	float y=(float)(d+e);//Fraction类型转换为float类型
	cout<<"y="<<y<<endl;
	return 0;
}